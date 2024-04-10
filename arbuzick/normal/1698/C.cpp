#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n <= 6) {
        bool ch = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (!count(a.begin(), a.end(), a[i] + a[j] + a[k])) {
                        ch = false;
                    }
                }
            }
        }
        cout << (ch ? "YES\n" : "NO\n");
        return;
    }
    if (a[1] < 0 || a[n - 2] > 0) {
        cout << "NO\n";
    } else if (count(a.begin(), a.end(), a[0] + a[n - 1])) {
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