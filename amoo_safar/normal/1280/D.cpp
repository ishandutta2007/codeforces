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
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[Maxn];
ll n, m, sub[Maxn], dep[Maxn], w[Maxn];
pll dp2[Maxn];

pll dp[Maxn][Maxn];

void DFS(ll u, ll p){
	sub[u] = 1;
	dp[u][1] = {0, w[u]};
	
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u);
		
		for(int i = 1; i <= sub[u] + sub[adj]; i++) dp2[i] = {-Inf, -Inf};
		
		for(int i = 1; i <= sub[u]; i++){
			for(int j = 1; j <= sub[adj]; j++){
				dp2[i + j] = max(dp2[i + j], pll(dp[u][i].F + dp[adj][j].F + (dp[adj][j].S > 0 ? 1 : 0) , dp[u][i].S ));
				dp2[i + j - 1] = max(dp2[i + j - 1], pll(dp[u][i].F + dp[adj][j].F, dp[u][i].S + dp[adj][j].S ));
			}
		}
		for(int i = 1; i <= sub[u] + sub[adj]; i++) dp[u][i] = dp2[i]; 
		sub[u] += sub[adj];
	}
}


int MAIN(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) G[i].clear();
	fill(w, w + n + 8, 0);
	ll x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		w[i] -= x;
	}
	
	for(int i = 1; i <= n; i++){
		cin >> x;
		w[i] += x;
	}
	
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	//cerr << w[1] << " " << w[2] << '\n';
	DFS(1, -1);
	//cerr << dp[1][1].S << '\n';
	cout << dp[1][m].F + (dp[1][m].S > 0 ? 1 : 0) << '\n';
	//cout << flush;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}