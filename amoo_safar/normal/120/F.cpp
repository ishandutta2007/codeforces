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
const ll MAXN = (ll) 1e2 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

vector<ll> g[MAXN];

pll dfs(ll node, ll par){
	ll ans = 0;
	ll tar = node;
	pll df;
	for(auto adj : g[node]){
		if(adj == par) continue;
		df = dfs(adj, node);
		if(ans < 1 + df.F){
			ans = 1 + df.F;
			tar = df.S;
		}
	}
	return mp(ans, tar);
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
	ll n, m, u, v, ans, ma;
	scanf("%lld", &m);
	
	ans = 0;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < MAXN; j++) g[j].clear();
		ma = 0;
		
		scanf("%lld", &n);
		for(int j = 0; j < n - 1; j++){
			scanf("%lld %lld", &u, &v);
			u--;
			v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		//for(int j = 0 ; j < n; j++) ma = max(ma, dfs(j, -1));
		//debug(ma);
		ans += dfs( dfs(0, -1).S, -1 ).F;
	}

	printf("%lld", ans);
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