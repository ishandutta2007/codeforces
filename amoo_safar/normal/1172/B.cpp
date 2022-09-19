#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll LOG = (ll) 30;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll dp[MAXN], f[MAXN], sub[MAXN], son[MAXN];

vector<ll> G[MAXN];

void DFS(ll u, ll p){
	sub[u] = 1;
	dp[u] = 1;
	ll sn = 0;
	for(auto adj : G[u]){
		if(adj == p) continue;
		sn ++;
		DFS(adj, u);
		sub[u] += sub[adj];
		dp[u] = mul(dp[u], dp[adj]);
	}
	if(u != 1) dp[u] = mul(dp[u], f[sn + 1]);
	else dp[u] = mul(dp[u], f[sn]);
	son[u] = sn;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	for(int i = 1; i<MAXN;i++) f[i] = mul(f[i - 1], i);
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, -1);
	cout << mul(n, dp[1]);
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