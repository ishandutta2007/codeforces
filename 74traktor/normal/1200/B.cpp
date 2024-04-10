#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, k, x;
    cin >> t;
    for (int tmp = 1; tmp <= t; ++tmp) {
        cin >> n >> m >> k;
        bool check = true;
        cin >> x;
        int last = x;
        for (int j = 2; j <= n; ++j) {
            cin >> x;
            if (x > last) {
                int imin = max(x - k, 0);
                if (last > imin) m += (last - imin);
                else {
                    if (imin - last > m) check = false;
                    else m -= (imin - last);
                }
            }
            else {
                int can = max(0, x - k);
                m += (last - can);
            }
            last = x;
        }
        if (check) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}