#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int dp[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                if (a[i] == b[j]) dp[i][j] = 2;
            } else if (i == 0) {
                if (a[i] == b[j]) dp[i][j] = 2;
                else dp[i][j] = max(dp[i][j - 1] - 1, 0);
            } else if (j == 0) {
                if (a[i] == b[j]) dp[i][j] = 2;
                else dp[i][j] = max(dp[i - 1][j] - 1, 0);
            } else {
                if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 2;
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j] - 1, dp[i][j - 1] - 1));
                dp[i][j] = max(dp[i][j], 0);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}