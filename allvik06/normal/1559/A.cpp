#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = a[0];
        for (int i = 0; i < n; ++i) {
            ans &= a[i];
        }
        cout << ans << "\n";
    }
}