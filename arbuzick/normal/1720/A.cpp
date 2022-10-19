#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * 1LL * d == b * 1LL * c) {
        cout << 0 << '\n';
    } else if (a == 0 || c == 0 || (a * 1LL * d) % (b * 1LL * c) == 0 || (b * 1LL * c) % (a * 1LL * d) == 0) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
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