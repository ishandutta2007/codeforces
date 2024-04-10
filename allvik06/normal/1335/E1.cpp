#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        vector <vector <int>> pref(26, vector <int> (n + 1)), suf(26, vector <int> (n + 1)), pr(26, vector <int> (n + 1, -1)), su(26, vector <int> (n + 1, -1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (a[i - 1] == j) pref[j][i] = pref[j][i - 1] + 1, pr[j][pref[j][i]] = i;
                else pref[j][i] = pref[j][i - 1];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if (a[i] == j) suf[j][i] = suf[j][i + 1] + 1, su[j][suf[j][i]] = i + 1;
                else suf[j][i] = suf[j][i + 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = max(ans, pref[i][n]);
        }
        for (int len = 1; len <= n; ++len) {
            for (int j = 0; j < 26; ++j) {
                int l = pr[j][len], r = su[j][len];
                if (pref[j][n] < len * 2) {
                    continue;
                }
                int maxx = 0;
                for (int k = 0; k < 26; ++k) {
                    maxx = max(maxx, pref[k][r - 1] - pref[k][l]);
                }
                if (2 * len + maxx == 5) {
                    int flex = 0;
                }
                ans = max(ans, 2 * len + maxx);
            }
        }
        cout << ans << "\n";
    }
}