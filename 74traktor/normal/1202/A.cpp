#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    string x, y;
    bool f;
    for (int i = 1; i <= t; ++i) {
        cin >> x >> y;
        int k = (int)x.size(), t = (int)y.size();
        k--, t--;
        f = true;
        int pos = -1;
        for (int j = 0; j <= t; ++j) {
            if (y[j] == '1') pos = j;
        }
        for (int j = k; j >= 0; --j) {
            if (x[j] == '0') {
                continue;
            }
            else {
                int dist1 = k - j, dist2 = t - pos;
                if (dist1 >= dist2 && f) {
                    cout << dist1 - dist2 << '\n';
                    f = false;
                }
            }
        }
    }
    return 0;
}