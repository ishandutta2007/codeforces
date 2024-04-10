#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long v[n][3], pre_col[n][4] = {}, pre_row[n + 1][3] = {};
    for (int j = 0; j < 3; ++j) for (int i = 0; i < n; ++i) {
        cin >> v[i][j];
        pre_col[i][j + 1] = pre_col[i][j] + v[i][j];
        pre_row[i + 1][j] = pre_row[i][j] + v[i][j];
    }
    long long dp[n][3], a1 = 0, a2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i) {
                dp[i][j] = -1ll << 60;
                for (int k = 0; k < 3; ++k) {
                    dp[i][j] = max(dp[i - 1][k] + pre_col[i][max(k, j) + 1] - pre_col[i][min(k, j)], dp[i][j]);
                }
            } else {
                dp[i][j] = pre_col[i][j + 1];
            }
        }
        if (i == 1) dp[i][2] = max(dp[i][2], pre_col[i][3] + pre_col[i - 1][3]);
        if (i) {
            dp[i][0] = max(dp[i][0], a2 + pre_col[i][3]);
            dp[i][2] = max(dp[i][2], a1 + pre_col[i][3]);
            a1 = max(a1 + pre_col[i][3], dp[i][0]);
            a2 = max(a2 + pre_col[i][3], dp[i][2]);
        } else {
            a1 = dp[i][0];
            a2 = dp[i][2];
        }
    }
    cout << dp[n - 1][2];
}