#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll x1, x2, y1, y2, n;
str s;

bool check(ll m){
	ll x = 0, y = 0;
	for(int i = 0; i < n; i++){
		ll cnt = m / n;
		if(i + 1 <= m % n) cnt ++;
		if(s[i] == 'U') y += cnt;
		if(s[i] == 'L') x -= cnt;
		if(s[i] == 'R') x += cnt;
		if(s[i] == 'D') y -= cnt;
	}
	return abs(x - x2) + abs(y - y2) <= m;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> n;
	cin >> s;
	x2 -= x1;
	x1 -= x1;
	y2 -= y1;
	y1 -= y1;
	
	ll l = -1;
	ll r = INF;
	ll mid;
	while(l + 1 < r){
		mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	if(r == INF) cout << -1;
	else cout << r;
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