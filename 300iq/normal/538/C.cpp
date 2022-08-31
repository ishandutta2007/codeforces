#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
    int n, m, x, y;
    cin >> n >> m;
    vector <int> d, h;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        d.push_back(x);
        h.push_back(y);
    }
    int ans = h[0];
    for (int i = 1; i < m; i++) {
        if (abs(d[i] - d[i - 1]) < abs(h[i] - h[i - 1])) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        } else {
            ans = max(ans, h[i]);
            x = min(h[i], h[i - 1]) + (abs(h[i] - h[i - 1]) + abs(d[i] - d[i - 1])) / 2;
            ans = max(ans, x);
        }
    }
    ans = max(ans, h[m - 1] + abs(d[m - 1] - n));
    ans = max(ans, h[0] + abs(d[0] - 1));
    cout << ans << endl;
}