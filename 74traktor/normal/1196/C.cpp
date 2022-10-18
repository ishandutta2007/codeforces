#include <bits/stdc++.h>

using namespace std;

int inf1 = -1 * 1e5;
int inf2 = -1 * inf1;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, x, y, f1, f2, f3, f4, min_x, min_y, max_x, max_y, n;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> n;
        min_x = inf1, min_y = inf1, max_x = inf2, max_y = inf2;
        for (int j = 1; j <= n; ++j) {
            cin >> x >> y >> f1 >> f2 >> f3 >> f4;
            if (f1 == 0) {
                min_x = max(min_x, x);
            }
            if (f2 == 0) {
                max_y = min(max_y, y);
            }
            if (f3 == 0) {
                max_x = min(max_x, x);
            }
            if (f4 == 0) {
                min_y = max(min_y, y);
            }
        }
        if (min_x <= max_x && min_y <= max_y) cout << 1 << " " << min_x << " " << min_y << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}