#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        cin >> n >> u >> v;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        bool ok = true, ok1 = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[0]) ok = false;
            if (abs(a[i] - a[i - 1]) > 1) ok1 = false;
        }
        if (!ok1) cout << 0 << "\n";
        else if (ok) cout << min(u + v, 2 * v) << "\n";
        else cout << min(u, v) << "\n";
    }
}