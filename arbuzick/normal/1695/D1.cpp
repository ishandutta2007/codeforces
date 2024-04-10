#include <bits/stdc++.h>

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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    if (n > 1) {
        ans = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() >= 3) {
            vector<int> dp(n);
            y_combinator([&](auto dfs, int v, int pr) -> void {
                vector<int> vals;
                for (auto u : g[v]) {
                    if (u != pr) {
                        dfs(u, v);
                        vals.push_back(dp[u]);
                    }
                }
                sort(vals.rbegin(), vals.rend());
                for (int i = 0; i + 1 < (int)vals.size(); ++i) {
                    dp[v] += max(1, vals[i]);
                }
                if (!vals.empty()) {
                    dp[v] += vals.back();
                }
            })(i, i);
            ans = max(ans, dp[i]);
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