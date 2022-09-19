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
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;



int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n1,n2,n3,p1,p2,p3;
	str s;
	cin >> s;
	cin >> n1 >> n2 >> n3 >> p1 >> p2 >> p3;
	ll low = 0, up = (ll) 1e14 + 10;	
	ll x1 = 0, x2 = 0, x3 = 0;
	ll r;
	cin >> r;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'B') x1 ++;
		if(s[i] == 'S') x2 ++;
		if(s[i] == 'C') x3 ++;
	}
	while(up - low > 1){
		ll mid = (up + low) / 2;
		ll pr =  p1 * max(0ll, mid*x1 - n1) + p2 * max(0ll, mid*x2 - n2) + p3 * max(0ll, mid*x3 - n3);
		if(pr > r){
			up = mid;
		} else {
			low = mid;
		}
	}
	cout << low;
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