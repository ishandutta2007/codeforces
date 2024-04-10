#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <int> flex(32);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int maxx = -1;
            for (int j = 31; j >= 0; --j) {
                if ((a[i] >> j) & 1) {
                    maxx = j;
                    break;
                }
            }
            ans += flex[maxx];
            ++flex[maxx];
        }
        cout << ans << "\n";
    }
}