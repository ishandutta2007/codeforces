#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const long long INF = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) {
            cin >> c;
        }
        vector<vector<pair<int, long long>>> dp(n + 1, vector<pair<int, long long>>(2, {0, -INF}));
        dp[0][0] = dp[0][1] = {0, 0};
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] > 0) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = max(dp[i - 1][1], {dp[i - 1][0].fi + 1, dp[i - 1][0].se + a[i - 1]});
            } else {
                dp[i][1] = dp[i - 1][1];
                dp[i][0] = max(dp[i - 1][0], {dp[i - 1][1].fi + 1, dp[i - 1][1].se + a[i - 1]});
            }
        }
        cout << max(dp[n][0], dp[n][1]).se << "\n";
    }
    return 0;
}