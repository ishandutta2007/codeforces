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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN], ttm[MAXN], pl[MAXN], pr[MAXN];

ll getl(ll x){
	if(pl[x] == x) return x;
	return pl[x] = getl(pl[x]);
}

ll getr(ll x){
	if(pr[x] == x) return x;
	return pr[x] = getr(pr[x]);
}

void pk(ll u ,ll t){
	ttm[u] = t;
	pr[u] = u + 1;
	pl[u] = u - 1;
}
ll ind[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < MAXN; i++) pr[i] = pl[i] = i;
	ll n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ind[a[i]] = i;
	}
	ll nw = 1;
	for(int i = n; i > 0; i--){
		if(ttm[ind[i]] > 0) continue;
		pk(ind[i], nw);
		ll x = getl(ind[i]);
		for(int j = 0; j < k; j++){
			x = getl(x);
			if(x == 0) break;
			pk(x, nw);
			x--;
		}
		x = getr(ind[i]);
		for(int j = 0; j < k; j++){
			x = getr(x);
			if(x == n + 1) break;
			pk(x, nw);
			x++;
		}
		nw = 3 - nw;
	}
	for(int i = 1; i<= n; i++) cout << ttm[i];
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