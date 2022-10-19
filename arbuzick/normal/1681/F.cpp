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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--, x--;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }
    long long ans = 0;
    vector<int> c(n);
    for (int lv = 0; lv < 19; ++lv) {
        vector<int> used(n), sz(n), count1(n), count2(n);
        for (int i = 0; i < n; ++i) {
            if (used[i] || c[i]) {
                continue;
            }
            y_combinator([&](auto dfs, int v, int pr) -> void {
                sz[v] = 1;
                used[v] = 1;
                for (auto [u, x] : g[v]) {
                    if (!c[u] && u != pr) {
                        dfs(u, v);
                        sz[v] += sz[u];
                    }
                }
            })(i, i);
            int centr = y_combinator([&](auto dfs, int v, int pr) -> int {
                for (auto [u, x] : g[v]) {
                    if (!c[u] && u != pr && sz[u] * 2 > sz[i]) {
                        return dfs(u, v);
                    }
                }
                return v;
            })(i, i);
            c[centr] = true;
            vector<pair<int, int>> vals;
            y_combinator([&](auto dfs, int v, int pr, int val) -> void {
                if (val != -1) {
                    vals.push_back({val, v});
                }
                sz[v] = 1;
                for (auto [u, x] : g[v]) {
                    if (u != pr && !c[u]) {
                        count2[x]++;
                        dfs(u, v, x);
                        sz[v] += sz[u];
                        count2[x]--;
                    }
                }
                if (val != -1 && count2[val] == 1) {
                    count1[val] += sz[v];
                }
            })(centr, centr, -1);
            for (auto [u_r, x_r] : g[centr]) {
                if (c[u_r]) {
                    continue;
                }
                count2[x_r]++;
                y_combinator([&](auto dfs, int v, int pr, int val) -> void {
                    if (val != -1 && count2[val] == 1) {
                        count1[val] -= sz[v];
                    }
                    for (auto [u, x] : g[v]) {
                        if (u != pr && !c[u]) {
                            count2[x]++;
                            dfs(u, v, x);
                            count2[x]--;
                        }
                    }
                })(u_r, centr, x_r);
                int sz_nw = sz[u_r];
                y_combinator([&](auto dfs, int v, int pr, int val) -> void {
                    if (val != -1 && count2[val] == 1) {
                        ans += sz[v] * 1LL * (sz[centr] - count1[val] - sz_nw);
                    } else if (val != -1 && count2[val] == 2) {
                        ans -= sz[v] * 1LL * (sz[centr] - count1[val] - sz_nw);
                    }
                    for (auto [u, x] : g[v]) {
                        if (u != pr && !c[u]) {
                            count2[x]++;
                            dfs(u, v, x);
                            count2[x]--;
                        }
                    }
                })(u_r, centr, x_r);
                y_combinator([&](auto dfs, int v, int pr, int val) -> void {
                    if (val != -1 && count2[val] == 1) {
                        count1[val] += sz[v];
                    }
                    for (auto [u, x] : g[v]) {
                        if (u != pr && !c[u]) {
                            count2[x]++;
                            dfs(u, v, x);
                            count2[x]--;
                        }
                    }
                })(u_r, centr, x_r);
                count2[x_r]--;
            }
            for (auto [val, v] : vals) {
                count1[val] = count2[val] = 0;
            }
        }
    }
    cout << ans << '\n';
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