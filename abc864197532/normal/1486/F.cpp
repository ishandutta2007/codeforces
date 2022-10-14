#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 300101, logN = 19, K = 333, INF = 5e8;

vector <int> adj[N];
int pt[N], sz[N], id[N], hd[N], par[N], dep[N], _t, jump[N][logN];

void dfs(int v = 0, int pa = -1) {
    sz[v] = 1;
    par[v] = jump[v][0] = pa;
    pt[v] = -1;
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        sz[v] += sz[u];
        if (pt[v] == -1 || sz[pt[v]] < sz[u]) pt[v] = u;
    }
}

void hld(int v, int pa, int h) {
    if (!~v) return;
    id[v] = _t++;
    hd[v] = h;
    hld(pt[v], v, h);
    for (int u : adj[v]) if (u != pa && u != pt[v]) {
        hld(u, v, u);
    }
}

void build() {
    for (int j = 0; j < logN; ++j) {
        for (int i = 0; i < N; ++i) {
            jump[i][j] = -1;
        }
    }
    _t = 0;
    dfs(0, -1);
    hld(0, -1, 0);
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i < N; ++i) {
            int k = jump[i][j - 1];
            if (~k) jump[i][j] = jump[k][j - 1];
        }
    }
}

int lca(int u, int v) {
    while (hd[u] != hd[v]) {
        if (dep[hd[u]] < dep[hd[v]]) swap(u, v);
        u = par[hd[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    return u;
}

void modify(int u, int v, vector <int> &pre) {
    while (hd[u] != hd[v]) {
        if (dep[hd[u]] < dep[hd[v]]) swap(u, v);
        pre[id[hd[u]]]++;
        pre[id[u] + 1]--;
        u = par[hd[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    pre[id[u]]++;
    pre[id[v] + 1]--;
}

int under(int u, int v) {
    for (int k = logN - 1; ~k; --k) {
        if (dep[u] - dep[v] - 1 >> k & 1) {
            u = jump[u][k];
        }
    }
    return u;
}

struct path {
    int u, v, k, su, sv;
    bool line;
    path (int _u, int _v) : u(_u), v(_v) {
        k = lca(u, v);
        if (k == u || k == v) {
            line = true;
            if (k == u) swap(u, v);
            su = under(u, v);
        } else {
            line = false;
            su = under(u, k);
            sv = under(v, k);
        }
    }
};

pii get(int u, int v) {
    if (u < v) swap(u, v);
    return mp(u, v);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    build();
    cin >> m;
    vector <int> pre1(n + 1, 0), pre2(n + 1, 0), cnt(n, 0), cnt2(n, 0);
    vector <path> paths;
    map <pii, int> m1;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        if (u == v) {
            cnt[u]++;
            continue;
        }
        path now = path(u, v);
        if (now.line) {
            modify(now.u, now.v, pre1);
            modify(now.u, now.su, pre2);
            cnt2[now.su]++;
        } else {
            modify(now.u, now.v, pre1);
            modify(now.u, now.su, pre2);
            modify(now.v, now.sv, pre2);
            m1[get(now.su, now.sv)]++;
            cnt2[now.su]++;
            cnt2[now.sv]++;
        }
        paths.pb(now);
    }
    for (int i = 1; i <= n; ++i) pre1[i] += pre1[i - 1], pre2[i] += pre2[i - 1];
    lli ans = 0;
    vector <int> cnt3(n, 0);
    for (path &i : paths) {
        ans -= cnt3[i.k];
        cnt3[i.k]++;
        if (i.line) {
            ans += pre1[id[i.k]] - pre2[id[i.su]];
        } else {
            ans += pre1[id[i.k]] - pre2[id[i.su]] - pre2[id[i.sv]] + m1[get(i.su, i.sv)];
        }
    }
    for (int i = 0; i < n; ++i) {
        ans += 1ll * cnt[i] * pre1[id[i]] + 1ll * cnt[i] * (cnt[i] - 1) / 2;
    }
    for (int i = 0; i < n; ++i) {
        ans += 1ll * cnt2[i] * (cnt2[i] - 1) / 2;
    }
    for (auto A : m1) {
        ans -= 1ll * A.Y * (A.Y - 1) / 2;
    }
    cout << ans << endl;
}