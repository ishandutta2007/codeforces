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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 1e10;
const ld EPS = (ld) 1e-8;

ll n;
ll a[MAXN];

bool check(ll cnt){
	ll r = 0;
	for(int i = 0; i < n; i++){
		if(cnt < a[i]) return false;
		r += (cnt - a[i]);
	}
	if(r < cnt) return false;
	return true;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	ll dw = 0, up = INF;
	ll mid;
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