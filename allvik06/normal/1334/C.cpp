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
        int n;
        cin >> n;
        vector <pair <int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        int nowi = n - 1, ans = min(a[n - 1].second, a[0].first);
        for (int i = 0; i < n - 1; ++i) {
            if (min(a[i].second, a[i + 1].first) < ans) {
                ans = min(a[i].second, a[i + 1].first);
                nowi = i;
            }
        }
        int res = 0;
        nowi = (nowi + 1) % n;
        for (int i = 0; i < n; ++i) {
            int ii = (nowi + i) % n;
            res += max(a[ii].first, (int)0);
            int next = (ii + 1) % n;
            a[next].first -= a[ii].second;
        }
        cout << res << "\n";
    }
    return 0;
}