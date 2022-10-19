#include <bits/stdc++.h>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <int> a(n * m);
        for (int i = 0; i < n * m; ++i) {
            cin >> a[i];
        }
        vector <pair <int, int>> all;
        for (int i = 0; i < n * m; ++i) {
            all.emplace_back(a[i], i);
        }
        sort(all.begin(), all.end());
        int cur = 0;
        vector <int> ans_pl(n * m);
        for (int i = 0; i < n * m; ++i) {
            if (i != 0 && all[i].first == all[i - 1].first) continue;
            int l = cur, r = cur;
            for (int j = i + 1; j < n * m; ++j) {
                if (all[j].first == all[i].first) ++r;
                else break;
            }
            int len = r - l + 1;
            cur += len;
            if (len < m && r % m >= l % m) {
                for (int j = r; j >= l; --j) ans_pl[all[j].second] = l + r - j;
                continue;
            }
            int len_suf = m - l % m;
            int u = l;
            for (int j = 0; j < len_suf; ++j) {
                ans_pl[all[u].second] = l + len_suf - 1 - j;
                ++u;
            }
            int len_pref = r % m + 1;
            if (len_pref == m && len == m) continue;
            int u1 = r;
            for (int j = 0; j < len_pref; ++j) {
                ans_pl[all[u1].second] = r - len_pref + 1 + j;
                u1--;
            }
            int flex = 0;
            while (u <= u1) {
                ans_pl[all[u1].second] = u + flex;
                u1--;
                ++flex;
            }
        }
        vector <vector <int>> now(n, vector <int> (m));
        long long ans = 0;
        for (int i = 0; i < n * m; ++i) {
            for (int j = 0; j < ans_pl[i] % m; ++j) {
                ans += now[ans_pl[i] / m][j];
            }
            now[ans_pl[i] / m][ans_pl[i] % m] = 1;
        }
        cout << ans << "\n";
    }
}