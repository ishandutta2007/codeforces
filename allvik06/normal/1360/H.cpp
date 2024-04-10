#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <string> a(n);
        vector <bool> now(n, true);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int w = ((1LL << m) - n - 1) / 2;
        string ans;
        for (int i = 0; i < m; ++i) {
            int flex = 0;
            for (int j = 0; j < n; ++j) {
                if (now[j] && a[j][i] == '0') ++flex;
            }
            if ((1LL << (m - i - 1)) - flex > w) {
                ans += "0";
                for (int j = 0; j < n; ++j) {
                    if (a[j][i] != '0') now[j] = false;
                }
            }
            else {
                ans += "1";
                w -= (1LL << (m - i - 1)) - flex;
                for (int j = 0; j < n; ++j) {
                    if (a[j][i] != '1') now[j] = false;
                }
            }
        }
        cout << ans << "\n";
    }
}