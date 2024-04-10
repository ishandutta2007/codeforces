#include <bits/stdc++.h>

using namespace std;

#define int long long
int dp[35][35][55];
int inf = 1e16;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 30; ++i) for (int j = 1; j <= 30; ++j) for (int z = 1; z <= 50; ++z) dp[i][j][z] = inf;
    for (int i = 1; i <= 30; ++i){
        for (int j = 1; j <= 30; ++j){
            if (i * j <= 50) dp[i][j][i * j] = 0;
        }
    }
    for (int i = 1; i <= 30; ++i){
        for (int j = 1; j <= 30; ++j){
            for (int k = 0; k <= 50; ++k){
                for (int t = 1; t < i; ++t){
                    for (int k1 = 0; k1 <= k; ++k1){
                        dp[i][j][k] = min(dp[i][j][k], dp[t][j][k1] + dp[i - t][j][k - k1] + j * j);
                    }
                }
                for (int t = 1; t < j; ++t){
                    for (int k1 = 0; k1 <= k; ++k1){
                        dp[i][j][k] = min(dp[i][j][k], dp[i][t][k1] + dp[i][j - t][k - k1] + i * i);
                    }
                }
            }
        }
    }
    int t, n, m, k;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n >> m >> k;
        cout << dp[n][m][k] << '\n';
    }
    return 0;
}