#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;

int dp_pref[maxn][maxn], dp_suf[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp_pref[i][j] = dp_suf[i][j] = -1;
        }
    }
    dp_pref[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i + 1 && j <= m; ++j) {
            if (dp_pref[i][j] != -1 && dp_pref[i + 1][j] == -1) {
                dp_pref[i + 1][j] = i + 1;
            }
            if (j > 0 && dp_pref[i][j - 1] != -1 && s[i] == t[j - 1] && (dp_pref[i + 1][j] == -1 || dp_pref[i + 1][j] > dp_pref[i][j - 1])) {
                dp_pref[i + 1][j] = dp_pref[i][j - 1];
            }
        }
    }
    dp_suf[n][m] = n;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m; j >= 0; --j) {
            if (dp_suf[i + 1][j] != -1 && dp_suf[i][j] == -1) {
                dp_suf[i][j] = i;
            }
            if (j < m && dp_suf[i + 1][j + 1] != -1 && s[i] == t[j] && (dp_suf[i][j] == -1 || dp_suf[i][j] < dp_suf[i + 1][j + 1])) {
                dp_suf[i][j] = dp_suf[i + 1][j + 1];
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dp_pref[i][j] != -1 && dp_suf[i][j] != -1) {
                int ans_nw = n - dp_suf[i][j];
                if (dp_pref[i][j] != 0) {
                    ans_nw += 1 + dp_pref[i][j] + i - j;
                }
                if (ans == -1 || ans > ans_nw) {
                    ans = ans_nw;
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}