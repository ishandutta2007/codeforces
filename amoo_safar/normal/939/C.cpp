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
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0;i<n;i++) cin >> a[i];
	ll s, f;
	cin >> s >> f;
	ll su = 0;
	ll i = 0,j=0;
	for(int k = 0;k<f-s;k++){
		su += a[j];
		j++;
	}
	
	ll ma = su;
	ll ans2, ind = 0;
	ll ans = s - ind;
	while (ans <= 0)ans += n;
	
	for(int k = 1;k<n;k++){
		su -= a[i];
		su += a[j];
		i++;
		j++;
		if(su == ma){
			ans2 = s - i;
			while (ans2 <= 0) ans2 += n;
			ans = min(ans, ans2);
		}
		if(su > ma){
			ma = su;
			ind = i;
			ans = s - ind;
			while (ans <= 0)ans += n;
		}
		if(j==n)j =0;
	}
	//debug(ma);
	//debug(ind);
	
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