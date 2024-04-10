#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <vector <int>> all(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; --a[i];
            all[a[i]].push_back(i);
        }
        bool ok[n][n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ok[i][j] = false;
            }
        }
        for (int l = 0; l < n; ++l) {
            vector <int> cur(n);
            int cnt = 0, mx = 0;
            for (int r = l; r < n; ++r) {
                ++cur[a[r]];
                ++cnt;
                mx = max(mx, cur[a[r]]);
                if ((r - l + 1) % 2 == 0 && mx * 2 <= cnt) ok[l][r] = true;
            }
        }
        for (int val = 0; val < n; ++val) {
            vector <int> dp(n, -INF);
            for (int i : all[val]) {
                if (i == 0) dp[0] = 1;
                else if (ok[0][i - 1]) dp[i] = 1;
            }
            for (int i = 0; i < n - 1; ++i) {
                if (a[i + 1] == val) dp[i + 1] = max(dp[i] + 1, dp[i + 1]);
                if (a[i] == val) {
                    for (int j : all[val]) {
                        if (j == i + 1) dp[i + 1] = max(dp[i] + 1, dp[i + 1]);
                        else if (j > i && ok[i + 1][j - 1]) dp[j] = max(dp[j], dp[i] + 1);
                    }
                }
            }
            ans = max(ans, dp.back());
            for (int i = 0; i < n - 1; ++i) {
                if (ok[i + 1][n - 1]) ans = max(ans, dp[i]);
            }
        }
        cout << ans << "\n";
    }
}

/*

 */