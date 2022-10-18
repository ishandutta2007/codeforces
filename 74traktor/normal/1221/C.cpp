#include <bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, c, m, x;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> c >> m >> x;
        int imin = min(c, m);
        int dx = x + c - imin + m - imin;
        if (dx >= imin) cout << imin << '\n';
        else {
            int cnt = (imin - dx + 2) / 3;
            cout << max(0, imin - cnt) << '\n';
        }
    }
    return 0;
}