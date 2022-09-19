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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

map<ll, ll> par, xo;

void add(ll node){
	if(par[node] == 0){
		par[node] = node;
		xo[node] = 0;
	}
	return ;
}

ll get_par(ll node){
	ll x = par[node];
	if(x == node) return node;
	ll y = get_par(x);
	xo[node] = xo[node] ^ xo[x];
	par[node] = y;
	return par[node];
}

void merge(ll a, ll b, ll xx){
	ll x = get_par(a);
	ll y = get_par(b);
	if(x == y) return ;	
	if(x < y){
		par[x] = y;
		xo[x] = xo[a] ^ xo[b] ^ xx;
	} else {
		par[y] = x;
		xo[y] = xo[a] ^ xo[b] ^ xx;
	}
	return ;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll q, t, l, r, x, last = 0;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> t >> l >> r;
		
		l ^= last;
		r ^= last;
		if(l > r) swap(l, r);
		r++;
		
		add(l);add(r);
		
		if(t == 1){
			cin >> x;
			x ^= last;
			if(get_par(l) == get_par(r)) continue;
			merge(l, r, x);
			
		} else {
			if(get_par(l) != get_par(r)){
				cout << -1 << '\n';
				last = 1;
			} else {
				last = xo[l] ^ xo[r];
				cout << last << '\n';
			}
		}
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