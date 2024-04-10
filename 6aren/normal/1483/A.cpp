#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(m);
        vector<int> cnt(n);
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int sz;
            cin >> sz;
            g[i].resize(sz);
            for (int &e : g[i]) {
                cin >> e;
                e--;
            }
            if (sz == 1) cnt[g[i][0]]++, ans[i] = g[i][0];
        }
        for (int i = 0; i < m; i++) {
            if (g[i].size() == 1) continue;
            if (cnt[g[i][0]] > cnt[g[i][1]]) swap(g[i][0], g[i][1]);
            ans[i] = g[i][0];
            cnt[g[i][0]]++;
        }
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > (m + 1) / 2) ok = 0;
        }
        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < m; i++) cout << ans[i] + 1 << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}