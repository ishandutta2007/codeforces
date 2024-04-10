#include <bits/stdc++.h>

using namespace std;
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <pair <int, int>> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
        bool ans = false;
        for (int i = 0; i < n; ++i) {
            bool f = true;
            for (int j = 0; j < n; ++j) {
                if (abs(a[j].first - a[i].first) + abs(a[j].second - a[i].second) > k) f = false;
            }
            if (f) ans = true;
        }
        if (ans) cout << 1 << "\n";
        else cout << -1 << "\n";
    }
}