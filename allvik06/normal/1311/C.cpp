#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector <int> p(m);
        for (int i = 0; i < m; ++i) {
            cin >> p[i];
        }
        vector <int> now(n);
        now[0] = 1;
        for (int i = 0; i < m; ++i) {
            ++now[0];
            --now[p[i]];
        }
        for (int i = 1; i < n; ++i) {
            now[i] = now[i - 1] + now[i];
        }
        vector <int> ans(26);
        for (int i = 0; i < n; ++i) {
            ans[s[i] - 'a'] += now[i];
        }
        for (int i = 0; i < 26; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}