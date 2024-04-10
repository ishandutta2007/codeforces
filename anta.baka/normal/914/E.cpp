#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 2e5, INF = 1e9;

int n, ch[maxn], mask[maxn], bou[maxn], dep[maxn], szeu, lg[2 * maxn + 1], pr[maxn];
vector<int> g[maxn], eu;
pair<int, int> t[2 * maxn][19];

void dfs(int v, int p) {
    pr[v] = p;
    bou[v] = sz(eu);
    eu.push_back(v);
    for(int to : g[v]) if(to != p) {
        mask[to] = mask[v] ^ (1 << ch[to]);
        dep[to] = dep[v] + 1; dfs(to, v);
        eu.push_back(v);
    }
}

inline int lca(int u, int v) {
    int l = bou[u], r = bou[v];
    if(l > r) swap(l, r);
    int x = lg[r - l + 1];
    return min(t[l][x], t[r - (1 << x) + 1][x]).second;
}

int tsz[maxn], ban[maxn], anc[maxn];

void calc_sz(int v, int p) {
    tsz[v] = 1;
    for(int to : g[v]) if(to != p && !ban[to]) {
        calc_sz(to, v); tsz[v] += tsz[to];
    }
}

int get_c(int v, int p, int n) {
    for(int to : g[v]) if(to != p && !ban[to] && 2 * tsz[to] >= n) return get_c(to, v, n);
    return v;
}

vector<int> vec[maxn], ct[maxn];

void build(int v, int p) {
    calc_sz(v, -1);
    int n = tsz[v];
    v = get_c(v, -1, n);
    ban[v] = 1;
    anc[v] = p;
    vec[v].reserve(n);
    if(p != -1) ct[p].push_back(v);
    for(int to : g[v]) if(!ban[to]) build(to, v);
}

inline int get_mask(int u, int v) {
    int w = lca(u, v);
    return (mask[u] ^ mask[v] ^ (1 << ch[w]));
}

ll ans[maxn], add[maxn], sub[maxn];

inline void add_path(int u, int v, ll x) {
    //cout << u + 1 << ' ' << v + 1 << ' ' << x << endl;
    if(dep[u] > dep[v]) swap(u, v);
    int w = lca(u, v);
    if(w == u) {
        add[v] += x;
        if(pr[u] != -1) add[pr[u]] -= x;
    } else {
        add[u] += x;
        add[v] += x;
        add[w] -= x;
        if(pr[w] != -1) add[pr[w]] -= x;
    }
}

void dfs1(int v, int p) {
    ans[v] = add[v];
    for(int to : g[v]) if(to != p) {
        dfs1(to, v); ans[v] += ans[to];
    }
}

int cnt[1048576], msk[maxn], cnt1[1048576];

void dfs_ct1(int v) {
    cnt1[msk[v]]++;
    for(int to : ct[v]) dfs_ct1(to);
}

void dfs_ct2(int v) {
    cnt1[msk[v]]--;
    for(int to : ct[v]) dfs_ct2(to);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        char x; cin >> x; ch[i] = x - 'a';
    }
    eu.reserve(2 * n);
    dfs(0, -1);
    szeu = sz(eu);
    for(int i = 2; i <= szeu; i++) lg[i] = lg[i >> 1] + 1;
    for(int i = 0; i < szeu; i++) t[i][0] = {dep[eu[i]], eu[i]};
    for(int j = 1; j < 19; j++)
        for(int i = 0; i + (1 << j) - 1 < szeu; i++)
            t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
    build(0, -1);

    for(int u = 0; u < n; u++) {
        int v = u;
        while(v != -1) {
            vec[v].push_back(u);
            v = anc[v];
        }
    }

    for(int v = 0; v < n; v++) {
        for(int u : vec[v]) {
            msk[u] = get_mask(u, v);
            cnt[msk[u]]++;
        }
        {
            int m = msk[v] ^ (1 << ch[v]);
            ll tot = cnt[m];
            for(int i = 0; i < 20; i++) tot += cnt[m ^ (1 << i)];
            add_path(v, v, tot);
            sub[v] += tot;
        }
        for(int o : ct[v]) {
            dfs_ct1(o);
            for(int u : vec[o]) {
                int m = msk[u] ^ (1 << ch[v]);
                ll tot = cnt[m] - cnt1[m];
                for(int i = 0; i < 20; i++) tot += cnt[m ^ (1 << i)] - cnt1[m ^ (1 << i)];
                add_path(u, v, tot);
                sub[v] += tot;
            }
            dfs_ct2(o);
        }
        for(int u : vec[v]) cnt[msk[u]]--;
    }

    dfs1(0, -1);
    for(int i = 0; i < n; i++) cout << ans[i] - sub[i] / 2  << ' ';
}