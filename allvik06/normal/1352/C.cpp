#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 10;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int l = 0, r = INF;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if ((n - 1) * m >= k) {
                r = m;
            }
            else {
                l = m;
            }
        }
        cout << n * (r - 1) + k - (n - 1) * (r - 1) << "\n";
    }
    return 0;
}