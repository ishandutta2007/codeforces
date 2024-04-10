#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

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
    vector<int> fact(n + 1), _fact(n + 1);
    fact[0] = _fact[0] = 1;
    for (int i = 0; i < n; ++i) {
        fact[i + 1] = fact[i] * 1LL * (i + 1) % mod;
        _fact[i + 1] = binpow(fact[i + 1], mod - 2);
    }
    auto comb = [&](int n, int k) {
        return fact[n] * 1LL * _fact[k] % mod * _fact[n - k] % mod;
    };
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<char, int> s, f;
    for (int i = 0; i < n; ++i) {
        s[a[i][0]]++;
        f[a[i][1]]++;
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (i < s['W'] || i < f['B'] || n - i < s['B'] || n - i < f['W']) {
            continue;
        }
        ans = (ans + comb(s['?'], i - s['W']) * 1LL * comb(f['?'], i - f['B'])) % mod;
    }
    int val = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == "WW" || a[i] == "BB") {
            val = 0;
            break;
        }
        if (a[i] == "??") {
            val = val * 2LL % mod;
        }
    }
    ans = (ans - val + mod) % mod;
    int wb = 1, bw = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == 'W') {
            bw = 0;
        } else if (a[i][0] == 'B') {
            wb = 0;
        }
        if (a[i][1] == 'W') {
            wb = 0;
        } else if (a[i][1] == 'B') {
            bw = 0;
        }
    }
    ans = (ans + wb + bw) % mod;
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