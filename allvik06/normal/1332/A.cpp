#include <bits/stdc++.h>

using namespace std;
#define int long long
bool check(int x, int x1, int x2) {
    return x >= x1 && x <= x2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, x, y, x1, y1, x2, y2;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        int tmpx = x - a + b, tmpy = y - c + d;
        if (check(x, x1, x2) && check(tmpx, x1, x2) && check(y, y1, y2) && check(tmpy, y1, y2)) {
            if (x1 == x2 && (a != 0 || b != 0)) {
                cout << "NO\n";
            }
            else if (y1 == y2 && (c != 0 || d != 0)) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}