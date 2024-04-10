#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) {
            swap(x, y);
        }
        int now = 0;
        if (2 * a >= b) {
            if (y < 0) {
                now = -y * b;
                x += -y;
                y = 0;
            } else if (x > 0) {
                now = x * b;
                y -= x;
                x = 0;
            }
        }
        now += abs(x) * a + abs(y) * a;
        cout << now << "\n";
    }
    return 0;
}