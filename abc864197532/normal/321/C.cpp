#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087;

vector <int> adj[N];
vector <int> sz(N, 0), cdt_pa(N, -1), cdt_depth(N, -1);

void dfs_sz(int v, int pa) {
    sz[v] = 1;
    for (int u : adj[v]) if (cdt_pa[u] == -1 and u != pa) {
        dfs_sz(u, v);
        sz[v] += sz[u];
    }
}

int dfs_fc(int v, int pa, int n) {
    int ans = -1;
    for (int u : adj[v]) if (u != pa) {
        if (cdt_pa[u] == -1 and sz[u] > n / 2) {
            return dfs_fc(u, v, n);
        }
    }
    return v;
}

void cd(int v, int pa) {
    dfs_sz(v, pa);
    int k = dfs_fc(v, pa, sz[v]);
    cdt_pa[k] = ~pa ? pa : k;
    cdt_depth[k] = ~pa ? cdt_depth[pa] + 1 : 0;
    for (int u : adj[k]) if (cdt_pa[u] == -1) {
        cd(u, k);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    fop (i,0,n - 1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cd(0, -1);
    fop (i,0,n) cout << char(cdt_depth[i] + 'A') << ' ';
    cout << '\n';
    return 0;
}