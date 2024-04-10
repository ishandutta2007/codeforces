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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 111;

struct Seg {
    int l, r, m;
    lli sum;
    Seg *ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), sum(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {sum = ch[0]->sum + ch[1]->sum;}
    void upd(int p, int v) {
        if (r - l == 1)
            sum = v;
        else {
            ch[p >= m]->upd(p, v);
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b)
            return sum;
        lli ans = 0;
        if (a < m)
            ans += ch[0]->query(a, b);
        if (m < b)
            ans += ch[1]->query(a, b);
        return ans;
    }
};

Seg *root;

vector <int> adj[N];
int id[N], hd[N], dep[N], pt[N], sz[N], par[N], _t;

void dfs(int v, int pa) {
    par[v] = pa;
    sz[v] = 1;
    pt[v] = -1;
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        if (pt[v] == -1 || sz[pt[v]] < sz[u]) {
            pt[v] = u;
        }
        sz[v] += sz[u];
    }
}

void dfs2(int v, int pa, int h) {
    if (v == -1)
        return;
    hd[v] = h;
    id[v] = _t++;
    dfs2(pt[v], v, h);
    for (int u : adj[v]) if (u != pt[v] && u != pa) {
        dfs2(u, v, u);
    }
}

vector <int> a;

lli query(int u, int v) {
    lli ans = 0;
    while (hd[u] != hd[v]) {
        if (dep[hd[u]] < dep[hd[v]])
            swap(u, v);
        ans += root->query(id[hd[u]], id[u] + 1) * 2 - a[hd[u]] - a[u];
        ans += a[hd[u]] + a[par[hd[u]]];
        u = par[hd[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    ans += root->query(id[u], id[v] + 1) * 2 - a[u] - a[v];
    return ans;
}

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], a[i] = abs(a[i]);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    dfs2(0, -1, 0);
    root = new Seg(0, n);
    for (int i = 0; i < n; ++i) {
        root->upd(id[i], a[i]);
    }
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v, --u;
        if (t == 1) {
            a[u] = abs(v);
            root->upd(id[u], a[u]);
        } else {
            --v;
            cout << query(u, v) << '\n';
        }
    }
}