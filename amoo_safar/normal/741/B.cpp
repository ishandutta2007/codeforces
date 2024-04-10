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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][MAXN], mark[MAXN], w[MAXN], b[MAXN];

vector<ll> g[MAXN], coms[MAXN];

void dfs(ll node, ll com){
	
	mark[node] = 1;
	coms[com].pb(node);
	
	for(auto adj : g[node]){
		if(!mark[adj]) dfs(adj, com);
	}
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m, maxw, u, v;
	scanf("%lld%lld%lld", &n, &m, &maxw);
	for(int i = 0; i < n; i++) scanf("%lld", &w[i]);
	for(int i = 0; i < n; i++) scanf("%lld", &b[i]);
	for(int i = 0; i < m; i++){
		scanf("%lld%lld", &u, &v);
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll c = 1;
	for(int i = 0; i < n; i++){
		if(!mark[i]){
			dfs(i, c);
			c++;
		}
	}
	ll sb, sw;
	for(int i = 1; i <= n; i++){
		sb = 0;
		sw = 0;
		for(auto x : coms[i]){
			sb += b[x];
			sw += w[x];
		}
		for(int j = 0; j <= maxw; j++){
			dp[i][j] = dp[i - 1][j];
			if(j >= sw) dp[i][j] = max(dp[i][j], dp[i - 1][j - sw] + sb);
			for(auto x : coms[i]){
				if(w[x] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[x]] + b[x]);
			}
		}
	}
	
	
	ll ans = 0;
	for(int i = 0; i <= maxw; i++) ans = max(ans, dp[n][i]);
	printf("%lld\n", ans);
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