#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

/**
a[i] i
w[i] i
f[i][j] i2^j1
cnt[i] 
dis[i] i
*/
int n, a[maxn], w[maxn], f[maxn][21], cnt[maxn];
long long dis[maxn];
vector<int> g[maxn];

/**
u , p, d
*/
void dfs1(int u, int p, long long d) {
    dis[u] = d;
    f[u][0] = p;
    for (auto v : g[u])
        dfs1(v, u, d + w[v]);
}

/**
ua[u]
*/
int getid(int u) {
    long long d = dis[u] - a[u];
    for (int i = 20; i >= 0; i--) {
        int p = f[u][i];
        if (p && dis[p] >= d) u = p;
    }
    return u;
}

/**

*/
void dfs2(int u) {
    for (auto v : g[u]) {
        dfs2(v);
        cnt[u] += cnt[v];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u >> w[v];
        g[u].push_back(v);
    }
    dfs1(1, 1, 0);
    for (int i = 1; i <= 20; i++)
        for (int u = 1; u <= n; u++)
            f[u][i] = f[ f[u][i-1] ][i-1];
    for (int u = 2; u <= n; u++) {
        int pp = getid(u);
        if (pp == u) continue;
        if (u != 1) cnt[f[u][0]]++;
        if (pp != 1) cnt[f[pp][0]]--;
    }
    dfs2(1);
    for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    return 0;
}