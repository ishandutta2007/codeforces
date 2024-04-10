#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17;

vector <int> adj[N], radj[N];
int scc[N], _id = 0, cnt[N];
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
    cnt[_id]++;
    for (int u : adj[v]) if (scc[u] == -1) {
        dfs(u);
    }
}

void build(int n) {
    _id = 0;
    order.clear();
    for (int i = 0; i < n; ++i) {
        vis[i] = false;
        scc[i] = -1;
        cnt[i] = 0;
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

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = m;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y, x--, y--;
        if (x == y) {ans--; continue;}
        adj[x].pb(y);
        radj[y].pb(x);
    }
    build(n);
    for (int i = 0; i < n; ++i) {
        if (cnt[i] > 1) ans++;
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) adj[i].clear(), radj[i].clear();
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}