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
const int Maxn = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<pll> G[Maxn];
ll n, m, sub[Maxn], dep[Maxn];

void DFS(ll u, ll p, ll d){
	sub[u] = 1;
	dep[u] = d;
	for(auto e : G[u]){
		ll adj = e.F;
		if(adj != p){
			DFS(adj, u, d + e.S);
			sub[u] += sub[adj];
		}
	}
}

ll cent(ll u, ll p){
	for(auto e : G[u]){
		if(e.F != p && sub[e.F] + sub[e.F] > n + n) return cent(e.F, u);
	}
	return u;
}
ll sm;
void dfs(ll u, ll p){
	ll cnt = 0;
	for(auto e : G[u]){
		ll adj = e.F;
		if(adj != p){
			dfs(adj, u);
			cnt += (sub[adj]&1);
		}
	}
	//cerr << cnt << '\n';
	//cerr << dep[u] << " " << cnt << '\n';
	if(sub[u] & 1){
		sm += (cnt / 2LL) * dep[u];
	} else {
		cnt --;
		sm += (cnt / 2LL) * dep[u];
		sm += dep[u];
	}
	
}

int MAIN(){
	cin >> n;
	for(int i = 1; i <= n + n; i++) G[i].clear();
	ll u, v, w;
	for(int i = 1; i < n + n; i++){
		cin >> u >> v >> w;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	DFS(1, -1, 0);
	ll roid = cent(1, -1);
	DFS(roid, -1, 0);
	
	sm = 0;
	dfs(roid, -1);
	
	ll A = 0;
	//for(int i = 1; i <= n + n; i++) cerr << dep[i] << ' '; cerr << '\n';
	
	for(int i = 1; i <= n + n; i++) A += dep[i];
	cout << A - sm - sm << " " << A << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}