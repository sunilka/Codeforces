#include<bits/stdc++.h>
using namespace std;


// printing the code here
int s = 100;
int a[100][100];
int vis[100][100];
int n,flag;

//if flag == 1 --> NO
//if flag == 0 --> YES

void init(int n)
{
    flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j] = 0;
        }
    }
}

bool isvalid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }
    return true;
}

void dfs(int i,int j)
{
    stack<pair<int,int> > s;
    s.push({i,j});

    while(!s.empty()){
        int flaggy = 0;
        int ii = s.top().first;
        int jj = s.top().second;

        if(isvalid(ii,jj+1) && a[ii][jj+1] == 1 && vis[ii][jj+1] == 0){
            flaggy = 1;
            s.push({ii,jj+1});
            vis[ii][jj+1] = 1;
        }

        else if(isvalid(ii,jj+1) && a[ii][jj+1] == 1 && vis[ii][jj+1] == 1){
            flaggy = 1;
            vis[ii][jj+1] = 1;
            return;
        }

        else if(isvalid(ii+1,jj) && a[ii+1][jj] == 1 && vis[ii+1][jj] == 0){
            flaggy = 1;
            s.push({ii+1,jj});
            vis[ii+1][jj] = 1;
        }

        else if(isvalid(ii+1,jj) && a[ii+1][jj] == 1 && vis[ii+1][jj] == 1){
            flaggy = 1;
            vis[ii+1][jj] = 1;
            return;
        }
        // if we reach the end of a certain one
        // we need to check the following
        // if end pos is row end
        // if end pos is col end
        // only then it is true
        // else it is false
        if(flaggy == 0){
            if(ii == n-1 || jj == n-1 ){
                return;
            }
            else{
                flag = 1;
                return;
            }
        }
    }

}

void putintoarray(int row,string s)
{
    for(int i=0;i<s.length();i++){
        a[row][i] = abs(48 - (int)(s[i]));
    }
}

void print()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int nooftestcases;
    cin>>nooftestcases;

    while(nooftestcases--){
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }

        for(int i=0;i<n;i++){
            putintoarray(i,s[i]);
        }
        init(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j] == 1 && vis[i][j] == 0){
                    dfs(i,j);
                }

                if( flag!=0 ){
                    break;
                }
            }
            if( flag !=0 ){
                    break;
            }
        }

        if(flag == 1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
}
