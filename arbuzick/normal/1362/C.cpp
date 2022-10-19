#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int a = 1; a <= n; a *= 2)
            ans += n / a;
        cout << ans << "\n";
    }
    return 0;
}