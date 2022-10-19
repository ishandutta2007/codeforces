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
        int n, k, sum = 0;
        cin >> n >> k;
        vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
        for (int j = 0; j < n; ++j) cin >> b[j];
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        for (int i = 0; i < k; ++i) {
            if (a[i] < b[i]) {
                sum += b[i] - a[i];
            }
        }
        cout << sum << "\n";
    }
}