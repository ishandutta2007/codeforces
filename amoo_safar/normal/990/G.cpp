// ba ejaze ostad shahali1382 be elat eski

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef int ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll par[MAXN], val[MAXN], mark[MAXN];
long long cnt[MAXN];
long long sz[MAXN];
vector<ll> reset, divs[MAXN];
//set<ll> reset;

vector<pll> E[MAXN];

ll get_par(ll u){
	if(par[u] == u) return u;
	return par[u] = get_par(par[u]);
}
void merge(ll u, ll v){
	u = get_par(u); v = get_par(v);
	reset.pb(u);
	reset.pb(v);
	if(u == v) return ;
	par[u] = v;
	sz[v] += sz[u]; 
}

void count(ll g){
	reset.clear();
	for(int j = g; j < MAXN; j += g){
		for(auto ed : E[j]){
			merge(ed.F, ed.S);
		}
	}
	for(auto x : reset){
		if((par[x] == x) and (mark[x] != g)) {
			cnt[g] += ( (sz[x] * (sz[x] - 1) ) / 2 );
			mark[x] = g;
		}
	}
	for(auto x : reset){
		par[x] = x;
		sz[x] = 1;
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for(int i = 0; i < MAXN; i++) par[i] = i, sz[i] = 1;  

	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> val[i];
	ll s, e;
	for(int i = 1; i < n; i++){
		cin >> s >> e;
		//for(auto x : divs[ __gcd(val[s], val[e]) ]) E[x].pb({s, e});
		E[ __gcd(val[s], val[e]) ].pb({s, e});
	}
	
	for(int i = 1; i < MAXN; i++) count(i);
	
	for(int i = MAXN - 1; i > 0; i--){
		for(int j = i + i; j < MAXN; j += i){
			cnt[i] -= cnt[j];
		}
	}
	for(int i = 1; i <= n; i++) cnt[ val[i] ]++;
	for(int i = 1; i <= 200000; i++){
		if(cnt[i] > 0) cout << i << " " << cnt[i] << '\n';
	}
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