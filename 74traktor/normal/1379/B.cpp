#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, l, r, m;
    cin >> t;
    while (t--) {
        cin >> l >> r >> m;
        int lef = m + l - r, righ = m + r - l;
        lef = max(lef, (long long)1);
        for (int a = l; a <= r; ++a) {
            if (righ / a != (lef - 1) / a) {
                int d = m - righ / a * a;
                if (d < 0) cout << a << " " << l << " " << abs(d) + l << '\n';
                else cout << a << " " << r << " " << r - d << '\n';
                break;
            }
        }
    }
    return 0;
}