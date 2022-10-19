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
        int n, k, maxx = 1;
        cin >> n >> k;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i != 0) continue;
            if (n / i <= k) maxx = max(maxx, n / i);
            if (i <= k) maxx = max(maxx, i);
        }
        cout << n / maxx << "\n";
    }
}