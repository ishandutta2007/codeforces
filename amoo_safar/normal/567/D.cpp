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

set<ll> s;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k, a;
	cin >> n >> k >> a;
	ll p = (n + 1) / (a + 1);
	s.insert(0);
	s.insert(n + 1);
	ll m;
	cin >> m;
	ll v;
	ll up, dw;
	//debug(p);
	for(int i = 1; i <= m; i++){
		cin >> v;
		up = *s.upper_bound(v);
		dw = *(--s.lower_bound(v));
		//debug(up);
		//debug(dw);
		p = p - ( (up - dw) / (a + 1) - ( (up - v) / (a + 1) + (v - dw) / (a + 1) ) );
		//debug(p);
		if(p < k) return cout << i, 0;
		s.insert(v);
	}
	cout << -1;
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