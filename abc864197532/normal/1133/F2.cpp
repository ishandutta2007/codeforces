#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
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
const int mod = 1e9 + 7, x = 864197532, N = 200005, logN = 18, K = 600, C = 100, M = 1e9;

vector <int> adj[N];

int dsu[N];

void init() {
    fop (i,0,N) dsu[i] = i;
}

int Find(int x) {
    if (x == dsu[x]) return x;
    return dsu[x] = Find(dsu[x]);
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;
    dsu[u] = v;
    return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, d;
    cin >> n >> m >> d;
    init();
    vector <bool> has_edge(n, false);
    fop (i,0,m) {
        cin >> u >> v, u--, v--;
        if (u == 0 || v == 0) {
            has_edge[u | v] = true;
        } else {
            Union(u, v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    vector <pii> now;
    fop (i,0,n) if (has_edge[i]) {
        if (Find(i) != Find(0)) {
            Union(0, i);
            adj[i].pb(0);
            adj[0].pb(i);
            has_edge[i] = false;
        }
    }
    fop (i,0,n) if (has_edge[i] && adj[0].size() < d) {
        adj[0].pb(i);
        adj[i].pb(0);
    }
    if (adj[0].size() != d) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    queue <int> q;
    q.push(0);
    vector <bool> vis(n, false);
    vis[0] = true;
    while (q.size()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) if (!vis[u]) {
            vis[u] = true;
            q.push(u);
            cout << u + 1 << ' ' << v + 1 << endl;
        }
    }
}