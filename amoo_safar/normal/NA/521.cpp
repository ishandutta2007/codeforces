#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
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
const ll MAXN = (ll) 3e2 + 10;
const ll INF = (ll) 1e15;
const ld EPS = (ld) 1e-8;

ll order[MAXN];
vector<ll> g[MAXN], ans, le;

void set_order(ll node, ll par){
	for(auto adj : g[node]){
		if(adj == par) continue;
		set_order(adj, node);
		order[node] = min(order[node], order[adj]);
	}
}

void DFS(ll node, ll par){
	ans.pb(node);
	for(auto adj : g[node]){
		if(adj == par) continue;
		DFS(adj, node);
		ans.pb(node);
	}
}

bool CMP(ll u, ll v){
	return order[u] < order[v];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(order, order + MAXN, INF);
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}	
	ll cnt = 0;
	for(int i = 2; i <= n; i++){
		if(g[i].size() == 1) cnt ++;
	}
	for(int i = 0; i < cnt; i++){
		cin >> u;
		order[u] = i;
		le.pb(u);
	}
	
	set_order(1, -1);
	for(int i = 1; i <= n; i++) sort(all(g[i]), CMP);
	DFS(1, -1);
	
	ll po = 0;
	le.pb(-1);
	for(auto x : ans){
		if(le[po] == x) po ++;
	}
	if(po < cnt) return cout << -1, 0;
	for(auto x : ans) cout << x << " ";
	
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