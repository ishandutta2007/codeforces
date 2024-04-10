#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll n, k;
ll val[MAXN], par[MAXN], dp[MAXN];
vector<ll> G[MAXN], H[MAXN], R[MAXN], vis, ord, topol;
vector<pll> to_add, E;
bitset<1000010> lf, mk1, mk2;

void DFS(ll u){
	ll dep = vis.size();
	vis.pb(u);
	ll p = vis[max(dep - k, 0ll)];
	lf[u] = true;
	for(auto adj : G[u]){
		DFS(adj);
		lf[u] = false;
	}
	if(lf[u]) to_add.pb({u, p});
	vis.pop_back();
}

void DFS1(ll u){
	mk1[u] = true;
	for(auto adj : G[u]){
		if(!mk1[adj]) DFS1(adj);
	}
	ord.pb(u);
}

void DFS2(ll u, ll p){
	mk2[u] = true;
	par[u] = p;
	val[p] += (lf[u] ? 1 : 0);
	for(auto adj : H[u]){
		if(!mk2[adj]) DFS2(adj, p);
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	ll u, v;
	for(int i = 2; i <= n; i++){
		cin >> u;
		G[u].pb(i);
		H[i].pb(u);
		E.pb({i, u});
	}
	DFS(1);
	for(auto edge : to_add){
		u = edge.F;
		v = edge.S;
		G[u].pb(v);
		H[v].pb(u);
		E.pb({v, u});
	}
	DFS1(1);
	reverse(all(ord));
	for(auto node : ord){
		if(!mk2[node]){
			DFS2(node, node);
			topol.pb(node);
		}
	}
	for(auto edge : E){
		u = edge.F;
		v = edge.S;
		u = par[u];
		v = par[v];
		if(u != v) R[u].pb(v);
	}
	
	for(auto node : topol){
		dp[node] = val[node];
		for(auto adj : R[node]){
			dp[node] = max(dp[node], dp[adj] + val[node]);
		}
	}
	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}


/*

                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/