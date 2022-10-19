#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1 - 1].push_back(v2 - 1);
        a[v2 - 1].push_back(v1 - 1);
    }
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        set<int> b;
        for (auto u : a[p[i].second]) {
            if (used[u] != 0 && used[u] < p[i].first)
                b.insert(used[u]);
            if (used[u] == p[i].first) {
                cout << -1;
                return 0;
            }
        }
        if (b.size() < p[i].first - 1) {
            cout << -1;
            return 0;
        }
        used[p[i].second] = p[i].first;
    }
    for (int i = 0; i < n; ++i)
        cout << p[i].second + 1 << ' ';
    return 0;
}