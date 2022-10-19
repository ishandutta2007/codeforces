#include <bits/stdc++.h>

using namespace std;
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector <int> a(101);
    while (t--) {
        int n, m;
        cin >> n >> m;
        a.assign(101, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++a[x];
        }
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            ++a[x];
        }
        int ans = 0;
        for (int i = 0; i <= 100; ++i) {
            ans += max(0, a[i] - 1);
        }
        cout << ans << "\n";
    }
}