#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int mn_x = 0, mx_x = 0, mn_y = 0, mx_y = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        mn_x = min(mn_x, x);
        mx_x = max(mx_x, x);
        mn_y = min(mn_y, y);
        mx_y = max(mx_y, y);
    }
    cout << (abs(mn_x) + abs(mx_x) + abs(mn_y) + abs(mx_y)) * 2 << '\n';
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