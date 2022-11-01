#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 4005, MOD = 1e9 + 9;

int dp[NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, w, b;
    cin >> n >> w >> b;

    int r = max(w, b);

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= r; ++j) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 2; i < n; ++i) {
        int add = (int64_t) dp[i][w] * dp[n - i][b] % MOD * (i - 1) % MOD;
        ans = (ans + add) % MOD;
    }

    for (int i = 1; i <= w; ++i) {
        ans = (int64_t) ans * i % MOD;
    }

    for (int i = 1; i <= b; ++i) {
        ans = (int64_t) ans * i % MOD;
    }

    cout << ans << '\n';
}