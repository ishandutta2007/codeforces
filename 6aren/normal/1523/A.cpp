#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        string res(n, '0');

        for (int i = 0; i < n; i++) {
            int mn = 2e9;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1') mn = min(mn, abs(i - j));
            }
            if (mn <= m) res[i] = '1';
            int mn_r = 1e9, mn_l = 1e9;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '1') {
                    mn_r = min(mn_r, j - i);
                    break;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '1') {
                    mn_l = i - j;
                    break;
                }
            }
            if (mn_r == mn_l && mn_l != 1e9 && s[i] != '1') {
                res[i] = '0';
            }
        }
        cout << res << '\n';
    }

    return 0;
}