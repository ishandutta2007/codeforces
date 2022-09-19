#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
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
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll rem[MAXN], ans[MAXN];
map<ll, ll> que[MAXN];
vector<ll> g[MAXN];


void dfs(ll node, ll val, ll dep, ll par){
	for(auto x : que[node]){
		val += x.S;
		rem[ min(MAXN - 1, dep + x.F + 1) ] += x.S;
	}
	val -= rem[dep];
	ans[node] = val;
	
	for(auto adj : g[node]){
		if(adj != par) dfs(adj, val, dep + 1, node);
	}
	
	for(auto x : que[node]){
		rem[ min(MAXN - 1, dep + x.F + 1) ] -= x.S;
	}
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	
	cin >> n;
	ll u, v;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	ll m;
	cin >> m;
	ll d, x;
	for(int i = 0; i < m; i++){
		cin >> v >> d >> x;
		que[v][d] += x;
	}
	
	dfs(1, 0, 0, -1);
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
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