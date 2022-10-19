#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

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
    n++;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sz = n + a[0] + 10;
    vector<int> f(sz), _f(sz);
    f[0] = _f[0] = 1;
    for (int i = 1; i < sz; ++i) {
        f[i] = f[i - 1] * 1LL * i % mod;
        _f[i] = binpow(f[i], mod - 2);
    }
    auto comb = [&](int n, int k) {
        if (n < k) {
            return 0LL;
        }
        return f[n] * 1LL * _f[k] % mod * _f[n - k] % mod;
    };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + comb(i + a[i], i + 1)) % mod;
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