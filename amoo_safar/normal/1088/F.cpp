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
const ll MAXN = (ll) 5e5 + 10;
const ll LOG = (ll) 20 + 1;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll par[MAXN][LOG], a[MAXN];
vector<ll> g[MAXN];

void DFS(ll node, ll p){
	par[node][0] = p;
	for(auto adj : g[node]){
		if(adj == p) continue;
		DFS(adj, node);
	}
	return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll ind = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] < a[ind]) ind = i;
	}
	DFS(ind, ind);
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++) par[j][i] = par[par[j][i - 1]][i - 1];
	}
	ll mn, p, ans = 0;
	for(int i = 1; i <= n; i++){
		if(i == ind) continue;
		mn = INF;
		for(int j = 0; j < LOG; j++){
			p = par[i][j];
			mn = min(mn, a[p] + a[i] + a[p] * j);
		}
		ans += mn;
	}
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