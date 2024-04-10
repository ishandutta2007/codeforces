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
int k;

void cyc (int v, int u, bool is = true) {
	if (cyc_ans.size() && depth[v] - depth[u] + 1 > k) return;
	vector <int> ans;
	int now = v;
	while (now != u) {
		ans.pb(now + 1);
		now = p[now];
	}
        ans.pb(u + 1);
	if (ans.size() <= k) {
		cout << 2 << endl << ans.size() << endl;
		print(ans);
		exit(0);
	} else {
		if (cyc_ans.empty()) cyc_ans = ans;
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
	cin >> n >> m >> k;
	vis.resize(n, false); depth.resize(n); p.resize(n);
	fop (i,0,m) {
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0, -1);
	if (!cyc_ans.empty()) {
		cout << 1 << endl;
		for (int i = 0, cnt = 0; i < cyc_ans.size(), cnt < (k + 1) >> 1; i += 2, cnt++) {
			cout << cyc_ans[i] << ' ';
		}
		cout << endl;
	} else {
		vector <int> ans[2];
		fop (i,0,n) ans[depth[i] & 1].pb(i + 1);
		if (ans[0].size() < ans[1].size()) swap(ans[0], ans[1]);
		cout << 1 << endl;
		fop (i,0,(k + 1) >> 1) cout << ans[0][i] << ' ';
		cout << endl;
	}
}