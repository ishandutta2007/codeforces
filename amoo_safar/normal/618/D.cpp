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

ll dp1[MAXN];
ll dp2[MAXN];

vector<pll> G[MAXN];
vector<ll> al;

void DFS(ll u, ll p){
	ll adj, w;
	ll sm = 0;
	for(auto e : G[u]){
		adj = e.F;
		w = e.S;
		if(adj == p) continue;
		DFS(adj, u);
		sm += dp2[adj];
	}
	dp2[u] = sm;
	ll mx = 0;
	for(auto e : G[u]){
		adj = e.F;
		w = e.S;
		if(adj == p) continue;
		mx = max(mx, sm - dp2[adj] + dp1[adj] + w);
		al.pb(dp1[adj] - dp2[adj] + w);
	}
	dp1[u] = max(mx, sm);
	
	al.pb(0); al.pb(0);
	sort(all(al));
	reverse(all(al));
	dp2[u] = max(dp2[u], sm + al[0] + al[1]);
	dp2[u] = max(dp2[u], dp1[u]);
	al.clear();
}

ll deg[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, x, y;
	cin >> n >> x >> y;
	ll u, v, w = 1;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb({v, w});
		G[v].pb({u, w});
		deg[u] ++;
		deg[v] ++;
	}
	if(x >= y){
		ll mx = *max_element(deg + 1, deg + n + 1);
		if(mx == n - 1) cout << x + (n - 2) * y;
		else cout << (n - 1) * y;
		return 0;
	}
	DFS(1, -1);
	//debug(dp2[1]);
	cout << (dp2[1] * x) + ((n - 1 - dp2[1]) * y);
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