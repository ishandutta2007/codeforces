#include <bits/stdc++.h>

using namespace std;

int a[150005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; ++j) cin >> a[j];
        int ans = 0, imin = a[n];
        for (int j = n - 1; j >= 1; --j) {
            if (a[j] > imin) ans++;
            imin = min(imin, a[j]);
        }
        cout << ans << '\n';
    }
    return 0;
}