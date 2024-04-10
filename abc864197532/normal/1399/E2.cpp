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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 18, K = 350;

vector <pair <pii, int>> adj[N];
vector <lli> del[2];
lli all = 0;

int dfs(int v = 0, int pa = -1, int w = 0, int c = 0) {
	int cnt = 0, is = 1;
	for (auto A : adj[v]) if (A.X.X != pa) {
		is = 0;
		cnt += dfs(A.X.X, v, A.X.Y, A.Y);
	}
	cnt += is;
	if (~pa) {
		lli now = w;
		all += now * cnt;
		while (now) {
			del[c].pb((now - now / 2) * cnt);
			now /= 2;
		}
	}
	return cnt;
}

void solve () {
	int n, u, v, w, c;
	lli S;
	cin >> n >> S;
	fop (i,0,n - 1) {
		cin >> u >> v >> w >> c; u--; v--; c--;
		adj[u].pb(mp(mp(v, w), c));
		adj[v].pb(mp(mp(u, w), c));
	}
	dfs();
	if (all <= S) {
		cout << 0 << endl;
	} else {
		sort(del[0].rbegin(), del[0].rend());
		sort(del[1].rbegin(), del[1].rend());
		lli all1 = 0, need = all - S;
		vector <lli> pre;
		pre.pb(0);
		int ans = 1 << 30;
		for (lli i : del[1]) pre.pb(pre.back() + i);
		fop (i,0,del[0].size() + 1) {
			if (i) all1 += del[0][i - 1];
			if (all1 + pre.back() < need) continue;
			int j = lower_bound(all(pre), need - all1) - pre.begin();
			ans = min(ans, i + 2 * j);
		}
		cout << ans << endl;
	}
	fop (i,0,n) adj[i].clear();
	del[0].clear(); del[1].clear();
	all = 0;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}