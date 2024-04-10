#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int DMAX = 2005, MOD = 1e9 + 7;

int dp[DMAX][DMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    string S;
    cin >> n >> m >> S;

    dp[0][0] = 1;
    for (int i = 1; i <= n - m; ++i) {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j <= n - m; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    int mins = 0, s = 0;
    for (char c: S) {
        s += c == '(' ? 1: -1;
        mins = min(mins, s);
    }

    int ans = 0;
    for (int i = 0; i <= n - m; ++i) {
        for (int j = -mins; j <= n - m; ++j) {
            if (j + s > n - m) continue;
            int add = (int64_t) dp[i][j] * dp[n - m - i][j + s] % MOD;
            ans = (ans + add) % MOD;
        }
    }

    cout << ans << '\n';
}