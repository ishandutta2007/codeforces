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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 18, K = 350;

vector <int> adj[N], a;
vector <bool> vis;
map <pii, int> edge;
vector <int> ans;

int dfs(int v, int pa) {
	vis[v] = true;
	int tmp = a[v];
	for (int u : adj[v]) if (!vis[u]) {
		tmp += dfs(u, v);
	}
	if (~pa) {
		if (edge.count({v, pa})) ans[edge[{v, pa}]] = -tmp;
		else ans[edge[{pa, v}]] = tmp;	
	}
	return tmp;
}

int main () {
	int n, m, u, v, c = 0;
	cin >> n;
	a.resize(n);
	vis.assign(n, false);
	fop (i,0,n) cin >> a[i];
	if (accumulate(all(a), 0)) {
		cout << "Impossible\n";
		return 0;
	}
	cin >> m;
	ans.resize(m);
	fop (i,0,m) {
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
		edge[{u, v}] = c++;
	}
	dfs(0, -1);
	cout << "Possible\n";
	fop (i,0,m) cout << ans[i] << endl;
}