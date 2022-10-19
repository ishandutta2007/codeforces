#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 1 << ' ';
    }
    for (int i = n % 2; i < n; i += 2) {
        cout << i + 2 << ' ' << i + 1 << ' ';
    }
    cout << '\n';
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