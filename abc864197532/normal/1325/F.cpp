#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100000, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

vector <int> adj[N];
vector <bool> vis;
vector <int> depth, p, cyc_ans;
int k = 0;

void cyc (int v, int u) {
	if (depth[v] - depth[u] + 1 >= k) {
		vector <int> ans = {u + 1};
		int now = v;
		while (now != u) {
			ans.pb(now + 1);
			now = p[now];
		}
		cout << 2 << endl << ans.size() << endl;
		print(ans);
		exit(0);
	}
}

void dfs(int v, int pa) {
	depth[v] = ~pa ? depth[pa] + 1 : 0;
	vis[v] = true;
	p[v] = pa;
	for (int u : adj[v]) if (u != pa) {
		if (!vis[u]) {
			dfs(u, v);
		} else if (depth[v] > depth[u]) {
			cyc(v, u);
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	while (k * k < n) k++;
	vis.resize(n, false); depth.resize(n); p.resize(n);
	fop (i,0,m) {
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0, -1);
	vector <int> ans[k - 1];
	fop (i,0,n) ans[depth[i] % (k - 1)].pb(i + 1);
	int mx = 0;
	fop (i,1,k - 1) {
		if (ans[mx].size() < ans[i].size()) mx = i;
	}
	cout << 1 << endl;
	fop (i,0,k) cout << ans[mx][i] << ' ';
	cout << endl;
}