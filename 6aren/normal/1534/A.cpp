#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> res(n, string(m, ' ')), s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        bool ok = 0;
        for (int mode = 0; mode < 2; mode++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[i][j] = (mode ^ ((i + j) % 2) ? 'R' : 'W'); 
                }
            }
            bool check = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (s[i][j] != '.' && s[i][j] != res[i][j]) check = 0;
                }
            }
            if (check) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            for (auto e : res) cout << e << '\n';
        } else cout << "NO\n";
    }

    return 0;
}