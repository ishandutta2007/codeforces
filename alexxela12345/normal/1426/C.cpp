#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // x
        // x+(n+x)/(1+x)
        int ans = 1e9;
        for (int x = 0; x < 4 * 10000; x++) {
            ans = min(ans, x + (n - (1 + x) + x) / (1 + x));
        }
        cout << ans << endl;
    }
}