#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>

using namespace std;
const int INF = 1e9;
const int MAXN = 5001;
int dp_pref[MAXN][MAXN];
int dp_suf[MAXN][MAXN];

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp_pref[i][j] = dp_suf[i][j] = INF;
        }
    }
    dp_pref[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp_pref[i + 1][j] = min(dp_pref[i + 1][j], dp_pref[i][j] + 2);
        }
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                dp_pref[i + 1][j + 1] = min(dp_pref[i + 1][j + 1], dp_pref[i][j] + 1);
            }
        }
    }
    dp_suf[n][m] = 0;
    for (int i = n; i > 0; --i) {
        for (int j = 0; j <= m; ++j) {
            dp_suf[i - 1][j] = min(dp_suf[i - 1][j], dp_suf[i][j] + 1);
        }
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp_suf[i - 1][j - 1] = min(dp_suf[i - 1][j - 1], dp_suf[i][j] + 1);
            }
        }
    }
    int ans = dp_suf[0][0];
    vector <int> dp(m), dp1(m);
    for (int i = 1; i <= m; ++i) {
        if (s.substr(0, i) == t.substr(0, i)) ans = min(ans, dp_suf[i][i]);
    }
    for (int i = 0; i < m; ++i) {
        if (s[0] == t[i]) dp[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int l = dp[j - 1];
            ans = min(ans, dp_suf[i][j] + 1 + dp_pref[i - l][j - l]);
        }
        if (i == n) break;
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                if (j) dp1[j] = dp[j - 1] + 1;
                else dp1[j] = 1;
            }
        }
        dp.swap(dp1);
        for (int j = 0; j < m; ++j) dp1[j] = 0;
    }
    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

 */