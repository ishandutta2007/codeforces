#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, t, ans;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ans = n;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (i <= k) ans = min(ans, n / i);
                if (n / i <= k) ans = min(ans, i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}