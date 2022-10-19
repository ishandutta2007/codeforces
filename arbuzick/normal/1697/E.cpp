#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

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
    auto binpow = y_combinator([&](auto binpow, int n, int k) -> int {
        if (k == 0) {
            return 1;
        }
        if (k % 2 == 1) {
            return binpow(n, k - 1) * 1LL * n % mod;
        }
        int m = binpow(n, k / 2);
        return m * 1LL * m % mod;
    });
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<int> f(n + 1), _f(n + 1);
    f[0] = _f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * 1LL * i % mod;
        _f[i] = binpow(f[i], mod - 2);
    }
    auto dist = [&](int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    };
    vector<int> mn(n, mod);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                mn[i] = min(mn[i], dist(x[i], y[i], x[j], y[j]));
            }
        }
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    vector<int> used(n, -1);
    for (int i = 0; i < n; ++i) {
        if (used[i] == -1) {
            vector<int> ind;
            bool ch = true;
            y_combinator([&](auto dfs, int v) -> void {
                used[v] = i;
                ind.push_back(v);
                for (int u = 0; u < n; ++u) {
                    if (dist(x[v], y[v], x[u], y[u]) == mn[v]) {
                        if (used[u] == -1) {
                            dfs(u);
                        } else if (used[u] != i) {
                            ch = false;
                        }
                    }
                }
            })(i);
            for (auto i : ind) {
                for (auto j : ind) {
                    if (i != j && dist(x[i], y[i], x[j], y[j]) != mn[i]) {
                        ch = false;
                    }
                }
            }
            if (ch) {
                vector<int> dp_nw(n + 1);
                for (int j = 1; j <= n; ++j) {
                    dp_nw[j] += dp[j - 1];
                }
                for (int j = (int)ind.size(); j <= n; ++j) {
                    dp_nw[j] += dp[j - (int)ind.size()];
                    if (dp_nw[j] >= mod) {
                        dp_nw[j] -= mod;
                    }
                }
                dp = dp_nw;
            } else {
                for (auto i : ind) {
                    used[i] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == -1) {
            vector<int> dp_nw(n + 1);
            for (int j = 1; j <= n; ++j) {
                dp_nw[j] += dp[j - 1];
            }
            dp = dp_nw;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += dp[i] * 1LL * f[n] % mod * _f[n - i] % mod;
        if (ans >= mod) {
            ans -= mod;
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