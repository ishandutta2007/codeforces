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
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 123456, logN = 17, K = 500;
const double eps = 1e-6;

set <int> adj[N];
int depth[N];

void dfs(int v, int pa) {
    depth[v] = ~pa ? depth[pa] + 1 : 0;
    for (int u : adj[v]) if (u ^ pa) {
        dfs(u, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    fop (i,0,n - 1) {
        cin >> u >> v, u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    if (m == 1) {
        cin >> u;
        cout << u << endl << 0 << endl;
        return 0;
    }
    vector <bool> on(n, false);
    fop (i,0,m) cin >> u, u--, on[u] = true;
    queue <int> q;
    fop (i,0,n) if (adj[i].size() == 1) q.push(i);
    int edge = n - 1;
    while (q.size() && edge) {
        v = q.front(); q.pop();
        if (!on[v]) {
            u = *adj[v].begin();
            adj[u].erase(v);
            adj[v].clear();
            edge--;
            if (adj[u].size() == 1) q.push(u);
        }
    }
    v = 0;
    while (adj[v].empty()) v++;
    dfs(v, 0);
    v = max_element(depth, depth + n) - depth;
    dfs(v, -1);
    cout << min(v, int(max_element(depth, depth + n) - depth)) + 1 << endl;
    cout << edge * 2 - *max_element(depth, depth + n) << endl;
}