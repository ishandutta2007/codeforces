#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
vector < int > g[maxn];
int f[maxn], used[maxn];
vector < int > topsort;
int oks, lst;

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) if (used[u] == 0) dfs(u);
    topsort.push_back(v);
}

void dfs1(int v) {
    used[v] = 2;
    lst = v;
    for (auto u : g[v]) {
        if (used[u] == 2) oks = 1;
        else dfs1(u);
    }
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
    for (int i = 1; i <= n; ++i) cin >> f[i];
    for (int i = 1; i <= n; ++i) {
        if (f[i] != 0) {
            g[i].push_back(f[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    vector < pair < int, int > > cur;
    for (auto key : topsort) {
        if (used[key] == 1) {
            oks = 0, lst = 0;
            dfs1(key);
            if (oks == 0) cur.push_back({key, lst});
        }
    }
    for (int i = 0; i < (int)cur.size(); ++i) {
        int j = (i + 1) % (int)cur.size();
        f[cur[i].second] = cur[j].first;
    }
    for (int i = 1; i <= n; ++i) cout << f[i] << " ";
    return 0;
}