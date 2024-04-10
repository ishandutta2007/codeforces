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
const int mod = 998244353, x = 864197532, N = 200000, logN = 18, K = 350;

void solve() {
	int n, m, u, v;
	cin >> n >> m;
	vector <int> happy(n), sz(n), bad(n, 0), adj[n], sz2(n);
	fop (i,0,n) cin >> sz[i], sz2[i] = sz[i];
	fop (i,0,n) cin >> happy[i];
	fop (i,0,n - 1) {
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bool is = true;
	function<void(int, int)> dfs1 = [&](int v, int pa) {
		int allbad = 0;
		for (int u : adj[v]) if (u != pa) {
			dfs1(u, v);
			sz[v] += sz[u];
			allbad += bad[u];
		}
		if ((sz[v] - happy[v]) & 1) is = false;
		bad[v] = (sz[v] - happy[v]) >> 1;
		if (sz[v] < bad[v] || bad[v] < 0) is = false;
		if (allbad + sz2[v] < bad[v]) is = false;
	};
	dfs1(0, -1);
	cout << (is ? "YES\n" : "NO\n");
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