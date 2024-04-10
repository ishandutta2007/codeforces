#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s += a[i];
        }
        if (s % x != 0) {
            cout << n << "\n";
            continue;
        }
        int k1 = 0, k2 = 0;
        int s1 = s;
        while (s1 % x == 0 && k1 < n) {
            s1 -= a[k1];
            k1++;
        }
        s1 = s;
        while (s1 % x == 0 && k2 < n) {
            s1 -= a[n - k2 - 1];
            k2++;
        }
        if (k1 == n && k2 == n)
            cout << -1 << "\n";
        else
            cout << max(n - k1, n - k2) << "\n";
    }
    return 0;
}