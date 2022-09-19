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

ll dpr[MAXN], dpl[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	str s, t;
	cin >> s >> t;
	ll n = s.size();
	ll m = t.size();
	
	ll p;
	
	dpl[n] = m;
	for(int i = n - 1; i >= 0;i--){
		p = dpl[i + 1];
		if(p == 0) {
			dpl[i] = p;
			continue;
		}
		if(t[p - 1] == s[i]) dpl[i] = p - 1;
		else dpl[i] = p;
	}
	
	
	dpr[0] = -1;
	for(int i = 1; i <= n; i++){
		p = dpr[i - 1];
		//debug(p);
		if(p == m - 1) {
			dpr[i] = m - 1;
			continue;
		}
		if(t[p + 1] == s[i - 1]) dpr[i] = p + 1;
		else dpr[i] = p;
	}

	ll ans = 0;
	ll ind = -1;
	for(int i = 0;i <= n; i++){
		if(ans < dpr[i] + 1 + m - dpl[i]){
			ind = dpr[i] + 1;
		}
		ans = max(ans, dpr[i] + 1 + m - dpl[i] );
	}
	if(ans == 0)return cout << "-",0;
	if(ans >= m) return cout << t, 0;

	else {
		for(int i = 0;i<ind;i++) cout << t[i];
		for(int i = m-(ans-ind); i < m;i++) cout << t[i]; 
	}
	//cout << min(m, ans);
	/*dpr[0] = 0;
	for(int i = 0; i < n; i++){
		for(int)
	}*/

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