#include <bits/stdc++.h>

using namespace std;
int INF = 1e9;

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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <int> all = a;
        sort(all.begin(), all.end());
        map <int, pair <int, int>> d;
        for (int i = 0; i < n; ++i) {
            if (i & 1) ++d[a[i]].second;
            else ++d[a[i]].first;
        }
        for (int i = 0; i < n; ++i) {
            if (i & 1) --d[all[i]].second;
            else --d[all[i]].first;
        }
        bool res = true;
        for (auto i : d) {
            if (i.second.first != 0 || i.second.second != 0) res = false;
        }
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
}