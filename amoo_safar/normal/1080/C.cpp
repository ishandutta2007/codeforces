#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll cw(ll x1, ll y1, ll x2, ll y2){
	if(x1 > x2 or y1 > y2) return 0;
	ll s = (abs(x2-x1)+1) * (abs(y2-y1)+1);
	s = max(0ll, s);
	if(s%2==0) return s/2;
	else return s/2 + ( (x1+y1) % 2 == 0 ? 1 : 0);
}

ll cb(ll x1, ll y1, ll x2, ll y2){
	if(x1 > x2 or y1 > y2) return 0;
	ll s = (x2-x1+1) * (y2-y1+1);
	s = max(0ll, s);
	if(s%2==0) return s/2;
	else return s/2 + ( (x1+y1) % 2 == 0 ? 0 : 1);
}

void MAIN(){
	ll n, m;
	cin >> n >> m;
	ll x1,x2,y1,y2,x3,y3,x4,y4,x5,y5,x6,y6;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	ll w = cw(1, 1,n,m);
	ll b = cb(1, 1,n,m);
	//debug(w);
	//debug(b);
	w += cb(x1, y1, x2, y2);
	b -= cb(x1, y1, x2, y2);
	
	w -= cw(x3, y3, x4, y4);
	b += cw(x3, y3, x4, y4);
	
	ll xx1 = max(x3, x1);
	ll yy1 = max(y1, y3);
	ll xx2 = min(x2, x4);
	ll yy2 = min(y2, y4);
	
	w -= cb(xx1,yy1,xx2,yy2);
	b += cb(xx1,yy1,xx2,yy2);
	
	cout << w << " " << b <<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		MAIN();
	}

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