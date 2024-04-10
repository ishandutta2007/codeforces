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

void solve() {
	int n, u, v, k;
	cin >> n >> k;
	set <int> adj[n], adj2[n];
	fop (i,0,n - 1) {
		cin >> u >> v; u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	if (k == 1) {
		cout << n - 1 << endl;
		return;
	}
	fop (i,0,n) if (adj[i].size() == 1) adj2[*adj[i].begin()].insert(i);
	queue <int> q;
	int ans = 0;
	fop (i,0,n) if (adj2[i].size() >= k) q.push(i);
	while (q.size()) {
		v = q.front(); q.pop();
		while (adj2[v].size() >= k) {
			vector <int> del;
			for (int u : adj2[v]) {
				del.pb(u);
				if (del.size() == k) break;
			}
			for (int u : del) {
				adj[u].erase(v);
				adj[v].erase(u);
				adj2[v].erase(u);
			}
			if (adj[v].size() == 1) {
				int u = *adj[v].begin();
				adj2[u].insert(v);
				if (adj2[u].size() >= k) q.push(u);
			}
			ans++;
		}
	}
	cout << ans << endl;
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