#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define int long long
const int mod = 1e9 + 7;

inline int power(int a, int n) {
    int cur = 1;
    while (n) {
        if (n & 1) {
            cur = cur * a % mod;
        }
        n >>= 1;
        a = a * a % mod;
    }
    return cur;
}

inline void solve() {
    int n, k;
    cin >> n >> k;
    k = min(n, k);
    vector <int> f(n + 1, 1), rf(n + 1, 1);
    for (int i = 2; i <= n; ++i) f[i] = f[i - 1] * i % mod;
    rf[n] = power(f[n], mod - 2);
    for (int i = n - 1; i > 1; --i) rf[i] = rf[i + 1] * (i + 1) % mod;

    auto cnk = [&](int nn, int kk) {
        return f[nn] * rf[kk] % mod * rf[nn - kk] % mod;
    };

    int ans = 0;
    for (int i = 0; i <= k; ++i) ans = (ans + cnk(n, i)) % mod;
    cout << ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*

 */