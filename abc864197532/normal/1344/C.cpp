#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200087, logN = 17;

vector <int> adj[N], back_degree(N, 0), radj[N];
vector <bool> vis(N, false), rvis(N, false);

vector <int> toposort(int n) {
	vector <int> degree(n), ans;
	queue <int> q;
	for (int i = 0; i < n; ++i) {
		degree[i] = back_degree[i];
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int v = q.front(); q.pop();
		ans.push_back(v);
		for (int u : adj[v]) {
			degree[u]--;
			if (degree[u] == 0) q.push(u);
		}
	}
	if (ans.size() != n) {
		ans.clear();
		ans.push_back(-1);
	}
	return ans;
}

void dfs (int v) {
	vis[v] = true;
	for (int u : adj[v]) if (!vis[u]) {
		dfs(u);
	}
}

void rdfs (int v) {
	rvis[v] = true;
	for (int u : radj[v]) if (!rvis[u]) {
		rdfs(u);
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
	fop (i,0,m) {
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		radj[v].pb(u);
		back_degree[v]++;
	}
	vector <int> ans = toposort(n);
	if (ans.back() == -1) {
		cout << -1 << endl; 
	} else {
		string ans;
		int nn = 0;
		fop (i,0,n) {
			if (!vis[i] and !rvis[i]) ans.pb('A'), nn++;
			else ans.pb('E');
			dfs(i), rdfs(i);
		}
		cout << nn << '\n' << ans << '\n';
	}
}