#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000, logN = 18, K = 350;

vector <int> adj[N];

vector <int> bfs(int s, int n) {
	vector <int> dis(n, -1);
	queue <int> q;
	q.push(s);
	dis[s] = 0;
	while (q.size()) {
		int v = q.front(); q.pop();
		for (int u : adj[v]) if (dis[u] == -1) {
			dis[u] = dis[v] + 1;
			q.push(u);
		}
	}
	return dis;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, u, v, s, t;
	cin >> n >> m >> s >> t; s--; t--;
	vector <vector <bool>> has(n, vector <bool> (n, false));
	fop (i,0,m) {
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
		has[u][v] = true;
		has[v][u] = true;
	}
	vector <int> dis1 = bfs(s, n), dis2 = bfs(t, n);
	int old = dis1[t], ans = 0;
	fop (i,0,n) fop (j,i + 1,n) if (i != j && !has[i][j]) {
		int nw = min(dis1[i] + 1 + dis2[j], dis1[j] + 1 + dis2[i]);
		if (old <= nw) ans++;
	}
	cout << ans << endl;
}