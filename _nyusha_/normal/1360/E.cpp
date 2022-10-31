#include<bits/stdc++.h>

using namespace std;

char a[55][55];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (a[i][j] == '1' && a[i + 1][j] == '0' && a[i][j + 1] == '0') ans = 0;
            }
        }
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}