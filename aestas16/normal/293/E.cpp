/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5, INF = 0x7f7f7f7f;

namespace Edges {
    struct Edge {
        int to, nxt, val;
    } e[(N << 1) + 10];
    int etot = 1, hd[N + 10];
    void adde(int x, int y, int z) { e[++etot] = {y, hd[x], z}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

int n, m, k, rt, tot, ans, arr[N + 10], dep[N + 10], sz[N + 10], maxsz[N + 10], dis[N + 10];
bool vis[N + 10];

namespace BIT {
    int bval[N + 10];
    int lowbit(int x) { return x & -x; }
    void add(int pos, int val) {
        for (int i = pos; i <= n + 1; i += lowbit(i)) bval[i] += val;
    }
    int qsum(int pos) {
        if (pos <= 0) return 0;
        int ret = 0;
        for (int i = pos; i; i -= lowbit(i)) ret += bval[i];
        return ret;
    }
} // namespace BIT
using namespace BIT;

bool cmp(int x, int y) { return dis[x] < dis[y]; }

void findrt(int u, int p, int total) {
    sz[u] = 1, maxsz[u] = 0;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p || vis[v]) continue;
        findrt(v, u, total), sz[u] += sz[v], maxsz[u] = max(maxsz[u], sz[v]);
    }
    maxsz[u] = max(maxsz[u], total - sz[u]);
    if (maxsz[u] < maxsz[rt]) rt = u;
}

void dfsson(int u, int p, int s) {
    arr[++tot] = u, dep[u] = dep[p] + 1;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p || vis[v]) continue;
        dis[v] = dis[u] + e[i].val, dfsson(v, u, s);
    }
}

int work(int u, int Dis, int Dep) {
    arr[tot = 1] = u, dis[u] = Dis, dep[u] = Dep;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (vis[v]) continue;
        dis[v] = Dis + e[i].val, dfsson(v, u, v);
    }
    sort(arr + 1, arr + 1 + tot, cmp);
    int pl = 1, pr = tot, ret = 0;
    for (int i = 1; i <= tot; i++) add(dep[arr[i]] + 1, 1);
    while (pl < pr) {
        if (dis[arr[pl]] + dis[arr[pr]] <= k)
            add(dep[arr[pl]] + 1, -1), ret += qsum(m - dep[arr[pl]] + 1), pl++;
        else
            add(dep[arr[pr]] + 1, -1), pr--;
    }
    add(dep[arr[pl]] + 1, -1);
    return ret;
}

void dfs(int u) {
    vis[u] = 1, ans += work(u, 0, 0);
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (vis[v]) continue;
        ans -= work(v, e[i].val, 1), rt = 0, findrt(v, 0, sz[v]), dfs(rt);
    }
}

struct OI {
    int RP, score;
} FJOI2021;

signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    maxsz[0] = INF, fr(n), fr(m), fr(k);
    for (int i = 2, x, y; i <= n; i++) fr(x), fr(y), adde(x, i, y), adde(i, x, y);
    findrt(1, 0, n), dfs(rt), printf("%lld\n", ans);
    return 0;
}