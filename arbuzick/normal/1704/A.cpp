#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    for (int i = 1; i < m; ++i) {
        if (a[n - (m - i)] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    if (count(a.begin(), a.end(), b[0]) < count(b.begin(), b.end(), b[0])) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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