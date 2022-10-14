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
const int mod = 998244353, x = 864197532, N = 500007;

vector <int> adj[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	vector <pii> need(n);
	fop (i,0,m) {
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fop (i,0,n) cin >> need[i].X, need[i].Y = i;
	sort(all(need));
	vector <int> nei(n, 1);
	bool is = true;
	fop (i,0,n) {
		int v = need[i].Y;
		for (int u : adj[v]) if (nei[u] == nei[v]) {
			nei[u] = nei[v] + 1;
		}
		if (nei[v] != need[i].X) is = false;
	}
	if (!is) cout << -1 << endl;
	else fop (i,0,n) cout << need[i].Y + 1 << " \n"[i == n - 1];
}