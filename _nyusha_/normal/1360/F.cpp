#include<bits/stdc++.h>

using namespace std;

string s[11];

inline int f(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < (int)s1.size(); ++i) {
        if (s1[i] != s2[i]) cnt++;
    }
    return cnt <= 1;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> s[i];
        string ans = "";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 26; ++j) {
                string go = s[1];
                go[i] = char('a' + j);
                int oks = 1;
                for (int z = 2; z <= n; ++z) {
                    if (!f(s[z], go)) {
                        oks = 0;
                        break;
                    }
                }
                if (oks) ans = go;
            }
        }
        if (ans == "") cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}