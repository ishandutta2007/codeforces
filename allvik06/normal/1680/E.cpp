#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char a[2][n];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int pref[n + 1][4];
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < 4; ++k) {
                pref[j][k] = INF;
            }
        }
        pref[0][0] = 0;
        int b[4] = {0, 1, 1, 2};
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            if (a[0][i] == '*') mask += 1;
            if (a[1][i] == '*') mask += 2;
            for (int msk1 = 0; msk1 < 4; ++msk1) {
                int msk = (mask | msk1);
                pref[i + 1][msk] = min(pref[i + 1][msk], pref[i][msk1] + b[msk1]);
            }
            pref[i + 1][1] = min(pref[i + 1][1], pref[i + 1][3] + 1);
            pref[i + 1][2] = min(pref[i + 1][2], pref[i + 1][3] + 1);
        }
        int ans = INF;
        for (int i = n - 1; i >= 0; --i) {
            if (a[0][i] == '*' || a[1][i] == '*') {
                ans = min(pref[i + 1][1], pref[i + 1][2]);
                break;
            }
        }
        cout << ans << "\n";
    }
}