#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = {a[i], i};
    }
    sort(p.begin(), p.end());
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        g[p[i].second].push_back(p[i + 1].second);
        p[i].first = b[p[i].second];
    }
    p[n - 1].first = b[p[n - 1].second];
    sort(p.begin(), p.end());
    for (int i = 0; i + 1 < n; ++i) {
        g[p[i].second].push_back(p[i + 1].second);
    }
    queue<int> q;
    string ans(n, '0');
    ans[p[n - 1].second] = '1';
    q.push(p[n - 1].second);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (ans[u] != '1') {
                ans[u] = '1';
                q.push(u);
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