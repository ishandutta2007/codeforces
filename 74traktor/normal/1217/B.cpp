#include <bits/stdc++.h>

using namespace std;

#define int long long
int inf = 1e18;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, x, d, h, imax, f;
        cin >> n >> x;
        imax = -1, f = -1 * inf;
        for (int j = 1; j <= n; ++j) {
            cin >> d >> h;
            imax = max(imax, d);
            f = max(f, d - h);
        }
        if (f <= 0) {
            if (x <= imax) cout << 1 << '\n';
            else cout << -1 << '\n';
        }
        else {
            if (x <= imax) cout << 1 << '\n';
            else {
                int g = (x - imax + f - 1) / f;
                cout << g + 1 << '\n';
            }
        }
    }
    return 0;
}