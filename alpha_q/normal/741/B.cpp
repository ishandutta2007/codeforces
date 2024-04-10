#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

struct data {
    long long w, b;
    int id, comp;
};

bitset <N> vis;
vector <int> g[N];
int n, m;
long long w;
long long dp[N][N], size[N];
long long wAll[N], bAll[N], tot = 0;
data d[N];

void dfs (int u) {
    vis[u] = 1;
    d[u].comp = tot;
    ++size[tot];
    wAll[tot] += d[u].w;
    bAll[tot] += d[u].b;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

bool cmp (data a, data b) {
    return a.comp < b.comp;
}

long long call (int p, long long cost) {
    if (p > n) return 0;
    if (dp[p][cost] != -1) return dp[p][cost];
    long long &ret = dp[p][cost];
    ret = call(p + 1, cost);
    if (cost + d[p].w <= w) ret = max(ret, d[p].b + call(size[d[p].comp] + 1, cost + d[p].w));
    if (cost + wAll[d[p].comp] <= w) ret = max(ret, bAll[d[p].comp] + call(size[d[p].comp] + 1, cost + wAll[d[p].comp]));
    return ret;
}

int main (int argc, char const *argv[]) {
    scanf("%d %d %lld", &n, &m, &w);
    for (int i = 1; i <= n; ++i) {
        d[i].id = 1;
        scanf("%lld", &d[i].w);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &d[i].b);
    }
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++tot;
            dfs(i);
        }
    }
    sort(d + 1, d + n + 1, cmp);
    for (int i = 1; i <= tot; ++i) size[i] += size[i - 1];
    memset(dp, -1, sizeof dp);
    printf("%lld\n", call(1, 0));
    return 0;
}