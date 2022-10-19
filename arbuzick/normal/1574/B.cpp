#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (m <= a - 1 + b - 1 + c - 1 && max({a, b, c}) - m - 1 <= a + b + c - max({a, b, c})) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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