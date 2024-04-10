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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll su = 0;
ll a[MAXN], dp1[MAXN], dp2[MAXN], dp3[MAXN];
vector<ll> G[MAXN];

void DFS(ll u, ll p){
	dp1[u] = 0;
	dp2[u] = 0;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u);
		dp1[u] += dp1[adj];
		dp2[u] += dp2[adj];
	}
	dp2[u] += dp1[u];
	dp1[u] += a[u];
}

void DFS2(ll u, ll p, ll v){
	dp3[u] = v;
	ll tot = 0;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS2(adj, u, (v + dp2[u] - (dp2[adj] + dp1[adj])) + (su - dp1[adj]));
	}
	return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i =1;i<=n;i++) cin >> a[i];
	for(int i = 1; i<= n;i++) su += a[i];
	ll u , v;
	for(int i = 1;i<n;i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, -1);
	DFS2(1, -1, 0);
	
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, dp2[i] + dp3[i]);	
	cout << ans;
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