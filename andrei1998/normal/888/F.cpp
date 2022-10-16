#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 500 + 5;
const int MOD = 1000000000 + 7;
 
bool adj[NMAX][NMAX];
int dp[NMAX + 1][NMAX + 1][2];
 
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> adj[i][j];
        }
    }
    for (int i = N; i >= 1; --i) {
        dp[i][i + 1][0] = dp[i][i + 1][1] = 1;
        for (int j = i + 2; j <= N + 1; ++j) {
             for (int k = i + 1; k <= j - 1; ++k) {
                if (adj[(j - 1) % N + 1][(k - 1) % N + 1]) {
                    dp[i][j][1] = (dp[i][j][1] + (1LL * dp[i][k][1] * dp[k][j][0])) % MOD;     
                }
            }
            dp[i][j][0] = dp[i][j][1]; 
            for (int k = i + 1; k <= j - 1; ++k) {
                if (adj[(i - 1) % N + 1][(k - 1) % N + 1]) {
                    dp[i][j][0] = (dp[i][j][0] + (1LL * dp[i][k][0] * dp[k][j][0])) % MOD; 
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (adj[1][i]) {
            ans = (ans + 1LL * dp[1][i][1] * dp[i][N + 1][0]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}