#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, maxx = 2 * (2e5 + 1);
    cin >> n >> m;
    vector<int> k(n);
    for (int i = 0; i < n; ++i) cin >> k[i];
    vector<vector<int>> days(maxx);
    for (int i = 0; i < m; ++i) {
        int d, nu;
        cin >> d >> nu;
        days[d].push_back(nu - 1);
    }
    int l = -1, r = maxx;
    while (r - l > 1) {
        vector<int> kk = k;
        int mid = (l + r) / 2;
        if (mid == 7) {
            int kek = 0;
        }
        int kol = mid, sk = 0;
        for (int i = mid; i >= 1; --i) {
            for (int j : days[i]) {
                sk += min(kol, kk[j]);
                int tmp = min(kol, kk[j]);
                kk[j] -= tmp;
                kol -= tmp;
            }
            if (i - kol == 0) --kol;
        }
        for (int i = 0; i < n; ++i) {
            sk += 2 * kk[i];
        }
        if (sk <= mid) r = mid;
        else l = mid;
    }
    cout << r;
}