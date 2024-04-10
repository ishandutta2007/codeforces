#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e6 + 5;

bool used[maxn];
int cnt[maxn], dp[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        used[i] = false;
        cnt[i] = 0;
        dp[i] = m * 2;
    }
    int mn_all = m;
    while (n--) {
        int a;
        cin >> a;
        used[a] = 1;
        mn_all = min(mn_all, a);
    }
    cnt[1] = 1;
    int ans = m, mx = m;
    for (int mn = m; mn >= 1; --mn) {
        if (mn != 1) {
            for (int i = mn; i <= m; i += mn) {
                if (i == mn) {
                    if (used[i] && dp[i] != m * 2) {
                        cnt[dp[i]]--;
                    }
                    dp[i] = min(dp[i], i);
                    if (used[i]) {
                        cnt[dp[i]]++;
                    }
                } else {
                    if (used[i] && dp[i] != m * 2) {
                        cnt[dp[i]]--;
                    }
                    dp[i] = min(dp[i], max(mn, dp[i / mn]));
                    if (used[i]) {
                        cnt[dp[i]]++;
                    }
                }
            }
        }
        if (mn <= mn_all) {
            while (cnt[mx] == 0) {
                mx--;
            }
            ans = min(ans, mx - mn);
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