#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 3 == 0) {
        cout << n / 3 << ' ' << n / 3 + 1 << ' ' << n / 3 - 1 << '\n';
    } else if (n % 3 == 1) {
        cout << n / 3 << ' ' << n / 3 + 2 << ' ' << n / 3 - 1 << '\n';
    } else {
        cout << n / 3 + 1 << ' ' << n / 3 + 2 << ' ' << n / 3 - 1 << '\n';
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