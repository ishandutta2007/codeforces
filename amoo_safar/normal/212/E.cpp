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
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

vector<ll> G[MAXN], ans;
bitset<5010> knap, sack[MAXN];
ll n;

ll DFS(ll u, ll p){
	ll res, sz = 1;
	sack[u][0] = true;
	for(auto adj : G[u]){
		if(adj == p) continue;
		res = DFS(adj, u);
		sack[u] |= (sack[u] << res);
		sz += res;
	}
	sack[u] |= (sack[u] << (n - sz));
	knap |= sack[u];
	return sz;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v); G[v].pb(u);
	}
	DFS(1, -1);
	for(int i = 1; i <= n - 2; i++) if(knap[i]) ans.pb(i);
	cout << ans.size() << '\n';
	for(auto x : ans) cout << x << " " << n - 1 - x << '\n';
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