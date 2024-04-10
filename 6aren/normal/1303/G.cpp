#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

 
struct CentroidDecomposition {
    int n;
    vector<vector<int>> g, gCentroid;
    vector<bool> deleted;
    vector<int> sz;
    vector<int> p;
    
    CentroidDecomposition() {
    }
 
    CentroidDecomposition(int _n) {
        n = _n;
        g.resize(n + 1); gCentroid.resize(n + 1);
        deleted.resize(n + 1);
        sz.resize(n + 1);
        p.resize(n + 1);
    }
 
    void addEdge(int u, int v) {
        g[u].pb(v);
        g[v].pb(u);
    }
 
    void calcSz(int cur, int pre) {
        sz[cur] = 1;
        for (int u : g[cur]) {
            if (u == pre) continue;
            if (deleted[u]) continue;
            calcSz(u, cur);
            sz[cur] += sz[u];
        }
    } 
 
    int findCentroid(int cur, int pre, int subtreeSize) {
        int mxSz = 0;
        for (int u : g[cur]) {
            if (u == pre) continue;
            if (deleted[u]) continue;
            if (sz[mxSz] < sz[u]) mxSz = u;
        }
        if (sz[mxSz] <= subtreeSize / 2) return cur;
        else return findCentroid(mxSz, cur, subtreeSize);
    }
 
    void buildCentroid(int cur, int parent) {
        calcSz(cur, 0);
        int centroid = findCentroid(cur, 0, sz[cur]);
        gCentroid[parent].pb(centroid);
        p[centroid] = parent;
        deleted[centroid] = 1;
        for (int e : g[centroid]) {
            if (!deleted[e]) buildCentroid(e, centroid);
        }
    }
 
    void work() {
        buildCentroid(1, 0);
    }
} cd;

#define ll long long
 
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        if (empty()) return 0;
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
} cht;

const int N = 150005;

vector<int> g[N];
int n, a[N];
long long ans = 0;
bool deleted[N];
stack<pair<long long, long long>> st;

void dfs(int u, int p, int cur, int sum, int sum2, int dep, int root) {
    cur = cur + a[u];
    sum += cur;
    sum2 += (dep + 1) * a[u];
    st.push({cur, sum2 - cur});
    ans = max(ans, sum);
    ans = max(ans, sum2);
    int foo = sum - (dep + 1) * root;
    // cout << u << ' ' << foo << endl;
    ans = max(ans, foo + cht.query(dep + 1));
    for (int e : g[u]) {
        if (e == p) continue;
        if (deleted[e]) continue;
        dfs(e, u, cur, sum, sum2, dep + 1, root);
    }
}

void solve(int u) {
    cht.clear();
    deleted[u] = 1;
    for (int e : g[u]) {
        if (!deleted[e]) {
            dfs(e, u, a[u], a[u], a[u], 1, a[u]);
            while (!st.empty()) {
                ii foo = st.top();
                st.pop();
                cht.add(foo.x, foo.y);
            }
        }
    }
    reverse(all(g[u]));
    cht.clear();
    for (int e : g[u]) {
        if (!deleted[e]) {
            dfs(e, u, a[u], a[u], a[u], 1, a[u]);
            while (!st.empty()) {
                ii foo = st.top();
                st.pop();
                cht.add(foo.x, foo.y);
            }
        }
    }
    for (int e : cd.gCentroid[u]) {
        solve(e);
    }
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    cd = CentroidDecomposition(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        cd.addEdge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cd.work();
    int root = cd.gCentroid[0][0];
    solve(root);
    cout << ans;
    return 0;
}