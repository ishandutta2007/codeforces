#include <bits/stdc++.h>

using namespace std;

int pre[4005][4005];
int cst[4005][4005];
int N, K;
int dp[805][4005];

int read(){
    int rtn = 0, p = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') p = -1; c = getchar();}
    while(c >= '0' && c <= '9') rtn = 10 * rtn + c - '0', c = getchar();
    return rtn * p;
}

void solve(int d, int l, int r, int x, int y){
    if(r < l){
        return;
    }
    int idx = (l+r)/2;
    int p = x;
    dp[d][idx] = dp[d-1][x-1] + cst[x][idx];
    for(int i = x+1; i<=min(y, idx); i++){
        if(dp[d][idx] > dp[d-1][i-1] + cst[i][idx]){
            dp[d][idx] = dp[d-1][i-1] + cst[i][idx];
            p = i;
        }
    }
    solve(d, l, idx-1, x, p);
    solve(d, idx+1, r, p, y);
}

int main(){
    N = read();
    K = read();
    for(int i =1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            pre[i][j] = read();
            pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    for(int i= 1; i<=N; i++){
        for(int j = 1; j<i; j++){
            cst[j][i] = (pre[i][i] - pre[i][j-1] - pre[j-1][i] + pre[j-1][j-1])/2;
        }
    }
    fill(dp[0]+1, dp[0]+N+1, 1000000000);
    for(int i = 1; i<=K; i++){
        solve(i, 1, N, 1, N);
    }
    cout << dp[K][N] << endl;
}