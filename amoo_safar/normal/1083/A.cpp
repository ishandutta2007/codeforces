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

ll ans = 0;
ll w[MAXN], dp1[MAXN], dp2[MAXN];

vector<pll> g[MAXN];
vector<ll> bw[MAXN];

void DFS(ll u, ll p){
	bw[u].pb(w[u]);
	dp2[u] = w[u];
	ll c, adj;
	for(pll ed : g[u]){
		adj = ed.F;
		c = ed.S;
		if(adj == p) continue;
		DFS(adj, u);
		
		if(c <= dp2[adj]){
			dp2[u] = max(dp2[u], dp2[adj] + w[u] - c);
			bw[u].pb(dp2[adj] + w[u] - c);
		} else {
			bw[u].pb(w[u]);
		}
		
	}
	
	ans = max(ans, max(dp1[u], dp2[u]));
}

void DFS2(ll u, ll p, ll in){
	sort(all(bw[u]));
	reverse(all(bw[u]));
	
	dp1[u] = in + w[u];
	ll c, adj;
	ll ye, x;
	for(pll ed : g[u]){
		adj = ed.F;
		c = ed.S;
		if(adj == p) continue;
		
		ye = 0;
		if(in + w[u] >= c ) ye = in + w[u] - c;
		
		if(c <= dp2[adj]){
			x = dp2[adj] + w[u] - c;
		} else {
			x = w[u];
		}
		
		if(x == bw[u][0]){
			if(bw[u][1] >= c) ye = max(ye, bw[u][1] - c);
		}
		else {
			if(bw[u][0] >= c) ye = max(ye, bw[u][0] - c);
		}
		DFS2(adj, u, ye);
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> w[i];
	ll u, v, c;
	for(int i = 1; i < n; i++){
		cin >> u >> v >> c;
		g[u].pb({v, c});
		g[v].pb({u, c});
	}


	DFS(1, -1);
	DFS2(1, -1, 0);
	for(int u = 1; u <= n; u++) ans = max(ans, max(dp2[u], dp1[u]));
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