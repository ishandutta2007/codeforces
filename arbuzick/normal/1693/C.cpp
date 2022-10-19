#include <bits/stdc++.h>
#define int long long

using namespace std;

template <typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template <typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), _g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        _g[v].push_back(u);
    }
    vector<int> dist(n, n + m);
    vector<int> count(n);
    for (int i = 0; i < n; ++i) {
        count[i] = g[i].size();
    }
    dist[n - 1] = 0;
    set<pair<int, int>> s;
    s.insert({0, n - 1});
    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for (auto u : _g[v]) {
            count[u]--;
        }
        for (auto u : _g[v]) {
            if (dist[u] > dist[v] + count[u] + 1) {
                s.erase({dist[u], u});
                dist[u] = dist[v] + count[u] + 1;
                s.insert({dist[u], u});
            }
        }
    }
    cout << dist[0] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}