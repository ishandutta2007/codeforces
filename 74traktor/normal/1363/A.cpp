#include<bits/stdc++.h>

using namespace std;

int a[1005];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] % 2 == 0) cnt0++;
            else cnt1++;
        }
        for (int i = 1; i <= x; i += 2) {
            if (i <= cnt1 && x - i <= cnt0) ans = 1;
        }
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}