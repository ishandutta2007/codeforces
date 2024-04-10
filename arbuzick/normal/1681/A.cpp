#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx_a = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mx_a = max(mx_a, v);
    }
    int m;
    cin >> m;
    int mx_b = 0;
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        mx_b = max(mx_b, v);
    }
    if (mx_a > mx_b) {
        cout << "Alice\n";
        cout << "Alice\n";
    } else if (mx_a < mx_b) {
        cout << "Bob\n";
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
        cout << "Bob\n";
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