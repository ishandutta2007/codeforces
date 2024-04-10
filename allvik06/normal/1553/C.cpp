#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int ans = 10;
        for (int i = 0; i < 2; ++i) {
            int cur0 = 0, cur1 = 0;
            for (int j = 0; j < 10; ++j) {
                if (s[j] == '1') {
                    if (j % 2 == 0) ++cur0;
                    else ++cur1;
                } else if (s[j] == '?') {
                    if (j % 2 == i) {
                        if (i == 0) ++cur0;
                        else ++cur1;
                    }
                }
                int ost0 = (10 - j - 1) / 2, ost1 = (10 - j) / 2;
                if (i == 0) {
                    if (cur0 > cur1 + ost1) ans = min(ans, j + 1);
                } else {
                    if (cur1 > cur0 + ost0) ans = min(ans, j + 1);
                }
            }
        }
        cout << ans << "\n";
    }
}