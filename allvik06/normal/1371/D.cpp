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
        int flex = k / n;
        vector <vector <int>> a(n, vector <int> (n));
        int j = 0;
        k -= flex * n;
        for (int i = 0; i < n; ++i) {
            for (int len = 0; len < flex + (i < k); ++len) {
                a[i][j] = 1;
                ++j;
                j %= n;
            }
        }
        int maxr = -1, minr = n * n + 1, mins = n * n + 1, maxs = -1;
        for (int i = 0; i < n; ++i) {
            int now = 0;
            for (int jj = 0; jj < n; ++jj) now += a[i][jj];
            maxs = max(maxs, now);
            mins = min(mins, now);
        }
        for (int i = 0; i < n; ++i) {
            int now = 0;
            for (int jj = 0; jj < n; ++jj) now += a[jj][i];
            maxr = max(maxr, now);
            minr = min(minr, now);
        }
        cout << (maxs - mins) * (maxs - mins) + (maxr - minr) * (maxr - minr) << "\n";
        for (int i = 0; i < n; ++i) {
            for (int jj = 0; jj < n; ++jj) {
                cout << a[i][jj];
            }
            cout << "\n";
        }
    }
}