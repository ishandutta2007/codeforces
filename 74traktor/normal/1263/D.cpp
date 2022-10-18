#include<bits/stdc++.h>

using namespace std;

int const maxn = 200005;
vector < int > go[27];
vector < int > g[maxn];
int used[maxn];

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) if (used[u] == 0) dfs(u);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (auto c : s) go[c - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < (int)go[i].size(); ++j) {
            int nxt = (j + 1) % (int)go[i].size();
            g[go[i][j]].push_back(go[i][nxt]);
            g[go[i][nxt]].push_back(go[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) ans++, dfs(i);
    }
    cout << ans;
    return 0;
}