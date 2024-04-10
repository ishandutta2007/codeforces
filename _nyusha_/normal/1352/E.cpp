#include<bits/stdc++.h>

using namespace std;

int a[8005], ok[8005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) ok[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = a[i];
            for (int j = i + 1; j <= n; ++j) {
                sum += a[j];
                if (sum <= n) ok[sum] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans += ok[a[i]];
        cout << ans << '\n';
    }
    return 0;
}