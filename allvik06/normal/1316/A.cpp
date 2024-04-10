#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, s = 0;
        cin >> n >> m;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s += a[i];
        }
        int kol = s - a[0];
        cout << min(a[0] + kol, m) << "\n";
    }
}