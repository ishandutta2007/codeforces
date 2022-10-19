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
        int n, ans = 0, now = 1;
        cin >> n;
        for (int i = 1; i <= n / 2; ++i) {
            ans += i * ((2 * i + 1) * (2 * i + 1) - now);
            now = (2 * i + 1) * (2 * i + 1);
        }
        cout << ans << "\n";
    }
}