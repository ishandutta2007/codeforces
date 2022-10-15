#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 300100, LOG = 20;

int n, m, p, u, v, U[MN], V[MN], num = 1, tmp[MN], id[MN], depth[MN], bl[MN][LOG], col[MN], fu, ck, good[MN];
bool vis[MN], bridge[MN];
vector<int> a[MN];
vector<pair<int, pii>> at[MN];
pii edge[MN];
pair<int, pii> q[MN];
queue<int> Q[MN];
char ans[MN];

void dfs(int cur, int par, int d) {
    bl[cur][0] = par;
    depth[cur] = d;
    for (int i = 1; i < LOG; i++) {
        bl[cur][i] = bl[bl[cur][i - 1]][i - 1];
    }
    for (auto i : at[cur]) {
        if (i.s.f == par) continue;
        dfs(i.s.f, cur, d + 1);
    }
}

int ok = 0;

void dfs1(int cur, int par, int v) {
    if (cur == id[ck] && v) ok = 1;
    for (auto nxt : at[cur]) {
        if (nxt.s.f == par) continue;
        dfs1(nxt.s.f, cur, v | nxt.f | good[nxt.s.f]);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) u = bl[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (bl[u][i] != bl[v][i]) {
            u = bl[u][i];
            v = bl[v][i];
        }
    }
    return bl[u][0];
}

int adj(int cur, int ed) { //node adj to cur with edge ed
    return U[ed] == cur ? V[ed] : U[ed];
}

int dfs(int cur, int ed) { //mark bridge
    vis[cur] = true;
    tmp[cur] = num++;
    int down = tmp[cur];
    for (int nxt : a[cur]) {
        int par = adj(cur, nxt);
        if (!vis[par]) {
            down = min(down, dfs(par, nxt));
        } else if (nxt != ed) {
            down = min(down, tmp[par]);
        }
    }
    if (down == tmp[cur] && ed != -1) {
        bridge[ed] = true;
    }
    return down;
}

void comp(int cur) { //compress cycles
    int idn = num;
    Q[idn].push(cur);
    id[cur] = idn;
    vis[cur] = true;
    while (Q[idn].size()) {
        int node = Q[idn].front();
        Q[idn].pop();
        for (int nxt : a[node]) {
            int par = adj(node, nxt);
            int colo = col[nxt];
            if (vis[par]) continue;
            if (bridge[nxt]) {
                num++;
                comp(par);
            } else {
                Q[idn].push(par);
                id[par] = idn;
                good[idn] |= colo;
                vis[par] = true;
            }
        }
    }
}

void mark(int cur, int par, int dir) {
    if (cur == par) return;
    for (auto nxt : at[cur]) {
        if (depth[nxt.s.f] > depth[cur]) continue;
        if (ans[nxt.s.s] != 'B') return;
        if (dir == nxt.f) ans[nxt.s.s] = 'R';
        else ans[nxt.s.s] = 'L';
        mark(nxt.s.f, par, dir);
    }
}

void proc(pair<int, pii> p) {
    //printf("%d %d\n", p.s.f, p.s.s);
    int par = lca(p.s.f, p.s.s);
    mark(p.s.f, par, 1);
    mark(p.s.s, par, 0);
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> col[i];
        u--; v--;
        edge[i] = {u, v};
        U[i] = u; V[i] = v;
        a[u].push_back(i);
        a[v].push_back(i);
    }
    cin >> fu >> ck;
    fu--; ck--;

    for (int i = 0; i < m; i++) {
        if (vis[i]) continue;
        dfs(i, -1);
    }

    memset(vis, 0, sizeof(vis));
    num = 1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        comp(i);
    }

    for (int i = 0; i < m; i++) {
        u = id[edge[i].f];
        v = id[edge[i].s];
        if (u == v) {good[u] |= col[i]; continue;}
        at[u].push_back({col[i], {v, i}});
        at[v].push_back({col[i], {u, i}});
        //printf("%d %d %d\n", u, v, col[i]);
    }
    //printf("%d %d\n", id[fu], id[ck]);
    dfs1(id[fu], -1, good[id[fu]]);
    if (ok) printf("YES\n");
    else printf("NO\n");

    return 0;
}