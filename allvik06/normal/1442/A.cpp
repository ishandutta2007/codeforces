#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int kol = 0;
        bool f = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] - kol < 0) {
                f = false;
            }
            if (a[i] - kol > a[i - 1]) {
                kol += (a[i] - kol) - a[i - 1];
                a[i] = a[i - 1];
            } else {
                a[i] -= kol;
            }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
}