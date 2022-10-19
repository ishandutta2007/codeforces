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
        int n, k;
        cin >> n >> k;
        vector <int> a(n), w(k);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < k; ++i) cin >> w[i];
        sort(a.begin(), a.end());
        sort(w.begin(), w.end());
        int l = 0, r = n - 1, ans = 0;
        for (int i : w) {
            if (i == 1) {
                ans += 2 * a[r];
                --r;
                continue;
            }
            else break;
        }
        vector <int> kek;
        for (int i : w) {
            if (i != 1) kek.push_back(i);
        }
        sort(kek.rbegin(), kek.rend());
        for (int i : kek) {
            ans += a[r];
            --r;
            ans += a[l];
            ++l;
            for (int j = 0; j < i - 2; ++j) {
                ++l;
            }
        }
        cout << ans << "\n";
    }
}