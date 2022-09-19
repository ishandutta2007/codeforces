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
	ll n;
	cin >> n;
	str s;
	cout << "0 0" << endl;
	cin >> s;
	if(n == 1) return cout << "1 0 1 1", 0;
	ll dw = 0;
	ll up = (ll)1e9 + 1;
	ll mid;
	str t="w";
	for(int i = 1;i<n-1;i++){
		mid = (up + dw) / 2;
		cout << mid << " 0" << endl;
		cin >> t;
		if(s == t){
			dw = mid;
		} else up = mid;
		//debug(dw);
	}
	cout << dw + 1 << " 1" << endl;
	cin >> t;
	if(t == s) cout << dw + 1 << " 0 " << dw + 2 << " 1" << endl;
	else cout << dw + 1 << " 0 " << dw << " 1" << endl; 
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