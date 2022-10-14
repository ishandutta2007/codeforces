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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17, K = 500;

vector <int> adj[N];
int depth[N], p[N];

void dfs(int v = 0, int pa = -1) {
    depth[v] = ~pa ? depth[pa] + 1 : 0;
    p[v] = pa;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    fop (i,0,n - 1) {
        cin >> u >> v; u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs();
    vector <bool> vis(n, false);
    vector <int> po(n);
    iota(all(po), 0);
    sort(all(po), [&](int i, int j) {
        return depth[i] > depth[j];
    });
    int ans = 0;
    fop (i,0,n) if (!vis[po[i]] && depth[po[i]] > 2) {
        int pp = p[po[i]];
        for (int u : adj[pp]) {
            vis[u] = true;
        }
        vis[pp] = true;
        ans++;
    }
    cout << ans << endl;
}