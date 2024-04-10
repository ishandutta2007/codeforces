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
        for (int i = 0; i < n; ++i) cin >> a[i];
        int sum0 = 0, sum1 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) sum0 += a[i];
            else sum1 += a[i];
        }
        if (sum0 > sum1) {
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) cout << a[i] << " ";
                else cout << 1 << " ";
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 1) cout << a[i] << " ";
                else cout << 1 << " ";
            }
        }
        cout << "\n";
    }
}