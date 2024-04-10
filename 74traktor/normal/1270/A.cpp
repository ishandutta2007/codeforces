#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k1, k2, x;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> k1 >> k2;
        int x1 = 0, x2 = 0;
        for (int j = 1; j <= k1; ++j) {
            cin >> x;
            x1 = max(x1, x);
        }
        for (int j = 1; j <= k2; ++j) {
            cin >> x;
            x2 = max(x2, x);
        }
        if (x1 > x2) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}