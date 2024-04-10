#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 350;

vector <int> adj[N], back_degree;

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

void solve() {
	int n, m, t, u, v;
	cin >> n >> m;
	back_degree.assign(n, 0);
	vector <pii> edge;
	fop (i,0,m) {
		cin >> t >> u >> v; u--; v--;
		if (t == 1) adj[u].pb(v), back_degree[v]++;
		else edge.eb(u, v);
	}
	vector <int> a = toposort(n);
	if (a.back() == -1) cout << "NO\n";
	else {
		cout << "YES\n";
		vector <int> id(n, -1);
		fop (i,0,n) id[a[i]] = i;
		for (auto A : edge) {
			if (id[A.X] > id[A.Y]) swap(A.X, A.Y);
			cout << A.X + 1 << ' ' << A.Y + 1 << endl;
		}
		fop (i,0,n) for (int j : adj[i]) {
			cout << i + 1 << ' ' << j + 1 << endl;
		}
	}
	fop (i,0,n) adj[i].clear();
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