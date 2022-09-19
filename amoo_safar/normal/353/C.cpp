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

ll a[MAXN];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	str s;
	cin >> s;
	ll ans = 0;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1') ans += a[i];
		sum += a[i];
	}
	ll sum2 = 0;
	for(int i = n - 1; i >= 0; i--){
		sum -= a[i];
		if(s[i] == '1'){
			ans = max(ans, sum + sum2);
			sum2 += a[i];
		}
	}
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