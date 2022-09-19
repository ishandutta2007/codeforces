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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll par[MAXN], sz[MAXN], ln[MAXN], pw[MAXN];
pair<pll, ll> a[MAXN];

ll get_par(ll node){
	if(node == par[node]) return node;
	par[node] = get_par(par[node]);
	return par[node];
}

void merge(ll a, ll b){
	ll x = get_par(a);
	ll y = get_par(b);
	if(x == y) return ;
	ln[y] += ln[x];
	sz[y] += sz[x];
	par[x] = y;
}

bool CMPx(pair<pll, ll> a, pair<pll, ll> b){
	return a.F.F < b.F.F;
}

bool CMPy(pair<pll, ll> a, pair<pll, ll> b){
	return a.F.S < b.F.S;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 0; i < MAXN; i++) par[i] = i;
	pw[0] = 1;
	for(int i = 1; i < MAXN; i++) pw[i] = (pw[i - 1] * 2ll) % MOD;
	fill(sz, sz + MAXN, 1);
	
	
	ll n;
	scanf("%lld", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &a[i].F.F, &a[i].F.S);
		a[i].S = i;
	}
	sort(a, a + n, CMPx);
	ln[get_par(a[0].S)] ++;
	for(int i = 1; i < n; i++){
		if(a[i].F.F == a[i - 1].F.F){
			merge(a[i].S, a[i - 1].S);
		} else {
			ln[get_par(a[i].S)]++;
		}
	}
	
	sort(a, a + n, CMPy);
	ln[get_par(a[0].S)] ++;
	for(int i = 1; i < n; i++){
		if(a[i].F.S == a[i - 1].F.S){
			merge(a[i].S, a[i - 1].S);
		} else {
			ln[get_par(a[i].S)]++;
		}
	}
	
	ll ans = 1;
	for(int i = 0; i < n; i++){
		if(par[i] == i){
			//debug(i);
			//debug(ln[i]);
			//debug(sz[i]);
			if(ln[i] <= sz[i]){
				ans *= pw[ln[i]];
			} else {
				ans *= (pw[ln[i]] - 1);
			}
			ans %= MOD;
		}
	}
	printf("%lld", ans);
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