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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

vector <int> adj[N];
bool vis[N];
int dep[N], _n;
vector <pii> p;

void dfs(int v, int pa) {
    vis[v] = true;
    _n++;
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        if (!vis[u]) dfs(u, v);
        else if (dep[u] < dep[v]) {
            p.eb(u, v);
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        dfs(i, -1);
        if (p.size() == 1) {
            if (dep[p[0].Y] - dep[p[0].X] == _n - 1) {
                ans++;
            }
        }
        p.clear();
        _n = 0;
    }
    cout << ans << endl;
}