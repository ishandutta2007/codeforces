#include<bits/stdc++.h>

using namespace std;

int nxt[100005][26];

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
        string s, t;
        cin >> s >> t;
        int ans = 0, ptr = 0;
        int n = (int)s.size();
        for (int j = 0; j < 26; ++j) nxt[n][j] = n;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s[i] - 'a'] = i;
        }
        while (ptr < (int)t.size()) {
            ans++;
            int pos = -1;
            int where = ptr;
            while (ptr < (int)t.size() && pos < (int)s.size()) {
                pos = nxt[pos + 1][t[ptr++] - 'a'];
            }
            if (pos == (int)s.size()) ptr--;
            if (where == ptr) {
                cout << -1 << '\n';
                break;
            }
            if (ptr == (int)t.size()) {
                cout << ans << '\n';
                break;
            }
        }
    }
    return 0;
}