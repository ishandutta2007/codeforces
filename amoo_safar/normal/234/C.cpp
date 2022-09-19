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

ll a[MAXN], l[MAXN], r[MAXN];

ll neg(ll x){
	if(x < 0) return 1;
	return 0;
}
ll pos(ll x){
	if(x > 0) return 1;
	return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	l[0] = neg(a[0]);
	for(int i = 1; i < n; i++) l[i] = l[i - 1] + neg(a[i]);
	r[n - 1] = pos(a[n - 1]);
	for(int i = n - 2; i >= 0; i--) r[i] = r[i + 1] + pos(a[i]);
	ll ans = n;
	for(int i = 0; i < n - 1; i++) ans = min(ans, n - l[i] - r[i + 1]);
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