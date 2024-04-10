#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 18, K = 500, C = 1 << 20;

vector <int> adj[N];
vector <int> bcc[N];
bool cut[N]{}, vis[N]{};
int dep[N], low[N], _id1 = 0;
stack <int> stk;

void dfs1(int v, int pa) {
    dep[v] = low[v] = ~pa ? dep[pa] + 1 : 0;
    stk.push(v);
    vis[v] = true;
    int ch = 0;
    for (int u : adj[v]) if (u != pa) {
        if (vis[u]) {
            low[v] = min(low[v], dep[u]);
        } else {
            dfs1(u, v);
            low[v] = min(low[v], low[u]);
            ch++;
            if (low[u] >= dep[v]) {
                cut[v] = true;
                int x;
                do {
                    x = stk.top(); stk.pop();
                    bcc[x].push_back(_id1);
                } while (x != u);
                bcc[v].push_back(_id1++);
            }
        }
    }
    if (pa == -1 && ch < 2) cut[v] = false;
}

vector <int> bct[N * 2];
int id[N * 2], hd[N * 2], dep2[N * 2], par[N * 2], sz[N * 2], pt[N * 2], va[N], _id2 = 0;
multiset <int> s[N];

struct Seg {
    int l, r, m, va;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), va(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {va = min(ch[0]->va, ch[1]->va);}
    void modify(int p, int v) {
        if (r - l == 1) va = v;
        else {
            ch[p >= m]->modify(p, v);
            pull();
        }
    }
    int query(int a, int b) {
        if (a <= l && r <= b) return va;
        int ans = 1 << 30;
        if (a < m) ans = min(ans, ch[0]->query(a, b));
        if (m < b) ans = min(ans, ch[1]->query(a, b));
        return ans;
    }
} root(0, N * 2);

void build() {
    for (int v = 0; v < N; ++v) if (cut[v]) {
        for (int i : bcc[v]) {
            bct[v].push_back(i + N);
            bct[i + N].push_back(v);
        }
    }
    for (int i = 0; i < N * 2; ++i) par[i] = -1;
}

void dfs2(int v, int pa) {
    par[v] = pa;
    dep2[v] = ~pa ? dep2[pa] + 1 : 0;
    pt[v] = -1;
    sz[v] = 1;
    for (int u : bct[v]) if (u != pa) {
        dfs2(u, v);
        if (pt[v] == -1 || sz[pt[v]] < sz[u]) {
            pt[v] = u;
        }
        sz[v] += sz[u];
    }
}

void hld(int v, int pa, int h) {
    if (v == -1) return;
    id[v] = _id2++;
    hd[v] = h;
    hld(pt[v], v, h);
    for (int u : bct[v]) if (u != pa && u != pt[v]) {
        hld(u, v, u);
    }
}

int lca(int v, int u) {
    while (hd[v] != hd[u]) {
        if (dep2[hd[v]] < dep2[hd[u]]) swap(v, u);
        v = par[hd[v]];
    }
    if (dep2[v] > dep2[u]) swap(u, v);
    return v;
}

int query(int v, int u) {
    int ans = 1 << 30;
    int k = lca(u, v);
    if (k >= N && par[k] != -1) {
        ans = va[par[k]];
    }
    while (hd[v] != hd[u]) {
        if (dep2[hd[v]] < dep2[hd[u]]) swap(v, u);
        ans = min(ans, root.query(id[hd[v]], id[v] + 1));
        v = par[hd[v]];
    }
    if (dep2[u] > dep2[v]) swap(v, u);
    return min(ans, root.query(id[u], id[v] + 1));
}

void modify(int v, int x) {
    if (cut[v]) {
        if (par[v] != -1) {
            s[par[v] - N].erase(s[par[v] - N].lower_bound(va[v]));
            s[par[v] - N].insert(x);
            root.modify(id[par[v]], *s[par[v] - N].begin());
        }
        va[v] = x;
        root.modify(id[v], x);
    } else {
        s[bcc[v][0]].erase(s[bcc[v][0]].lower_bound(va[v]));
        s[bcc[v][0]].insert(x);
        root.modify(id[bcc[v][0] + N], *s[bcc[v][0]].begin());
        va[v] = x;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, u, v;
    cin >> n >> m >> q;
    fop (i,0,n) cin >> va[i];
    fop (i,0,m) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(0, -1);
    build();
    dfs2(N, -1);
    hld(N, 0, N);
    fop (i,0,n) {
        if (!cut[i]) {
            s[bcc[i][0]].insert(va[i]);
        } else {
            if (par[i] != -1) s[par[i] - N].insert(va[i]);
            root.modify(id[i], va[i]);
        }
    }
    fop (i,0,_id1) root.modify(id[i + N], *s[i].begin());
    while (q--) {
        char c;
        int u, v;
        cin >> c >> u >> v;
        if (c == 'C') {
            modify(u - 1, v);
        } else {
            u--, v--;
            if (u != v) {
                if (!cut[u]) u = bcc[u][0] + N;
                if (!cut[v]) v = bcc[v][0] + N;
                cout << query(u, v) << endl;
            } else {
                cout << va[v] << endl;
            }
        }
    }
}