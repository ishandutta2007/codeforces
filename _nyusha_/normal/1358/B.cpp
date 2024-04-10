#include<bits/stdc++.h>

using namespace std;

int a[100005];

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
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] < i + 1) ans = max(ans, i + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}