#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 3e3 + 10;
const ll Inf = 2e16;
const ll Log = 30;

vector<ll> G[Maxn];

ll dp[Maxn][Maxn];
vector< pair<ll, pll> > E;

ll get(ll u, ll v){
	return max(dp[u][v], dp[v][u]);
}

ll wh[Maxn][Maxn];
ll sub[Maxn][Maxn];

ll rt;
void DFS(ll u, ll p, ll d){
	sub[rt][u] = 1;
	wh[rt][u] = p;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u, d + 1);
		sub[rt][u] += sub[rt][adj];
	}
	if(u <= rt) E.pb({d, {u, rt}});
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i = 1; i <= n; i++){
		rt = i;
		DFS(i, -1, 0);
	}
	sort(all(E));
	ll di;
	ll ans = 0;
	for(auto x : E ){
		ll fi = x.F;
		u = x.S.F;
		v = x.S.S;
		if(fi == 0){
			dp[u][v] = 0;
			continue;
		}
		dp[u][v] = sub[u][v] * sub[v][u] + max( get(u, wh[u][v]), get(v, wh[v][u])  );
		ans = max(ans, dp[u][v]);
	}
	cout << ans << '\n';
	return 0;
}