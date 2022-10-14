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
const int mod = 1e9 + 7, x = 864197532, N = 500000, logN = 17, K = 350;

vector <int> adj[N];
int depth[N], p[N];
bool vis[N];

void dfs(int v, int pa) {
    vis[v] = true;
	depth[v] = ~pa ? depth[pa] + 1 : 0;
	p[v] = pa;
	for (int u : adj[v]) if (!vis[u]) {
		dfs(u, v);
	}
}

void solve() {
	int n, m, u, v;
	cin >> n >> m;
	fop (i,0,m) {
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fop (i,0,n) vis[i] = false;
	dfs(0, -1);
	int id = 0, need = (n + 1) >> 1;
	fop (i,1,n) if (depth[id] < depth[i]) id = i;
	fop (i,0,n) vis[i] = false;
	dfs(id, -1);
	auto it = max_element(depth, depth + n);
	if (*it + 1 >= need) {
		cout << "PATH\n";
		vector <int> ans;
		id = it - depth;
		while (id != -1) {
			ans.pb(id + 1);
			id = p[id];
		}
		cout << ans.size() << endl;
		printv(ans);
	} else {
		cout << "PAIRING\n";
		vector <int> v[n + 1];
		vector <pii> ans;
		fop (i,0,n) {
			int d = depth[i];
			if (v[d].size()) {
				ans.eb(v[d][0] + 1, i + 1);
				v[d].pop_back();
			} else {
				v[d].pb(i);
			}
		}
		cout << ans.size() << endl;
		for (auto A : ans) cout << A.X << ' ' << A.Y << endl;
	}
	fop (i,0,n) adj[i].clear();
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}