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
const int mod = 998244353, x = 864197532, N = 300000, logN = 17;

vector <int> adj[N];
int tans = 0;

int dfs(int v, int pa) {
	int best1 = 0, best2 = 0, cnt = 0;
	for (int u : adj[v]) if (u != pa) {
		int cur = dfs(u, v);
		cnt++;
		if (best1 < cur) tie(best1, best2) = mp(cur, best1);
		else if (best2 < cur) best2 = cur;
	}
	tans = max(tans, best1 + best2 + cnt - (v == 0));
	if (pa == -1) tans = max(tans, best1 + 1); 
	return max(best1 + cnt, 1);
}

void solve() {
	int n, m, u, v;
	cin >> n;
	fop (i,0,n - 1) {
		cin >> u >> v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	tans = 0;
	dfs(0, -1);
	cout << tans << endl;
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