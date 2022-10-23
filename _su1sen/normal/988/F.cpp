#include<bits/stdc++.h>

using namespace std;

constexpr long long INF = 1LL << 50;

int main() {
    int a, n, m;
    cin >> a >> n >> m;
    vector<bool> rain(a);
    vector<long long> ub(a, INF);
    int left_most_rain = a;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        for (int x = l + 1; x <= r; ++x) {
            rain[x] = true;
        }
        left_most_rain = min(left_most_rain, l);
    }
    int left_most_ub = a;
    for (int i = 0; i < m; ++i) {
        int x, p;
        cin >> x >> p;
        if (p < ub[x]) ub[x] = p;
        left_most_ub = min(left_most_ub, x);
    }
    if (left_most_rain < left_most_ub) {
        cout << -1 << '\n';
        return 0;
    }
    vector<vector<long long>> dp(a + 1, vector<long long>(a + 2, INF));
    dp[0][a + 1] = 0;
    if (ub[0] >= 0) dp[0][0] = 0;
    for (int i = 1; i <= a; ++i) {
        long long p = ub[i];
        for (int j = 0; j < i; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + ub[j]);
            dp[i][i] = min(dp[i][i], dp[i - 1][j] + ub[j]);
            if (not rain[i]) {
                dp[i][i] = min(dp[i][i], dp[i - 1][j]);
                dp[i][a + 1] = min(dp[i][a + 1], dp[i - 1][j]);
            }
        }
        if (not rain[i]) {
            dp[i][i] = min(dp[i][i], dp[i - 1][a + 1]);
            dp[i][a + 1] = min(dp[i][i], dp[i - 1][a + 1]);
        }
    }
    long long ans = INF;
    for (int j = 0; j <= a + 1; ++j) ans = min(ans, dp[a][j]);
    cout << ans << '\n';
    return 0;
}