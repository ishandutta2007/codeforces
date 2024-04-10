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

typedef pair<pll, ll> ppll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll n, par[MAXN], w[MAXN], sz[MAXN], wsz[MAXN];
vector<ppll> E;

ll get_par(ll node){
	if(par[node] == node) return node;
	par[node] = get_par(par[node]);
	return par[node];
}

void merge(ll u, ll v){
	u = get_par(u);
	v = get_par(v);
	if(u == v) return ;
	par[u] = v;
	sz[v] += sz[u];
	wsz[v] += wsz[u];
	return ;
}



vector<pll> v;

bool valid(){
	ll ind = 0;
	ll wsum = 0;
	ll szsum = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i].F > v[ind].F){
			ind = i;
		}
		szsum += v[i].F;
		wsum += v[i].S;
	}
	if(2 * v[ind].F <= szsum) return true;
	if(wsum - v[ind].S >= v[ind].F) return true;
	return false;
}

bool check(ll weight){
	// reset
	fill(sz, sz + MAXN, 1);
	for(int i = 0; i < MAXN; i++) wsz[i] = w[i];
	for(int i = 1; i < MAXN; i++) par[i] = i;
	v.clear();
	//
	
	for(auto edge : E){
		if(edge.S < weight){
			merge(edge.F.F, edge.F.S);
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(get_par(i) == i){
			v.pb({sz[i], wsz[i]});
		}
	}
	
	return valid();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll u, v, we;
	for(int i = 1; i < n; i++){
		cin >> u >> v >> we;
		E.pb({{u, v}, we});
	}
	for(int i = 1; i <= n; i++) cin >> w[i];
	
	ll dw = 0;
	ll up = 10001;
	ll mid;
	while(dw + 1 < up){
		mid = (dw + up) / 2;
		if(check(mid)) dw = mid;
		else up = mid;
	}
	cout << dw << '\n';
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