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
const int Maxn = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[Maxn];
map<pll, ll> mp;
ll dep[Maxn], dp[Maxn], Dep[Maxn], par[Maxn];

void DFS(ll u, ll p, ll D = 0){
	ll mx = 0, mx2 = 0;
	Dep[u] = D;
	par[u] = p;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u, D + 1);
		mp[{u, adj}] = dep[adj] + 1;
		dep[u] = max(dep[u], dep[adj] + 1);
		if(dep[adj] + 1 > mx){
			mx2 = mx;
			mx = dep[adj] + 1;
		} else mx2 = max(dep[adj] + 1, mx2);
	}
}
void dfs(ll u, ll p){
	ll mx = 0, mx2 = 0;
	for(auto adj : G[u]){
		if(adj == p) continue;
		if(dep[adj] + 1 > mx){
			mx2 = mx;
			mx = dep[adj] + 1;
		} else mx2 = max(dep[adj] + 1, mx2);
	}
	for(auto adj : G[u]){
		if(adj == p) continue;
		dp[adj] = 1 + dp[u];
		if(dep[adj] + 1 == mx) dp[adj] = max(dp[adj], mx2 + 1);
		else dp[adj] = max(dp[adj], mx + 1);
		dfs(adj, u);
		mp[{adj, u}] = dp[adj];
	}
}

vector<pll> rec[Maxn];
ll ans[Maxn], cnt[Maxn], cnt2[Maxn], mxv[Maxn];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
		ans[1] = max(ans[1], (ll) G[u].size() + 1LL);
		ans[1] = max(ans[1], (ll) G[v].size() + 1LL);
	}
	
	DFS(1, -1);
	dfs(1, -1);
	//for(int i = 1; i <= n; i++) cout << dep[i] << ' ' << dp[i] << '\n';
	for(auto x : mp){
		//cerr << x.F.F << " " << x.F.S << " -> " << x.S << '\n';
		rec[x.S].pb(x.F);
	}
	for(int i = n; i > 0; i--){
		for(auto e : rec[i]){
			ans[i + i + 1] = max(ans[i + i + 1], cnt[e.F] + 1);
		}
		
		for(auto e : rec[i]){
			cnt[e.F] ++;
			ans[i + i] = max(ans[i + i], cnt[e.F]);
			ans[i + i - 1] = max(ans[i + i - 1], cnt[e.F]);
		}
	}
	
	memset(cnt, 0, sizeof cnt);
	
	for(int i = n; i > 0; i--){
		for(auto e : rec[i]){
			cnt[e.F] ++;
			ans[i + i] = max(ans[i + i], cnt[e.F]);
			if(par[e.S] == e.F) cnt2[e.F] ++;
			if(e.F != 1){
				mxv[par[e.F]] = max(mxv[par[e.F]], cnt2[e.F]);
			}
		}
		for(auto e : rec[i]){
			u = e.F;
			if(u != 1){
				ans[i + i] = max(ans[i + i], cnt[u] + cnt[par[u]] - 1 - (mp[pll(u, par[u])] >= i));
			}
			ll res = cnt[i] + cnt[par[i]];
			if(mxv[u] > 0){
				ans[i + i] = max(ans[i + i], mxv[u] + cnt[u] - 1);
			}
		}
	}	
	
	for(int i = n; i > 0; i--) ans[i] = max(ans[i], ans[i + 2]);
	
	
	
	//cout << "End !\n";
	for(int i = 1; i <= n; i++) cout << max(1LL, ans[i]) << ' ';
	return 0;
}