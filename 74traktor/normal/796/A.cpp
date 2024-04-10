#include<bits/stdc++.h>

using namespace std;

int a[105];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int d = 0; d <= n; ++d) {
        if (m - d >= 1 && a[m - d] <= k && a[m - d] != 0) {
            cout << d * 10;
            exit(0);
        }
        if (m + d <= n && a[m + d] <= k && a[m + d] != 0) {
            cout << d * 10;
            exit(0);
        }
    }
    return 0;
}