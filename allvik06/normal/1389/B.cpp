#include <bits/stdc++.h>

using namespace std;
#define int long long


signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector <int> a(n);
        vector <int> psum(n + 1);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) psum[i] = psum[i - 1] + a[i - 1];
        int maxx = psum[k + 1];
        for (int i = 1; i < n; ++i) {
            int cur = psum[i + 1];
            for (int kol = 1; kol <= z; ++kol) {
                if (i == 2 && kol == 3) {
                    int kek = 1;
                }
                if (k - i < 2 * kol - 1) break;
                int ost = k - i - 2 * kol + 1;
                if (cur + a[i - 1] * kol + a[i] * (kol - 1) + psum[i + ost] - psum[i] > maxx) {
                    maxx = cur + a[i - 1] * kol + a[i] * (kol - 1) + psum[i + ost] - psum[i];
                    if (maxx == 62) cerr << i << " " << kol << "\n";
                }
            }
        }
        cout << maxx << "\n";
    }
}