#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6;
const ll INF = 1e18;
using ld = double;
#define x first
#define y second

int n, q;
vector<pair<int, ll>> g[maxn];
vector<int> path, cur;
ll dist[maxn];

void dfs0(int v, int p) {
    cur.push_back(v);
    if(v == n - 1) path = cur;
    for(auto e : g[v]) if(e.x != p) dist[e.x] = dist[v] + e.y, dfs0(e.x, v);
    cur.pop_back();
}

ll dep[maxn];
int was[maxn], any, curs;

void dfs1(int v) {
    curs++;
    for(auto e : g[v])
        if(!was[e.x]) {
            was[e.x] = 1;
            dep[e.x] = dep[v] + e.y;
            dfs1(e.x);
        }
}

ll opt = -INF, bst = -INF;

void dfs2(int v, int V, int p) {
    bst = max(bst, opt + dep[v] - dist[V]);
    for(auto e : g[v]) if(!was[e.x] && p != e.x) dfs2(e.x, V, v);
}

void dfs3(int v, int V, int p) {
    if(v != V) opt = max(opt, dep[v] + dist[V]);
    for(auto e : g[v]) if(!was[e.x] && p != e.x) dfs3(e.x, V, v);
}

void dfs4(int v, int V, int p) {
    if(v != V) bst = max(bst, opt + dep[v] - dist[V]);
    for(auto e : g[v]) if(!was[e.x] && p != e.x) dfs4(e.x, V, v);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }
    dfs0(0, -1);
    for(int v : path) was[v] = 1;
    for(int v : path) {
        curs = 0, dfs1(v);
        if(curs > 2) any = 1;
    }
    memset(was, 0, sizeof(was));
    for(int v : path) was[v] = 1;
    int Y = -1;
    for(int v : path) {
        dfs2(v, v, -1);
        if(Y != -1) {
            opt = max(opt, dist[Y]);
            dfs4(v, v, -1);
        }
        Y = v;
        dfs3(v, v, -1);
    }
    if(any) bst = max(bst, 0LL);
    while(q--) {
        ll x; cin >> x;
        cout << min(dist[n - 1], dist[n - 1] + bst + x) << '\n';
    }
}