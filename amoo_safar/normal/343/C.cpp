#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 2e10;
const ld EPS = (ld) 1e-8;

ll n, m;
ll h[MAXN];
ll p[MAXN];

ll read(ll i, ll l, ll r){
	if(l == r) return 0;
	if(l + 1 == r) return abs(h[i] - p[l]);
	return p[r - 1] - p[l] + min( abs(h[i] - p[l]), abs(h[i] - p[r - 1]) );
}

bool check(ll min){
	ll j = 0, k;
	for(int i = 0; i < n; i++){
		k = j;
		while(k <= m){
			if( read(i, j, k) > min) break;
			k++;
		}
		j = k - 1;
		if(j == m) return true;
	}
	return false;
	
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < m; i++) cin >> p[i];
	
	ll dw = -1, up = INF, mid;
	while(dw + 1 < up){
		mid = (dw + up) / 2;
		if( check(mid) ) up = mid;
		else dw = mid;
	}
	cout << up;
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