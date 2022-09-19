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
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN], LIS[MAXN], mn[MAXN];

void update(ll i){
	ll up, dw, mid;
	dw = 1;
	up = MAXN;
	while(dw + 1 < up){
		mid = (up + dw) / 2;
		if(mn[mid - 1] < a[i]) dw = mid;
		else up = mid;
	}
	LIS[i] = dw;
	return ;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n; 
	for(int i = 0;i < n; i++) cin >> a[i];


	ll lis = 1;
	fill(mn, mn + MAXN, INF);
	LIS[0] = 1;
	mn[1] = a[0];
	for(int i = 1; i < n; i++){
		update(i);
		mn[LIS[i]] = min(mn[LIS[i]], a[i]);
		lis = max(lis, LIS[i]);
	}
	cout << lis;
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