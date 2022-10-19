#include <bits/stdc++.h>

using namespace std;

void solve() {
    int w;
    cin >> w;
    if (w % 2 == 1 || w < 4) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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