#include <bits/stdc++.h>

using namespace std;

int N;
int dp[2005][2005][2];
int vis[2005][2005];
int MOD = 1e9+7;

int add(int a, int b){
    return (a+b)%MOD;
}

void solve(int n, int o){
    vis[n][o] = -1;
    if(!vis[n+1][o+1]){
        solve(n+1, o+1);
    }
    if(o && !vis[n+1][o-1]){
        solve(n+1, o-1);
    }
    vis[n][o] = 1;
    if(o && vis[n+1][o-1] == 1 && vis[n+1][o+1] == 1){
        dp[n][o][0] = dp[n+1][o+1][1] + dp[n+1][o-1][1];
        dp[n][o][1] = dp[n+1][o+1][0] + 1 + dp[n+1][o-1][1];
        dp[n][o][1] = max(dp[n][o][1], dp[n+1][o-1][0] + 1 + dp[n+1][o+1][1]);
    }
    else if(o && vis[n+1][o-1] == 1){
        dp[n][o][1] = 1 + dp[n+1][o-1][0];
        dp[n][o][0] = dp[n+1][o-1][1];
    }
    else if(vis[n+1][o+1] == 1){
        dp[n][o][1] = 1 + dp[n+1][o+1][0];
        dp[n][o][0] = dp[n+1][o+1][1];
    }
    else{
        vis[n][o] = -1;
    }
    dp[n][o][1] %= MOD, dp[n][o][0] %= MOD;
}

int main(){
    cin >> N;
    vis[2*N][0] = 1;
    for(int i = 1; i<=2*N; i++){
        vis[2*N][i] = -1;
    }
    solve(0, 0);
    cout << dp[0][0][1] << endl;
}