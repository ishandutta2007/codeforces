#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
typedef long long int lint;

using namespace std;

const int MOD = (int) 1e9 + 7;

int main() {
#ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    int n = SZ(A), m  = SZ(B);

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // dp[0][0] = 1;
    // for (int i = 0; i <= n; ++i) {
    //     dp[i][0] = 1;
    // }
    // for (int i = 0; i <= m; ++i) {
    //     dp[0][i] = 1;
    // }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1] + 1;
                dp[i][j] %= MOD;
            }
        }
        ans = (ans + dp[i][m]) % MOD;
    }
    cout << ans << '\n';
}