#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, pair<int, int>>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    }
    int ans = 0;
    for (int st = 0; st < 2; ++st) {
        int ans_nw = 0, nw = x;
        vector<int> used(n);
        for (int i = 0; i < n; ++i) {
            int pos_mx = -1;
            for (int j = 0; j < n; ++j) {
                if (used[j] == 0 && a[j].first == (ans_nw + st) % 2 && a[j].second.first <= nw && (pos_mx == -1 || a[pos_mx].second.second < a[j].second.second)) {
                    pos_mx = j;
                }
            }
            if (pos_mx != -1) {
                ans_nw++;
                used[pos_mx] = 1;
                nw += a[pos_mx].second.second;
            }
        }
        ans = max(ans, ans_nw);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(25);
    cout << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}