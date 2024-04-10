#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, b, p, f, h, c;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> b >> p >> f >> h >> c;
        int ans = 0;
        for (int tmp = 0; tmp <= p; ++tmp) {
            for (int cur = 0; cur <= f; ++cur) {
                if (2 * (tmp + cur) <= b) ans = max(ans, tmp * h + cur * c);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}