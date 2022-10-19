///
///   Oh? You're approaching me?
///

#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int mod = 7*17*(1<<23) + 1;

ll inv(ll x)
{
	ll ans = 1, y = mod-2;
	while (y) {
		if (y&1) ans = ans*x % mod;
		x = x*x % mod;
		y >>= 1;
	}
	return ans;
}

void factorize(ll x, vector<ll>& ans)
{
	for (ll y = 2; y*y <= x; ++y) {
		while (x%y == 0) {
			ans.push_back(y);
			x /= y;
		}
	}
	if (x > 1)
		ans.push_back(x);
}

typedef tuple<int, ll, ll> Edge;
typedef unordered_map<ll, int> mp;

ll ins(mp &lcm, mp &cur, ll x, int y)
{
	ll ans = 1;
	if (cur[x] == lcm[x] && y > 0) {
		lcm[x]++;
		ans = x;
	}
	cur[x] += y;
	return ans;
}

ll dfs_lcm(vector<vector<Edge>> &adj, mp &lcm, mp &cur, int v, int p)
{
	ll ans = 1;
	for (auto [u, a, b] : adj[v]) {
		if (u == p) continue;
		vector<ll> fa, fb;
		factorize(a, fa);
		factorize(b, fb);
		for (auto x : fa) { ans = ans*ins(lcm, cur, x, -1) % mod; }
		for (auto x : fb) { ans = ans*ins(lcm, cur, x,  1) % mod; }
		ans = dfs_lcm(adj, lcm, cur, u, v)*ans % mod;
		for (auto x : fb) { ans = ans*ins(lcm, cur, x, -1) % mod; }
		for (auto x : fa) { ans = ans*ins(lcm, cur, x,  1) % mod; }
	}
	return ans;
}

ll dfs(vector<vector<Edge>> &adj, ll cur, int v, int p)
{
	ll ans = cur;
	for (auto [u, a, b] : adj[v]) {
		if (u == p) continue;
		ans = (ans + dfs(adj, cur*a%mod*inv(b)%mod, u, v)) % mod;
	}
	return ans;
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<Edge>> adj(n);
	Loop (_,1,n) {
		int v, u, a, b;
		cin >> v >> u >> a >> b;
		--v; --u;
		adj[v].emplace_back(u, b, a);
		adj[u].emplace_back(v, a, b);
	}
	mp cur, lcm_mp;
	ll lcm_ll = dfs_lcm(adj, lcm_mp, cur, 0, -1);
	ll ans = dfs(adj, lcm_ll, 0, -1);
	cout << ans << '\n';
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
		solve();
}