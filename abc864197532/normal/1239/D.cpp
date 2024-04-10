#include <bits/stdc++.h>
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
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000004, logN = 18, K = 500, C = 100;

vector <int> adj[N], radj[N];
int scc[N], _id = 0;
bool vis[N];
vector <int> order;

void rdfs(int v) {
    vis[v] = true;
    for (int u : radj[v]) if (!vis[u]) {
        rdfs(u);
    }
    order.push_back(v);
}

void dfs(int v) {
    scc[v] = _id;
    for (int u : adj[v]) if (scc[u] == -1) {
        dfs(u);
    }
}

void run(int n) {
    _id = 0;
    order.clear();
    for (int i = 0; i < n; ++i) {
        vis[i] = false;
        scc[i] = -1;
    }
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        rdfs(i);
    }
    reverse(order.begin(), order.end());
    for (int v : order) {
        if (scc[v] == -1) {
            dfs(v);
            _id++;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        fop (i,0,m) {
            int u, v;
            cin >> u >> v, u--, v--;
            adj[u].pb(v);
            radj[v].pb(u);
        }
        run(n);
        if (_id == 1) {
            cout << "No\n";
        } else {
            vector <int> ans[2];
            fop (i,0,n) ans[scc[i] != 0].pb(i + 1);
            cout << "Yes\n" << ans[0].size() << ' ' << ans[1].size() << endl;
            printv(ans[0]);
            printv(ans[1]);
        }
        fop (i,0,n) adj[i].clear(), radj[i].clear();
    }
}