#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int used[maxn], cnt, n, ok, ans[maxn], oks[maxn];
vector < int > g[maxn];
vector < int > answ;
set < pair < int, int > > go[maxn];
map < vector < int >, int > gett;
int tt[5];
map < pair < int, int >, int > cntt;

void dfs(int v) {
    cnt++;
    ans[cnt] = v, used[v] = 1;
    for (auto u : g[v]) {
        if (used[u] == 0 && cntt[{min(u, v), max(u, v)}] == 1) {
            dfs(u);
        }
    }
}

void solve() {
    int a, b, c;
    cin >> n;
    gett.clear(), cntt.clear();
    for (int i = 1; i <= n; ++i) g[i] = {}, used[i] = 0, oks[i] = 0, go[i] = {};
    for (int i = 1; i <= n - 2; ++i) {
        cin >> a >> b >> c;
        if (a == 1) oks[b] = 1, oks[c] = 1;
        if (b == 1) oks[a] = 1, oks[c] = 1;
        if (c == 1) oks[a] = 1, oks[b] = 1;
        g[a].push_back(b);
        g[a].push_back(c);
        g[b].push_back(a);
        g[b].push_back(c);
        g[c].push_back(a);
        g[c].push_back(b);
        cntt[{min(a, b), max(a, b)}]++;
        cntt[{min(a, c), max(a, c)}]++;
        cntt[{min(b, c), max(b, c)}]++;
        go[a].insert({min(b, c), max(b, c)});
        go[b].insert({min(a, c), max(a, c)});
        go[c].insert({min(a, b), max(a, b)});
        tt[0] = a, tt[1] = b, tt[2] = c;
        sort(tt + 0, tt + 3);
        gett[{tt[0], tt[1], tt[2]}] = i;
    }
    set < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i) Q.insert({(int)go[i].size(), i});
    answ = {};
    while ((int)Q.size() > 0) {
        auto p = (*Q.begin());
        Q.erase(p);
        for (auto key : go[p.second]) {
            tt[0] = p.second, tt[1] = key.first, tt[2] = key.second;
            sort(tt + 0, tt + 3);
            answ.push_back(gett[{tt[0], tt[1], tt[2]}]);
            Q.erase({(int)go[key.first].size(), key.first});
            Q.erase({(int)go[key.second].size(), key.second});
            go[key.first].erase({min(p.second, key.second), max(p.second, key.second)});
            go[key.second].erase({min(p.second, key.first), max(p.second, key.first)});
            Q.insert({(int)go[key.first].size(), key.first});
            Q.insert({(int)go[key.second].size(), key.second});
        }
    }
    cnt = 0, ok = 0;
    dfs(1);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';
    for (auto key : answ) cout << key << " ";
    cout << '\n';
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
    while (t--) solve();
    return 0;
}