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
const int mod = 1e9 + 7, x = 864197532, N = 1000000, logN = 17;

struct Dsu {
    int n;
    vector <int> dsu, size;
    Dsu (int n): n(n) {
        dsu.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int Find(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = Find(dsu[a]);
    }
    bool Union(int a, int b) {
        int x = Find(a), y = Find(b);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        dsu[y] = x;
        size[x] += size[y];
        size[y] = 0;
        return true;
    }
};

vector <int> adj[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), p(n);
    fop (i,0,n) cin >> a[i];
    fop (i,0,n - 1) {
        int u, v;
        cin >> u >> v; u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return a[i] < a[j];
    });
    lli ans = 0;
    vector <bool> vis(n, false);
    Dsu dsu1(n), dsu2(n);
    fop (i,0,n) {
        int v = p[i], all = 1;
        for (int u : adj[v]) if (vis[u]) {
                ans -= 1ll * a[v] * dsu1.size[dsu1.Find(u)] * dsu1.size[dsu1.Find(u)];
                all += dsu1.size[dsu1.Find(u)];
                dsu1.Union(u, v);
            }
        ans += 1ll * a[v] * all * all;
        vis[v] = true;
    }
    vis.assign(n, false);
    sort(all(p), [&](int i, int j) {
        return a[i] > a[j];
    });
    fop (i,0,n) {
        int v = p[i], all = 1;
        for (int u : adj[v]) if (vis[u]) {
                ans += 1ll * a[v] * dsu2.size[dsu2.Find(u)] * dsu2.size[dsu2.Find(u)];
                all += dsu2.size[dsu2.Find(u)];
                dsu2.Union(u, v);
            }
        ans -= 1ll * a[v] * all * all;
        vis[v] = true;
    }
    cout << ans / 2 << endl;
}