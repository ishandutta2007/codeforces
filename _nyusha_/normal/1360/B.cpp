#include<bits/stdc++.h>

using namespace std;

int a[55];

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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        int ans = 1005;
        for (int i = 2; i <= n; ++i) {
            ans = min(ans, a[i] - a[i - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}