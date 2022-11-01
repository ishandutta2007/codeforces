#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 321, MOD = 1e9 + 7;

int64_t dp[2][NMAX][NMAX];
int64_t tdp[2][NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    if (n > m) {
        cout << "0\n";
        return 0;
    }

    dp[0][0][0] = tdp[0][0][0] = 1;
    for (int i = 1, u = 1; i <= m; ++i, u ^= 1) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                dp[u][j][k] = dp[u ^ 1][j][k];
                tdp[u][j][k] = tdp[u ^ 1][j][k];
            }
        }
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (j > 0) {
                    dp[u][j][k] += dp[u ^ 1][j - 1][k + 1];
                    tdp[u][j][k] += tdp[u ^ 1][j - 1][k + 1];
                }
                if (k > 0) {
                    if (i != x) {
                        dp[u][j][k] += dp[u ^ 1][j][k - 1];
                    }
                    tdp[u][j][k] += tdp[u ^ 1][j][k - 1];
                }
                if (j > 0) {
                    if (i != x) {
                        dp[u][j][k] += dp[u ^ 1][j - 1][k];
                    }
                    tdp[u][j][k] += tdp[u ^ 1][j - 1][k];
                }

                dp[u][j][k] %= MOD;
                tdp[u][j][k] %= MOD;
            }
        }
    }
    int ans = (tdp[m & 1][n][0] - dp[m & 1][n][0]) % MOD;
    for (int i = 1; i <= n; ++i) {
        ans = (int64_t) ans * i % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}