#include<bits/stdc++.h>

using namespace std;

int const maxn = 2005;
int c[maxn], ans[maxn], d[maxn];
vector < int > g[maxn];
set < int > Q;
bitset < maxn > used[maxn];

void dfs1(int v, int p) {
    used[v][ans[v]] = 1;
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs1(u, v);
        used[v] = (used[v]|used[u]);
    }
    for (int i = 1; i < ans[v]; ++i) {
        if (used[v][i]) d[v]--;
    }
    if (d[v] != 0) {
        cout << "NO";
        exit(0);
    }
}

void dfs(int v, int p) {
    auto it = Q.begin();
    while (c[v]--) {
        if (it == Q.end()) {
            cout << "NO" << '\n';
            exit(0);
        }
        it++;
    }
    if (it == Q.end()) {
        cout << "NO" << '\n';
        exit(0);
    }
    ans[v] = (*it);
    Q.erase((*it));
    for (auto u : g[v]) {
        if (u != p) dfs(u, v);
    }
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, v;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p >> c[i];
        d[i] = c[i];
        if (p != 0) g[p].push_back(i);
        if (p == 0) v = i;
    }
    for (int i = 1; i <= n; ++i) Q.insert(i);
    dfs(v, 0);
    dfs1(v, 0);
    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}