#include<bits/stdc++.h>

using namespace std;

int const maxn = 2005;
int a[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = a[n] - a[1];
        int mn = a[1];
        for (int r = 1; r < n; r++) {
            mn = min(mn, a[r]);
            ans = max(ans, a[n] - mn);
        }
        int mx = a[n];
        for (int l = n; l > 1; l--) {
            mx = max(mx, a[l]);
            ans = max(ans, mx - a[1]);
        }
        for (int i = 2; i <= n; i++) {
            ans = max(ans, a[i - 1] - a[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}