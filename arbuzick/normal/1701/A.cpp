#include <bits/stdc++.h>

using namespace std;

int a[2][2];

void solve() {
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
    if (a[0][0] && a[0][1] && a[1][0] && a[1][1]) {
        cout << 2 << '\n';
    } else {
        cout << min(1, a[0][0] + a[0][1] + a[1][0] + a[1][1]) << '\n';
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