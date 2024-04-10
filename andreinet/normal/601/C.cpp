#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef long double ldouble;
const int NMAX = 105, MMAX = 1005;

ldouble dp[2][NMAX * MMAX];
int A[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> A[i];

    if (m == 1) {
        cout << "1.0000000000000\n";
        return 0;
    }

    dp[0][0] = 1;
    int total = 0;
    for (int i = 1, u = 1; i <= n; ++i, u ^= 1) {
        memset(dp[u], 0, sizeof dp[u]);
        ldouble s1 = 0, s2 = 0;
        int x = A[i];
        total += x;
        for (int j = 1; j <= i * m; ++j) {
            s1 += dp[u ^ 1][j - 1];
            if (j - x >= 0) s1 -= dp[u ^ 1][j - x];
            if (j - x - 1 >= 0) s2 += dp[u ^ 1][j - x - 1];
            if (j - m - 1 >= 0) s2 -= dp[u ^ 1][j - m - 1];
            ldouble fct = i == n ? 1: m - 1;
            dp[u][j] = (s1 + s2) / fct;
        }
    }
    int lim = n * m;

    int u = n & 1;
    ldouble gt = 0;
    for (int i = total; i <= lim; ++i)
        gt += dp[u][i];
    ldouble lt = 0;
    for (int i = 0; i < total; ++i)
        lt += dp[u][i];


    cout << setprecision(18) << fixed;
    cout << 1 + lt << '\n';
}