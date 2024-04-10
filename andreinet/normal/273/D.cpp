#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
#define WRITE(x) (cerr << #x << ": " << x << endl)
using namespace std;

typedef long long i64;
const int NMAX = 155, MOD = 1e9 + 7;

int64_t dp[2][4][NMAX][NMAX];
int64_t sdp[2][4][NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int64_t ans = 0;
    for (int i = 1, u = 1; i <= n; ++i, u ^= 1) {
        memset(dp[u], 0, sizeof dp[u]);
        memset(sdp[u], 0, sizeof sdp[u]);

        for (int p = 0; p < 4; ++p) {
            for (int j = 1; j <= m; ++j) {
                for (int k = j; k <= m; ++k) {
                    dp[u][p][j][k] = (sdp[u ^ 1][p][j][k] + (p == 0)) % MOD;
                    ans = (ans + dp[u][p][j][k]) % MOD;
                }
            }
        }

        // SDP 0
        for (int j = m; j > 0; --j) {
            for (int k = j; k <= m; ++k) {
                sdp[u][0][j][k] = sdp[u][0][j + 1][k] + sdp[u][0][j][k - 1] -
                                  sdp[u][0][j + 1][k - 1] + dp[u][0][j][k];
                sdp[u][0][j][k] %= MOD;
            }
        }

        // SDP 1
        for (int j = 1; j <= m; ++j) {
            for (int k = j; k <= m; ++k) {
                sdp[u][1][j][k] = sdp[u][1][j - 1][k] + sdp[u][1][j][k - 1] -
                                  sdp[u][1][j - 1][k - 1] + dp[u][1][j][k] +
                                  dp[u][0][j - 1][k];
                sdp[u][1][j][k] %= MOD;
            }
        }
        
        // SDP 2
        for (int j = m; j > 0; --j) {
            for (int k = m; k >= j; --k) {
                sdp[u][2][j][k] = sdp[u][2][j + 1][k] + sdp[u][2][j][k + 1] -
                                  sdp[u][2][j + 1][k + 1] + dp[u][2][j][k] +
                                  dp[u][0][j][k + 1];
                sdp[u][2][j][k] %= MOD;
            }
        }

        // SDP 3
        for (int j = 1; j <= m; ++j) {
            for (int k = m; k >= j; --k) {
                sdp[u][3][j][k] = sdp[u][3][j - 1][k] + sdp[u][3][j][k + 1] -
                                  sdp[u][3][j - 1][k + 1] + dp[u][3][j][k] +
                                  dp[u][0][j - 1][k + 1] +
                                  dp[u][1][j][k + 1] +
                                  dp[u][2][j - 1][k];
                sdp[u][3][j][k] %= MOD;
            }
        }
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
}