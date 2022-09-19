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
const ll LOG = 20;

ll sp[MAXN][LOG], dep[MAXN], ans[MAXN], cnt[MAXN];
vector<pll> G[MAXN];

void DFS(ll u, ll p){
	dep[u] = dep[p] + 1; sp[u][0] = p;
	for(int i = 1; i < LOG; i++) sp[u][i] = sp[sp[u][i - 1]][i - 1];
	ll adj;
	for(auto E : G[u]){
		adj = E.F;
		if(adj == p) continue;
		DFS(adj, u);
	}
}

ll DFS2(ll u, ll p){
	ll adj, res, val = cnt[u];
	for(auto E : G[u]){
		adj = E.F;
		if(adj == p) continue;
		res = DFS2(adj, u);
		ans[E.S] = res;
		val += res;
	}
	return val;
}

ll blift(ll u, ll h){
	for(int i = 0; i < LOG; i++) if(h & (1ll << i)) u = sp[u][i];
	return u;
}

ll LCA(ll u, ll v){
	if(dep[u] < dep[v]) swap(u, v);
	u = blift(u, dep[u] - dep[v]);
	if(u == v) return u;
	for(int i = LOG - 1; i >= 0; i--)
		if(sp[u][i] != sp[v][i]){
			u = sp[u][i];
			v = sp[v][i];
		}
	return sp[u][0];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb({v, i}); G[v].pb({u, i});
	}
	DFS(1, 0);
	ll k;
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> u >> v;
		cnt[u] ++;
		cnt[v] ++;
		cnt[LCA(u, v)] -= 2;
	}
	DFS2(1, 0);
	for(int i = 1; i < n; i++) cout << ans[i] << " ";
	cout << '\n';
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