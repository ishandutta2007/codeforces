#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 2005, MOD = 1e9 + 7;

int dp1[2][2][NMAX];
int dp2[2][2][NMAX];

int solve(string A, int m, int d) {
    if (A == "0") return 0;
    int n = SZ(A);
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);
    dp1[0][1][0] = 1;
    dp1[0][0][0] = 1;
    dp2[0][1][0] = 1;
    dp2[0][0][0] = 1;


    int pw = 1;
    int ans = 0;
    reverse(A.begin(), A.end());
    for (int i = 1, u = 1; i <= n; ++i, u ^= 1) {
        memset(dp1[u], 0, sizeof dp1[u]);
        memset(dp2[u], 0, sizeof dp2[u]);
        int c = A[i - 1] - '0';

        for (int j = 0; j < m; ++j) {
            for (int k = 1; k < 10; ++k) {
                int nj = (j + pw * k) % m;
                int r = k == d;
                dp1[u][r][nj] += dp1[u ^ 1][r ^ 1][j];
                dp1[u][r][nj] %= MOD;

                if (k == c) {
                    dp2[u][r][nj] += dp2[u ^ 1][r ^ 1][j];
                    dp2[u][r][nj] %= MOD;
                } else if (k < c) {
                    dp2[u][r][nj] += dp1[u ^ 1][r ^ 1][j];
                    dp2[u][r][nj] %= MOD;
                }
            }
        }

        if (i < n) {
            ans = (ans + dp1[u][0][0]) % MOD;
        } else {
            ans = (ans + dp2[u][0][0]) % MOD;
        }

        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 1; ++k) {
                int nj = (j + pw * k) % m;
                int r = k == d;
                dp1[u][r][nj] += dp1[u ^ 1][r ^ 1][j];
                dp1[u][r][nj] %= MOD;

                if (k == c) {
                    dp2[u][r][nj] += dp2[u ^ 1][r ^ 1][j];
                    dp2[u][r][nj] %= MOD;
                } else if (k < c) {
                    dp2[u][r][nj] += dp1[u ^ 1][r ^ 1][j];
                    dp2[u][r][nj] %= MOD;
                }
            }
        }

        pw = 10 * pw % m;
    }
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int m, d;
    cin >> m >> d;

    string A, B;
    cin >> A >> B;

    for (int i = SZ(A) - 1, t = 1; i >= 0 && t; --i) {
        A[i] -= t;
        if (A[i] < '0') {
            A[i] += 10;
            t = 1;
        } else {
            t = 0;
        }
    }
    if (A[0] == '0') A = A.substr(1, SZ(A) - 1);

    int ans = (solve(B, m, d) - solve(A, m, d)) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
}