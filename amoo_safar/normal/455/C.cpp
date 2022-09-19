#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll par[MAXN], lp[MAXN], mark[MAXN], parcom[MAXN], maxdis[MAXN];

ll get_par(ll node){
	if(par[node] != node){
		par[node] = get_par(par[node]);
	}
	return par[node];
}

void merge(ll x, ll y){
	ll parx = get_par(x);
	ll pary = get_par(y);
	par[pary] = parx;
	maxdis[parx] = max(max(maxdis[pary], maxdis[parx]), (maxdis[pary] + 1) / 2 + (maxdis[parx] + 1) / 2 + 1);
}

vector<ll> g[MAXN], coms[MAXN];

void dfs(ll node, ll com){
	
	mark[node] = 1;
	coms[com].pb(node);
	
	for(auto adj : g[node]){
		if(!mark[adj]) dfs(adj, com);
	}
}

pll farest(ll node, ll par){
	ll ans = 0;
	ll far = node;
	pll fa;
	for(auto adj : g[node]){
		if(adj != par){
			fa = farest(adj, node);
			if(fa.F + 1 > ans){
				ans = fa.F + 1;
				far = fa.S;
			}
		}
	}
	return {ans, far};
}

int main(){
	for(int i = 0; i < MAXN; i++) par[i] = i; 
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m, q, u, v;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll c = 0;
	for(int i = 0; i < n; i++){
		if(!mark[i]){
			dfs(i, c);
			parcom[c] = i;
			c++;
		}
	}
	ll longest;
	for(int i = 0; i < c; i++){
		longest = farest(farest(parcom[i], -1).S, -1).F;
		for(auto x : coms[i]){
			par[x] = parcom[i];
			maxdis[x] = longest;
		}
	}
	ll t;
	for(int i = 0; i < q; i++){
		cin >> t;
		if(t == 1){
			cin >> u;
			u--;
			//debug(u);
			//debug(get_par(u));
			cout << maxdis[get_par(u)] << '\n';
			
		} else {
			cin >> u >> v;
			u--;
			v--;
			
			if(get_par(u) != get_par(v)) merge(u, v);
		}
	}
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