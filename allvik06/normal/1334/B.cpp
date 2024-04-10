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
        int n, x;
        cin >> n >> x;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int sum = 0;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (sum / (i + 1) < x) {
                ans = i;
                break;
            }
        }
        if (ans == -1) cout << n << "\n";
        else cout << ans << "\n";
    }
    return 0;
}