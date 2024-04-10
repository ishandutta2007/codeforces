/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300001, logN = 20, K = 111;

vector <int> adj[N];
int pt[N], sz[N], id[N], hd[N], par[N], dep[N], _t;

struct Seg {
    int l, r, m, cnt, sum;
    bool is;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), is(false), cnt(0), sum(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {
        if (r - l == 1) sum = is ? 1 : 0;
        else sum = (ch[0]->cnt ? 0 : ch[0]->sum) + (ch[1]->cnt ? 0 : ch[1]->sum);
    }
    void chg(int p) {
        if (r - l == 1) {
            if (is) is = false;
            else is = true;
        } else ch[p >= m]->chg(p);
        pull();
    }
    void modify(int a, int b, int v) {
        if (a <= l && r <= b) cnt += v;
        else {
            if (a < m) ch[0]->modify(a, b, v);
            if (m < b) ch[1]->modify(a, b, v);
        }
        pull();
    }
};

Seg* root;

void dfs(int v = 0, int pa = -1) {
    sz[v] = 1;
    par[v] = pa;
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
    _t = 0;
    dfs(0, -1);
    hld(0, -1, 0);
}

void modify (int u, int v, int x) {
    while (hd[u] != hd[v]) {
        if (dep[hd[u]] < dep[hd[v]]) swap(u, v);
        root->modify(id[hd[u]], id[u] + 1, x);
        // from id[hd[u]] to id[u] + 1
        u = par[hd[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    // from id[u] to id[v] + 1
    root->modify(id[u], id[v] + 1, x);
}

void solve() {
    int n;
    cin >> n;
    vector <vector <int>> adj1(n);
    for (int i = 1, v; i < n; ++i) {
        cin >> v, --v;
        adj1[v].pb(i);
    }
    vector <int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i], --p[i];
        adj[p[i]].pb(i);
    }
    build();
    root = new Seg(0, n);
    int ans = 0;
    function<void(int, int)> dfs = [&](int v, int pa) {
        if (v) modify(0, p[v], 1);
        root->chg(id[v]);
        ans = max(ans, root->sum);
        for (int u : adj1[v]) {
            dfs(u, v);
        }
        if (v) modify(0, p[v], -1);
        root->chg(id[v]);
    };
    dfs(0, -1);
    cout << ans << endl;
    for (int i = 0; i < n; ++i) adj[i].clear();
    delete root;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}