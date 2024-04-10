//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
#define int ll

const int maxn = 5e5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

struct DSU {
    vector<int> p, s;
    DSU(int n) : p(n), s(n, 1) { iota(all(p), 0); }
    int get(int v) { return p[v] == v ? v : p[v] = get(p[v]); }
    void unite(int u, int v) {
        if((u = get(u)) != (v = get(v))) {
            if(s[u] < s[v]) swap(u, v);
            p[v] = u; s[u] += s[v];
        }
    }
};
struct segTree {
    int n;
    vector<int> t;
    segTree(int n) : n(n), t(2 * n) {
        for(int i = 0; i < n; i++) t[n + i] = i;
        for(int i = n - 1; i; i--) t[i] = min(t[i * 2], t[i * 2 + 1]);
    }
    void upd(int v, int x) {
        t[v += n] = x;
        for(v >>= 1; v; v >>= 1) t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    int get(int l, int r) {
        r = min(r, n - 1);
        int ret = inf;
        for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if(l & 1) ret = min(ret, t[l]);
            if(!(r & 1)) ret = min(ret, t[r]);
        }
        return ret;
    }
};

int n, k, m, fa[maxn], fb[maxn], fw[maxn], take[maxn];
vector<int> g[maxn];
int dep[maxn], up[maxn][19], tin[maxn], tout[maxn], tik_tak;
int tsz[maxn], len[maxn], hed[maxn], id[maxn];
vector<segTree> t;
int pw[20];
vector<int> vl[maxn];

void dfs(int v, int p) {
    tin[v] = tik_tak++;
    up[v][0] = p;
    for(int i = 1; i < 19; i++) up[v][i] = up[up[v][i - 1]][i - 1];
    tsz[v] = 1;
    int kid = -1;
    for(int to : g[v]) if(to != p) {
        dep[to] = dep[v] + 1, dfs(to, v);
        tsz[v] += tsz[to];
        if(kid == -1 || tsz[kid] < tsz[to]) kid = to;
    }
    tout[v] = tik_tak++;
    hed[v] = v;
    len[v] = 1;
    if(kid != -1) hed[v] = hed[kid], len[hed[v]]++;
}
bool upper(int u, int v) {
    return tin[u] < tin[v] && tout[u] > tout[v];
}
int lca(int u, int v) {
    if(u == v) return u;
    if(tin[u] > tin[v]) swap(u, v);
    if(upper(u, v)) return u;
    for(int i = 18; i >= 0; i--)
        if(!upper(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}
DSU dsu(maxn);
int clr(segTree &t, int l, int r, vector<int> &vl) { // interval
    int ret = 0;
    int x;
    while((x = t.get(l, r)) < r) {
        t.upd(x, inf);
        dsu.unite(vl[x], up[vl[x]][0]);
        ret++;
        l = x; // ?? may be
    }
    return ret;
}
int go(int u, int v) {
    int ret = 0;
    while(hed[u] != hed[v]) {
        int pos = dep[hed[v]] - dep[v];
        ret += clr(t[id[hed[v]]], pos, inf, vl[hed[v]]);
        int d = len[hed[v]] - pos;
        for(int i = 18; i >= 0; i--)
            if(pw[i] <= d) {
                v = up[v][i];
                d -= pw[i];
            }
    }
    return ret + clr(t[id[hed[v]]], dep[hed[v]] - dep[v], dep[hed[v]] - dep[u], vl[hed[v]]);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    pw[0] = 1;
    for(int i = 1; i < 20; i++) pw[i] = pw[i - 1] + pw[i - 1];
    cin >> n >> k >> m;
    DSU pre(n);
    for(int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
        pre.unite(u, v);
    }
    for(int i = 0; i < m; i++) {
        cin >> fa[i] >> fb[i] >> fw[i];
        fa[i]--; fb[i]--;
        if(pre.get(fa[i]) != pre.get(fb[i])) {
            take[i] = 1;
            pre.unite(fa[i], fb[i]);
            g[fa[i]].pb(fb[i]);
            g[fb[i]].pb(fa[i]);
        }
    }
    dfs(0, 0);
    for(int i = 0; i < n; i++) if(hed[i] == i) id[i] = sz(t), t.emplace_back(segTree(len[i])), vl[i].resize(len[i]);
    for(int u = 0; u < n; u++) vl[hed[u]][dep[hed[u]] - dep[u]] = u;
    for(int i = 0; i < m; i++) {
        if(tin[fa[i]] > tin[fb[i]]) swap(fa[i], fb[i]);
        if(take[i]) {
            t[id[hed[fb[i]]]].upd(dep[hed[fb[i]]] - dep[fb[i]], inf);
        }
    }
    int ours = 0;
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        //cout << ours << ' ' << ans << endl;
        int u = fa[i], v = fb[i], w = fw[i];
        if(dsu.get(u) == dsu.get(v)) continue;
        if(take[i]) {
            dsu.unite(u, v);
            continue;
        }
        if(tin[u] > tin[v]) swap(u, v);
        int cnt;
        if(upper(u, v)) {
            cnt = go(u, v);
        } else {
            int o = lca(u, v);
            cnt = go(o, u) + go(o, v);
        }
        ours += cnt;
        ans += 1LL * w * cnt;
    }
    cout << (ours == k ? ans : -1);
}