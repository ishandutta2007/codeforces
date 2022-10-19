#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int b = log2(n - 1);
    for (int i = 1; i < (1 << b); ++i) {
        cout << i << ' ';
    }
    cout << 0 << ' ' << (1 << b) << ' ';
    for (int i = (1 << b) + 1; i < n; ++i) {
        cout << i << ' ';
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