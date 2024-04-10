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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

pll a[MAXN];

ll f(str s){
	if(s == "USB") return 1;
	return 0;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll aa, b, c, m, mo;
	cin >> aa >> b >> c >> m;
	str t;
	for(int i = 0; i < m; i++){
		cin >> mo >> t;
		a[i] = mp(mo, f(t));
	}
	sort(a, a + m);
	ll ans = 0, co = 0;
	for(int i = 0; i < m; i++){
		if(a[i].S == 1){
			if(aa > 0){
				ans++;
				aa--;
				co += a[i].F;
			} else if(c > 0){
				ans++;
				c--;
				co += a[i].F;
			}
		}else{
			if(b > 0){
				ans++;
				b--;
				co += a[i].F;
			} else if(c > 0){
				c--;
				co += a[i].F;
				ans ++;
			}
		}
	}
	//debug(aa);
	//debug(b);
	//debug(c);
	cout << ans << " " << co;
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