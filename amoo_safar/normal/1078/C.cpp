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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll dp1[MAXN], dp2[MAXN], dp3[MAXN];
vector<ll> g[MAXN];

ll pow_mod(ll base, ll power){
	base %= MOD;
	if(power == 0) return 1;
	if(power % 2 == 1) return (base * pow_mod(base, power - 1)) % MOD;
	return pow_mod( (base * base) % MOD, power / 2);
}

void DFS(ll node, ll par){
	ll sons = 0;
	for(auto adj : g[node]){
		if(adj == par) continue;
		DFS(adj, node);
		sons ++;
	}
	dp3[node] = 1;
	for(auto adj : g[node]){
		if(adj == par) continue;
		dp3[node] *= (dp1[adj] + dp3[adj]);
		dp3[node] %= MOD;
	}
	ll all = 1;
	for(auto adj : g[node]){
		if(adj == par) continue;
		all *= (2ll * dp1[adj] + dp3[adj]);
		all %= MOD;
	}
	dp1[node] = 0;
	for(auto adj : g[node]){
		if(adj == par) continue;
		dp1[node] += ( ( ( (all * pow_mod( 2ll * dp1[adj] + dp3[adj], MOD - 2)) % MOD ) * (((dp2[adj] + dp3[adj])) % MOD)  ) % MOD );
		dp1[node] %= MOD;
	}
	dp2[node] = all - dp3[node];
	
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	DFS(1, -1);
	cout << (dp1[1] + dp3[1]) % MOD;
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