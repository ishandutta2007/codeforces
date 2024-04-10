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

ll par[MAXN], a[MAXN];
vector< pair<ll, pll> > E;

ll get_par(ll u){
	if(par[u] == u) return u;
	return par[u] = get_par(par[u]);
}

bool merge(ll u, ll v){
	u = get_par(u);
	v = get_par(v);
	if(u == v) return false;
	par[u] = v;
	return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < MAXN; i++) par[i] = i;
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	ll ind = 0;
	for(int i = 0; i < n; i++) if(a[i] < a[ind]) ind = i;
	ll u, v, w;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		E.pb({w, {u, v}});
	}
	for(int i = 0; i < n; i++) E.pb({a[ind] + a[i], {ind + 1, i + 1}});
	ll ans = 0;
	sort(all(E));
	for(auto e : E) if(merge(e.S.F, e.S.S)) ans += e.F;
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