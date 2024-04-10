#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000005, logN = 17, K = 90002;

set <int> adj[N];
vector <int> path;
bool vis[N] = {};

void dfs(int v) {
    vis[v] = true;
    while (adj[v].size()) {
        int u = *adj[v].begin(); adj[v].erase(adj[v].begin());
        adj[u].erase(v);
        dfs(u);
    }
    path.pb(v);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    fop (i,0,m) {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    fop (i,1,n + 1) if (adj[i].size() & 1) adj[i].insert(0), adj[0].insert(i);
    vector <pii> ans;
    vector <int> del[n + 1];
    fop (i,0,n + 1) if (!vis[i]) {
        dfs(i);
        reverse(all(path));
        vector <pii> ok;
        fop (i,1,path.size()) {
            if (i & 1) {
                ok.eb(path[i - 1], path[i]);
            } else {
                if (path[i] && path[i - 1]) {
                    del[path[i - 1]].pb(path[i]);
                    del[path[i]].pb(path[i - 1]);
                }
            }
        }
        for (pii i : ok) {
            if (!i.X || !i.Y) i = mp(i.X + i.Y, del[i.X + i.Y].back());
            if (i.X > i.Y) swap(i.X, i.Y);
            ans.eb(i);
        }
        path.clear();
    }
    reverse(all(ans));
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    cout << ans.size() << endl;
    for (pii A : ans) cout << A.X << ' ' << A.Y << endl;
}