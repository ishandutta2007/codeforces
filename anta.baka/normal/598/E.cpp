#include <bits/stdc++.h>

using namespace std;

const int N = 31;
const int K = 51;
const int BAD = -1;
const int INF = 1e9;

int dp[N][N][K];

void solve(int n, int m, int k){
    if(dp[n][m][k]!=INF)
        return;
    if(k>n*m)
        dp[n][m][k]=BAD;
    else if(k==n*m)
        dp[n][m][k]=0;
    else if(k==0)
        dp[n][m][k]=0;
    else {
        for(int n1=1; n1<n; n1++)
            for(int k1=0; k1<=k; k1++){
                solve(n1,m,k1);
                solve(n-n1,m,k-k1);
                if(dp[n1][m][k1]!=BAD&&dp[n-n1][m][k-k1]!=BAD)
                    dp[n][m][k]=min(dp[n][m][k],dp[n1][m][k1]+dp[n-n1][m][k-k1]+m*m);
            }
        for(int m1=1; m1<m; m1++)
            for(int k1=0; k1<=k; k1++){
                solve(n,m1,k1);
                solve(n,m-m1,k-k1);
                if(dp[n][m1][k1]!=BAD&&dp[n][m-m1][k-k1]!=BAD)
                    dp[n][m][k]=min(dp[n][m][k],dp[n][m1][k1]+dp[n][m-m1][k-k1]+n*n);
            }
    }
}

int main() {
    for(int z=0; z<N; z++)
        for(int x=0; x<N; x++)
            for(int c=0; c<K; c++)
                dp[z][x][c]=INF;
    int _;
    cin>>_;
    while(_--){
        int n,m,k;
        cin>>n>>m>>k;
        solve(n,m,k);
        cout<<dp[n][m][k]<<"\n";
    }
}