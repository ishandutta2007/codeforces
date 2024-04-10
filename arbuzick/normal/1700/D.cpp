#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<long long> kek(n + 1, 0);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
        kek[i + 1] = max(kek[i], (sum - 1) / (i + 1) + 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        int l = 0, r = n + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (kek[m] <= t && t * 1LL * m >= sum) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r == n + 1) {
            cout << -1 << '\n';
        } else {
            cout << r << '\n';
        }
    }
    return 0;
}