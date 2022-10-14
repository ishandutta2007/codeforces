#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
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
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

vector <int> adj[N], radj[N];
int scc[N], _id = 0;
bool vis[N];
int cnt[N];
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

void build(int n) {
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

void dfs2(int v) {
    vis[v] = true;
    for (int u : adj[v]) if (!vis[u]) {
        dfs2(u);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s, --s;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    build(n);
    for (int i = 0; i < n; ++i) vis[i] = false;
    dfs2(s);
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) if (scc[i] != scc[j]) {
            cnt[scc[j]]++;
        }
        if (vis[i]) cnt[scc[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < _id; ++i) {
        if (!cnt[i]) ans++;
    }
    cout << ans << endl;
}