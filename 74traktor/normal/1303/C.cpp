#include<bits/stdc++.h>

using namespace std;

set < int > g[27];
int was[27];
string ans;

void dfs(int v) {
    ans += char('a' + v);
    was[v] = 1;
    for (auto u : g[v]) {
        if (was[u] == 0) dfs(u);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r",  stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int j = 0; j < 26; ++j) g[j] = {}, was[j] = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (i != 0) g[s[i] - 'a'].insert(s[i - 1] - 'a');
            if (i != (int)s.size() - 1) g[s[i] - 'a'].insert(s[i + 1] - 'a');
        }
        int ok = 1, good = 0;
        ans = "";
        for (int j = 0; j < 26; ++j) {
            if ((int)g[j].size() > 2) ok = 0;
        }
        if (ok == 0) {
            cout << "NO" << '\n';
            continue;
        }
        for (int j = 0; j < 26; ++j) {
            if ((int)g[j].size() == 0) ans += char('a' + j);
        }
        for (int j = 0; j < 26; ++j) {
            if (was[j] == 0 && (int)g[j].size() == 1) dfs(j);
        }
        if ((int)ans.size() == 26) {
            cout << "YES" << '\n';
            cout << ans << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}