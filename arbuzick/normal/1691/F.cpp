#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

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
    int n, k;
    cin >> n >> k;
    vector<int> f(n + 1), _f(n + 1);
    auto binpow = y_combinator([&](auto binpow, int n, int k) -> int {
        if (k == 0) {
            return 1;
        }
        if (k % 2) {
            return binpow(n, k - 1) * 1LL * n % mod;
        }
        int m = binpow(n, k / 2);
        return m * 1LL * m % mod;
    });
    f[0] = _f[0] = 1;
    for (int i = 0; i < n; ++i) {
        f[i + 1] = f[i] * 1LL * (i + 1) % mod;
        _f[i + 1] = binpow(f[i + 1], mod - 2);
    }
    auto comb = [&](int n, int k) {
        return f[n] * 1LL * _f[k] % mod * _f[n - k] % mod;
    };
    vector<vector<int>> g(n);
    vector<int> sz(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    y_combinator([&](auto dfs, int v, int p) -> void {
        sz[v] = 1;
        for (auto u : g[v]) {
            if (u != p) {
                dfs(u, v);
                sz[v] += sz[u];
            }
        }
    })(0, 0);
    int ans = 0;
    y_combinator([&](auto dfs, int v, int p) -> void {
        ans += comb(n, k) * 1LL * n % mod;
        ans %= mod;
        for (auto u : g[v]) {
            if (n - sz[u] >= k) {
                ans += comb(n - sz[u], k) * 1LL * (n - sz[u]) % mod * sz[u] % mod;
                ans %= mod;
            }
        }
        int sum = 0;
        for (auto u : g[v]) {
            if (sz[u] >= k) {
                sum += comb(sz[u], k);
                sum %= mod;
            }
        }
        ans -= sum * 1LL * n % mod;
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        for (auto u : g[v]) {
            if (sz[u] >= k) {
                sum -= comb(sz[u], k);
                sum %= mod;
                if (sum < 0) {
                    sum += mod;
                }
            }
            ans -= sum * 1LL * (n - sz[u]) % mod * sz[u] % mod;
            ans %= mod;
            if (ans < 0) {
                ans += mod;
            }
            if (sz[u] >= k) {
                sum += comb(sz[u], k);
                sum %= mod;
            }
        }
        for (auto u : g[v]) {
            if (u != p) {
                sz[v] -= sz[u];
                sz[u] += sz[v];
                dfs(u, v);
                sz[u] -= sz[v];
                sz[v] += sz[u];
            }
        }
    })(0, 0);
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