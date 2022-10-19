#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i < n + 2; ++i) {
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