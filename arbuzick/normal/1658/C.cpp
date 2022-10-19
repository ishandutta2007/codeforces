#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (c[i] == 1) {
            if (pos != -1) {
                cout << "NO\n";
                return;
            }
            pos = i;
        }
    }
    if (pos == -1) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] > c[(i - 1 + n) % n] + 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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