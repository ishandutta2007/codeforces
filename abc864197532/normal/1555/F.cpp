#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300001, logN = 20, K = 15;

int dsu[N];

int Find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = Find(dsu[x]);
}

struct edge {
    int u, v, w, id;
};

vector <pii> adj[N];
int sz[N], pt[N], par[N], hd[N], dep[N], id[N], xorr[N], _id = 0;
bool vis[N];

void dfs1(int v, int pa) {
    vis[v] = true;
    sz[v] = 1;
    pt[v] = -1;
    par[v] = pa;
    for (auto [u, w] : adj[v]) if (u != pa) {
        xorr[u] = xorr[v] ^ w;
        dep[u] = dep[v] + 1;
        dfs1(u, v);
        sz[v] += sz[u];
        if (pt[v] == -1 || sz[pt[v]] < sz[u])
            pt[v] = u;
    }
}

void dfs2(int v, int pa, int h) {
    if (v == -1)
        return;
    hd[v] = h;
    id[v] = _id++;
    dfs2(pt[v], v, h);
    for (auto [u, w] : adj[v]) if (u != pa && u != pt[v]) {
        dfs2(u, v, u);
    }
}

void build(int n) {
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        dfs1(i, -1);
        dfs2(i, -1, i);
    }
}

struct Seg {
    int l, r, m, val, lz;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), val(0), lz(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {val = max(ch[0]->val, ch[1]->val);}
    void give() {val = lz = 1;}
    void push() {
        if (!lz)
            return;
        ch[0]->give(), ch[1]->give();
    }
    void add(int a, int b) {
        if (a <= l && r <= b)
            give();
        else {
            push();
            if (a < m)
                ch[0]->add(a, b);
            if (m < b)
                ch[1]->add(a, b);
            pull();
        }
    }
    int query(int a, int b) {
        if (a >= b)
            return 0;
        if (a <= l & r <= b)
            return val;
        push();
        if (a < m && ch[0]->query(a, b))
            return 1;
        if (m < b && ch[1]->query(a, b))
            return 1;
        return 0;
    }
};

Seg* root;

int query(int u, int v) {
    while (hd[u] != hd[v]) {
        if (dep[hd[u]] < dep[hd[v]])
            swap(u, v);
        if (root->query(id[hd[u]], id[u] + 1))
            return 1;
        u = par[hd[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    if (root->query(id[v] + 1, id[u] + 1))
        return 1;
    return 0;
}

void modify(int u, int v) {
    while (hd[u] != hd[v]) {
        if (dep[hd[u]] < dep[hd[v]])
            swap(u, v);
        root->add(id[hd[u]], id[u] + 1);
        u = par[hd[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    root->add(id[v] + 1, id[u] + 1);
}

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <bool> ans(q, false);
    vector <edge> oth;
    iota(dsu, dsu + n, 0);
    for (int i = 0, u, v, w; i < q; ++i) {
        cin >> u >> v >> w, --u, --v;
        if (Find(u) == Find(v))
            oth.pb({u, v, w, i});
        else
            dsu[Find(u)] = Find(v), adj[u].eb(v, w), adj[v].eb(u, w), ans[i] = true;
    }
    build(n);
    root = new Seg(0, n);
    for (edge e : oth) {
        if (!query(e.u, e.v) && (xorr[e.u] ^ xorr[e.v] ^ e.w)) {
            modify(e.u, e.v);
            ans[e.id] = true;
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }
}