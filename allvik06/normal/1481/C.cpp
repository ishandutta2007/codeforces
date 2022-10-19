#include <bits/stdc++.h>

using namespace std;
#define ll long long

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
        vector <int> a(n), b(n), c(m);
        vector <int> need_kol(n + 1);
        vector <bool> in_b(n + 1);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            in_b[b[i]] = true;
        }
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ++need_kol[b[i]];
            }
        }
        for (int i = 0; i < m; ++i) {
            --need_kol[c[i]];
        }
        set <pair <int, int>> all;
        for (int i = 1; i <= n; ++i) {
            if (in_b[i]) {
                all.insert(make_pair(need_kol[i], i));
            }
        }
        vector <int> result;
        bool ok = true;
        vector <vector <int>> flex(n + 1);
        vector <int> kek_timur(n + 1);
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                flex[b[i]].push_back(i);
            }
            kek_timur[b[i]] = i;
        }
        set <int> lol_kek;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                lol_kek.insert(i);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (in_b[c[i]]) {
                if (flex[c[i]].empty()) {
                    result.push_back(kek_timur[c[i]]);
                    all.erase(make_pair(need_kol[c[i]], c[i]));
                    need_kol[c[i]]++;
                    all.insert(make_pair(need_kol[c[i]], c[i]));
                } else {
                    result.push_back(flex[c[i]].back());
                    all.erase(make_pair(need_kol[c[i]], c[i]));
                    lol_kek.erase(flex[c[i]].back());
                    all.insert(make_pair(need_kol[c[i]], c[i]));
                    flex[c[i]].pop_back();
                }
            } else {
                if (!lol_kek.empty()) {
                    result.push_back(*lol_kek.begin());
                    continue;
                }
                auto lul = *all.begin();
                if (lul.first >= 0) {
                    break;
                }
                result.push_back(kek_timur[lul.second]);
                all.erase(lul);
                need_kol[lul.second]++;
                ++lul.first;
                flex[lul.second].push_back(kek_timur[lul.second]);
                lol_kek.insert(kek_timur[lul.second]);
                all.insert(lul);
            }
        }
        if (result.size() != m) cout << "NO\n";
        else {
            for (int i = 0; i < m; ++i) {
                a[result[i]] = c[i];
            }
            if (a == b) {
                cout << "YES\n";
                for (int i : result) cout << i + 1 << " ";
                cout << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}