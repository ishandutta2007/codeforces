#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int dif = -1, mn_dif = -10;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            cout << "NO\n";
            return;
        }
        if (b[i] == 0) {
            mn_dif = max(mn_dif, a[i]);
        } else {
            if (dif == -1) {
                dif = a[i] - b[i];
            } else if (dif != a[i] - b[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    if (dif == -1 || dif >= mn_dif) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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