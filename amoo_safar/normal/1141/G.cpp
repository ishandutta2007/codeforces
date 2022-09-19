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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll deg[MAXN], b[MAXN];
vector<ll> G[MAXN];
vector<pll> E;

bool CMP(ll u, ll v){
	return deg[u] < deg[v];
}
ll r;
map<pll, ll> mp;
void DFS(ll u, ll p, ll c){
	ll co = 1;
	for(auto adj : G[u]){
		if(co == c) co ++;
		if(co == r + 1) co = 1;
		if(adj == p) continue;
		DFS(adj, u, co);
		mp[{u, adj}] = co;
		mp[{adj, u}] = co;
 		co ++;
		if(co == r + 1) co = 1;
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		deg[v] ++; deg[u]++;
		G[u].pb(v);
		G[v].pb(u);
		E.pb({u, v});
	}
	for(int i = 1;i<=n;i++) b[i] = i;
	sort(deg + 1, deg + n + 1);
	reverse(deg + 1, deg + n + 1);
	r = deg[k + 1];
	cout << r<< '\n';
	DFS(1, -1, -1);
	for(auto x : E) cout << mp[x] << " ";
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