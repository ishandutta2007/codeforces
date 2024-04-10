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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll par[MAXN], sp[MAXN];
pair<pll, ll> E[MAXN];

ll get_par(ll u){
	if(par[u] == u) return u;
	return par[u] = get_par(par[u]);
}

bool merge(ll u, ll v){
	u = get_par(u);
	v = get_par(v);
	if(u == v) return false;
	if(min(sp[u], sp[v]) == 0) {
		par[u] = v;
		sp[v] += sp[u];
		return false;
	}
	par[u] = v;
	sp[v] += sp[u];
	return true;
}

bool CMP(pair<pll, ll> a, pair<pll, ll> b){
	return a.S < b.S;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i =0;i<MAXN;i++) par[i] = i;
	ll n, m, k;
	cin >> n >> m >> k;
	ll no;
	for(int i = 0;i<k;i++){
		cin >> no;
		sp[no] ++;
	}
	ll s,e,w;
	for(int i = 0;i<m;i++){
		cin >> E[i].F.F >> E[i].F.S >> E[i].S;
	}
	sort(E, E + m, CMP);
	ll ans = 0;
	for(int i = 0;i<m;i++){
		if(merge(E[i].F.F, E[i].F.S)){
			ans = max(ans, E[i].S);
		}
	}
	for(int i =0;i<k;i++) cout << ans << " ";
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