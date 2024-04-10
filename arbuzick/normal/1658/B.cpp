#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << '\n';
    } else {
        int f = 1;
        for (int i = 1; i <= n / 2; ++i) {
            f = f * 1LL * i % mod * i % mod;
        }
        cout << f << '\n';
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