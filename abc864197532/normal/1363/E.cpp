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
const int x = 864197532, N = 200000;
const long long mod = 9223372036854775807;
const double eps = 1e-6, Pi = 3.1415926535;
 
vector <int> adj[N];
vector <lli> cost;
vector <int> able;
lli ans = 0;

pii dfs(int v, int pa) {
	if (~pa) cost[v] = min(cost[v], cost[pa]);
	pii now = {0, 0};
	if (able[v] == 0) now.X++;
	if (able[v] == 1) now.Y++;
	for (int u : adj[v]) if (u != pa) {
		pii A = dfs(u, v);
		now.X += A.X;
		now.Y += A.Y;
		if (min(now.X, now.Y) > 0) {
			int k = min(now.X, now.Y);
			ans += cost[v] * k;
			now.X -= k;
			now.Y -= k;
		}
	}
	return now;
}
 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, b, c, bb = 0, cc = 0;
	cin >> n;
	cost.resize(n);
	able.resize(n, 2);
	fop (i,0,n) {
		cin >> cost[i] >> b >> c;
		if (b == 0 and c == 1) able[i] = 0, bb++;
		if (b == 1 and c == 0) able[i] = 1, cc++;
	}
	if (bb != cc) {
		cout << -1 << endl;
		return 0;
	}
	fop (i,0,n - 1) {
		cin >> b >> c;
		b--; c--;
		adj[b].pb(c);
		adj[c].pb(b);
	}
	dfs(0, -1);
	cout << ans * 2 << endl;
}