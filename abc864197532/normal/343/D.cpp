#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17;

struct Seg {
    int l, r, m;
    int sum, addTag;
    Seg* ch[2];
    Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
        sum = 0;
        addTag = -1;
        if (r - l != 1) {
            ch[0] = new Seg (l, m);
            ch[1] = new Seg (m, r);
            pull();
        }
    }
    int size() {return r - l;}
    void pull() {sum = ch[0]->sum + ch[1]->sum;}
    void addValue(int v) {sum = v * size();};
    void push() {
        if (~addTag) {
            if (r - l != 1) {
                ch[0]->addValue(addTag);
                ch[0]->addTag = addTag;
                ch[1]->addValue(addTag);
                ch[1]->addTag = addTag;
            }
            addTag = -1;
        }
    }
    int query(int a, int b) {
        if (a <= l and r <= b) return sum;
        push();
        int ans = 0;
        if (a < m) ans += ch[0]->query(a,b);
        if (m < b) ans += ch[1]->query(a,b);
        return ans;
    }
    void add(int a, int b, int v) {
        if (a >= b) return;
        if (a <= l and r <= b) {
            addValue(v);
            addTag = v;
        } else {
            push();
            if (a < m) ch[0]->add(a,b,v);
            if (m < b) ch[1]->add(a,b,v);
            pull();
        }
    }
};

vector <int> adj[N];
vector <int> pt(N, -1), sz(N, 1), idx(N, -1), hd(N, -1), par(N, -1), depth(N);
int _id = 0;

Seg root(0, N);

void dfs(int v = 0, int pa = -1) {
    par[v] = pa;
    depth[v] = ~pa ? depth[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
            dfs(u, v);
            sz[v] += sz[u];
            if (pt[v] == -1 || sz[pt[v]] < sz[u]) pt[v] = u;
        }
}

void hld(int v = 0, int pa = -1, int h = 0) {
    if (v == -1) return;
    idx[v] = _id++;
    hd[v] = h;
    hld(pt[v], v, h);
    for (int u : adj[v]) if (u != pa && u != pt[v]) {
        hld(u, v, u);
    }
}

void modify(int u, int v) {
    while (hd[u] != hd[v]) {
        if (depth[hd[u]] < depth[hd[v]]) swap(u, v);
        root.add(idx[hd[u]], idx[u] + 1, 0);
        u = par[hd[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    root.add(idx[u], idx[v] + 1, 0);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v, q;
    cin >> n;
    fop (i,0,n - 1) {
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    hld();
    cin >> q;
    while (q--) {
        cin >> u >> v; v--;
        if (u == 1) {
            root.add(idx[v], idx[v] + sz[v], 1);
        } else if (u == 2) {
            modify(0, v);
        } else {
            cout << root.query(idx[v], idx[v] + 1) << endl;
        }
    }
}