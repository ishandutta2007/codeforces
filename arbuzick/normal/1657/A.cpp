#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 0 << '\n';
    } else if (((int)sqrt(x * x + y * y)) * ((int)sqrt(x * x + y * y)) == x * x + y * y) {
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