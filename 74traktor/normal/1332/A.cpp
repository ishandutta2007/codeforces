#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        int go_x = x - a + b, go_y = y - c + d;
        if (x1 <= go_x && go_x <= x2 && y1 <= go_y && go_y <= y2) {
            if (min(a, b) != 0 && x1 == x2) cout << "NO" << '\n';
            else if (min(c, d) != 0 && y1 == y2) cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}