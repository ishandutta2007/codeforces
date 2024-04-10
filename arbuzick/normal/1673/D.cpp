#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int b, q, y;
    cin >> b >> q >> y;
    int c, r, z;
    cin >> c >> r >> z;
    if (r % q != 0 || c < b || c + r * 1LL * (z - 1) > b + q * 1LL * (y - 1) || (b % q + q) % q != (c % q + q) % q) {
        cout << 0 << '\n';
        return;
    }
    if (c - r < b || c + r * 1LL * z > b + q * 1LL * (y - 1)) {
        cout << -1 << '\n';
        return;
    } else {
        int ans = 0;
        auto gcd = [&](int a, int b) {
            while (b) {
                a %= b;
                swap(a, b);
            }
            return a;
        };
        for (int i = 1; i * i <= r; ++i) {
            if (r % i == 0) {
                if (i * 1LL * q / gcd(i, q) == r) {
                    ans = (ans + (r / i) * 1LL * (r / i)) % mod;
                }
                if (r / i != i && r / i * 1LL * q / gcd(r / i, q) == r) {
                    ans = (ans + i * 1LL * i) % mod;
                }
            }
        }
        cout << ans << '\n';
    }
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