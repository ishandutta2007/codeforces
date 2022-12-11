#include <bits/stdc++.h>

using namespace std;

long long dp[35][35][55];
int T;

long long solve(int n, int m, int k){
    if(!k){
        return 0;
    }
    if(n*m < k){
        return INT_MAX;
    }
    if(n*m == k){
        return 0;
    }
    if(dp[n][m][k] != -1){
        return dp[n][m][k];
    }
    dp[n][m][k] = INT_MAX;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=k; j++){
            dp[n][m][k] = min(dp[n][m][k], solve(i, m, j) + solve(n-i, m, k-j) + m*m);
        }
    }
    for(int i = 1; i<m; i++){
        for(int j = 0; j<=k; j++){
            dp[n][m][k] = min(dp[n][m][k], solve(n, i, j) + solve(n, m-i, k-j) + n*n);
        }
    }
    return dp[n][m][k];
}

int main(){
    cin >> T;
    for(int i = 1; i<=30; i++){
        for(int j = 1; j<=30; j++){
            for(int k = 1; k<=50; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << "\n";
    }
}