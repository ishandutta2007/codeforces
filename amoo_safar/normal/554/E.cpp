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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll pow_mod(ll base, ll power){
	//debug(power);
	ll x;
	if(power == 0) return 1;
	if(power == 1) return base % MOD;
	if(power % 2 == 0){
		x = pow_mod(base, power / 2);
		return (x * x) % MOD;
	}
	x = pow_mod(base, power / 2);
	return (( (x * x) % MOD ) * base) % MOD;
}

ll part[MAXN];

vector<ll> g0[MAXN];
vector<ll> g1[MAXN];

bool dfs(ll node, ll p){
	part[node] = p;

	bool res = true, res2;
	for(auto adj : g0[node]){
		if(part[adj] == p) return false;
		if(part[adj] == -1){
			res2 = dfs(adj, 1- p);
			res = res && res2;
		}
		
	}
	
	for(auto adj : g1[node]){
		if((part[adj] != p) and (part[adj] != -1)) return false;
		if(part[adj] == -1){
			res2 = dfs(adj, p);
			res = res && res2;
		}
	}
	
	return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	fill(part, part + MAXN, -1);
	
	ll n, m, u, v, c;
	scanf("%lld %lld", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%lld %lld %lld", &u, &v, &c);
		u--;
		v--;
		if(c == 0){
			g0[u].pb(v);
			g0[v].pb(u);
		} else {
			g1[u].pb(v);
			g1[v].pb(u);
		}
	}
	
	ll coms = 0;
	
	for(int i = 0; i < n; i++){
		if(part[i] == -1){
			//printf("%lld\n", i);
			coms ++;
			if(!dfs(i, 0)){
				//printf("%lld\n", i+1);
				printf("%lld", 0ll);
				return 0;
			}
		}
	}
	for(int i =0;i<n;i++) debug(part[i]);
	printf("%lld\n", pow_mod(2, coms - 1));
	//printf("%lld\n", pow_mod(2, 1562));
	
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