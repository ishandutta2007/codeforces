#include <bits/stdc++.h>

using namespace std;

template<typename Fun>
struct y_combinator {
    const Fun fun;
 
    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}
 
    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n, e;
    long long k;
    cin >> n >> e >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    int l = 0, r = 1000 * 1000 * 1000 + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        vector<int> used(n);
        bool cycle = false;
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0 && a[i] <= m) {
                y_combinator([&](auto dfs, int v) -> void {
                    used[v] = 1;
                    for (auto u : g[v]) {
                        if (cycle) {
                            return;
                        }
                        if (a[u] <= m) {
                            if (used[u] == 1) {
                                cycle = true;
                                return;
                            } else if (used[u] == 0) {
                                dfs(u);
                            }
                        }
                    }
                    used[v] = 2;
                })(i);
            }
        }
        if (cycle) {
            r = m;
            continue;
        }
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            for (auto j : g[i]) {
                if (a[i] <= m && a[j] <= m) {
                    cnt[j]++;
                }
            }
        }
        used.assign(n, 0);
        vector<int> len(n, 1);
        for (int i = 0; i < n; ++i) {
            if (a[i] <= m && used[i] == 0) {
                y_combinator([&](auto dfs, int v) -> void {
                    used[v] = 1;
                    for (auto u : g[v]) {
                        if (a[u] <= m) {
                            if (!used[u]) {
                                dfs(u);
                            }
                            len[v] = max(len[v], len[u] + 1);
                        }
                    }
                })(i);
            }
        }
        bool ch = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= m && len[i] >= k) {
                ch = true;
                break;
            }
        }
        if (ch) {
            r = m;
        } else {
            l = m;
        }
    }
    if (r == 1000 * 1000 * 1000 + 1) {
        cout << -1 << '\n';
    } else {
        cout << r << '\n';
    }
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