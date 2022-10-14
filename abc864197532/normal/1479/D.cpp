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
const int mod = 1e9 + 7, abc = 864197532, N = 300000, logN = 18, M = 2e7;
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

int rnd() {return uniform_int_distribution<int>(1, 65535)(rng);}

struct Seg {
    static Seg mem[M], *pt;
    int l, r, m, hash1, hash2, x, y;
    Seg* ch[2];
    Seg () = default;
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), x(rnd()), y(rnd()) {
        if (r - l > 1) {
            ch[0] = new (pt++) Seg(l, m);
            ch[1] = new (pt++) Seg(m, r);
            pull();
        } else {
            hash1 = hash2 = 0;
        }
    }
    void pull() {
        hash1 = (1ll * ch[0]->hash1 * x + 1ll * ch[1]->hash1 * y) % mod;
        hash2 = (1ll * ch[0]->hash2 * y + 1ll * ch[1]->hash2 * x) % mod;
    }
    Seg* modify(int p, int v) {
        Seg *now = new (pt++) Seg(*this);
        if (r - l == 1) {
            now->hash1 = now->hash2 = v;
        } else {
            now->ch[p >= m] = now->ch[p >= m]->modify(p, v);
            now->pull();
        }
        return now;
    }
    int query(int p) {
        if (r - l == 1) return hash1;
        return ch[p >= m]->query(p);
    }
} Seg::mem[M], *Seg::pt = mem;

vector <int> adj[N];
vector <Seg*> roots;
int in[N], out[N], jump[N][logN], cnt[N], a[N], _t = 0;

void dfs(int v, int pa) {
    in[v] = _t++;
    jump[v][0] = pa;
    cnt[a[v]] ^= 1;
    roots.pb(roots.back()->modify(a[v], cnt[a[v]]));
    cout << endl;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
    out[v] = _t++;
    cnt[a[v]] ^= 1;
    roots.pb(roots.back()->modify(a[v], cnt[a[v]]));
}

void build() {
    for (int i = 0; i < N; ++i) for (int j = 0; j < logN; ++j) jump[i][j] = -1;
    dfs(0, -1);
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i < N; ++i) {
            int k = jump[i][j - 1];
            if (~k) jump[i][j] = jump[k][j - 1];
        }
    }
}

bool anc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;
    for (int i = logN - 1; ~i; --i) {
        int k = jump[u][i];
        if (~k && !anc(k, v)) u = k;
    }
    return jump[u][0];
}

int query(Seg *tl, Seg *tr, int a, int b, int l, int r) {
    int m = l + r >> 1;
    if (a <= l && r <= b) {
        if (tl->hash1 == tr->hash1 && tl->hash2 == tr->hash2) return -1;
        if (r - l == 1) return l;
        if (tl->ch[0]->hash1 == tr->ch[0]->hash1 && tl->ch[0]->hash2 == tr->ch[0]->hash2) {
            return query(tl->ch[1], tr->ch[1], a, b, m, r);
        }
        return query(tl->ch[0], tr->ch[0], a, b, l, m);
    } else {
        if (a < m) {
            int res = query(tl->ch[0], tr->ch[0], a, b, l, m);
            if (res != -1) return res;
        }
        if (m < b) {
            int res = query(tl->ch[1], tr->ch[1], a, b, m, r);
            if (res != -1) return res;
        }
        return -1;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, u, v, l, r;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    roots.pb(new (Seg::pt++) Seg(0, n));
    build();
    while (q--) {
        cin >> u >> v >> l >> r, --u, --v, --l;
        int k = lca(u, v);
        Seg *tl, *tr;
        if (k == u) {
            tl = roots[in[u]], tr = roots[in[v] + 1];
        } else if (k == v) {
            tl = roots[in[v]], tr = roots[in[u] + 1];
        } else {
            if (in[u] > in[v]) swap(u, v);
            int t = roots[in[v] + 1]->query(a[k]);
            tl = roots[out[u]], tr = roots[in[v] + 1]->modify(a[k], t ^ 1);
        }
        int ans = query(tl, tr, l, r, 0, n);
        cout << (~ans ? ans + 1 : -1) << '\n';
    }
}