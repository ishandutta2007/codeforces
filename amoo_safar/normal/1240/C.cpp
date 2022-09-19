#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1e9 + 7;
const int Maxn = 5e5 + 10;
const ll Inf = 1000000000000000LL;

ll dp1[Maxn], dp2[Maxn];
ll k;
vector<pll> G[Maxn];
vector<ll> H[Maxn];

void DFS(ll u, ll p){
	ll sm = 0;
	ll adj;
	
	for(auto E : G[u]){
		adj = E.F;
		if(adj != p){
			DFS(adj, u);
			sm += dp1[adj];
			H[u].pb(dp2[adj] - dp1[adj] + E.S); 
		}
	}
	
	sort(all(H[u]));
	reverse(all(H[u]));
	ll d = 0;
	for(int i = 0; i <= min(k, (ll) H[u].size()); i++){
		if(i == k) break;
		dp2[u] = max(dp2[u], sm + d);
		if(i != H[u].size()) d += H[u][i];
	}
	if(H[u].size() >= k) dp1[u] = max(dp2[u], sm + d);
	else dp1[u] = dp2[u];
}

int MAIN(){
	//memset(dp1, 0, sizeof dp1);
	//memset(dp2, 0, sizeof dp2);
	
	ll n;
	cin >> n >> k;
	fill(dp1, dp1 + n + 1, 0);
	fill(dp2, dp2 + n + 1, 0);
	ll u, v, w;
	for(int i = 1; i < n; i++){
		cin >> u >> v >> w;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	DFS(1, -1);
	
	cout << dp1[1] << '\n';	
	for(int i = 0; i <= n; i++) {
		G[i].clear();
		H[i].clear();
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}