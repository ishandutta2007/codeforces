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

ld dis(ld x1,ld y1,ld x2,ld y2){
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

ld di(ld x1,ld y1,ld x2,ld y2){
	return abs(x1-x2) + abs(y1-y2);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b, c;
	cin >> a >> b >> c;
	
	ld x1, y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ld ans = abs(x1- x2) + abs(y1 - y2);
	
	if(a == 0 or b == 0) return cout << setprecision(16) << ans, 0;
	
	ld xx1,yy1,xx2,yy2;
	for(int i = 0;i < 2;i++){
		if(i == 0){
			xx1 = x1;
			yy1 = (a * x1 + c) / (-b);
		} else {
			yy1 = y1;
			xx1 = (b * y1 + c) / (-a);
		}
		for(int j = 0;j<2;j++){
			if(j == 0){
				xx2 = x2;
				yy2 = (a * x2 + c) / (-b);
			} else {
				yy2 = y2;
				xx2 = (b * y2 + c) / (-a);
			}
			
			ans = min(ans, dis(xx1,yy1,xx2,yy2) + di(x1,y1,xx1,yy1) + di(x2,y2,xx2,yy2) );
			//cout << setprecision(16) << dis(xx1,yy1,xx2,yy2)<< endl;// + di(x1,y1,xx1,yy1) + di(x2,y2,xx2,yy2) << endl;
		}
		//cout << setprecision(16) << ans << endl;
	}
	cout << setprecision(16) << ans;
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