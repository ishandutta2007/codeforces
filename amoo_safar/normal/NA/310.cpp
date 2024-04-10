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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;


ll dis(ll x1, ll y1, ll x2, ll y2){
	return abs(x1- x2) + abs(y1 - y2);
}
set<pll> an;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x1, y1;
	cin >> x1 >> y1;
	ll x2, y2;
	cin >> x2 >> y2;
	ll x3, y3;
	cin >> x3 >> y3;
	ll xa = -1, ya = -1;
	ll ans = INF;
	for(int i = 0; i<=1000;i++){
		for(int j = 0;j<=1000;j++){
			ll d = dis(x3,y3,i,j) +dis(x2,y2,i,j)+dis(x1,y1,i,j);
			if(d < ans){
				ans = d;
				xa = i;
				ya = j;
			}
		}
	}
	//debug(xa);
	//debug(ya);	
	for(int i = min(xa,x1); i<=max(xa,x1); i++) an.insert({i, min(ya,y1)});
	for(int i = min(ya,y1);i<=max(ya,y1); i++) an.insert({ (min(ya,y1) == ya ? x1 : xa), i });
	
	x1 = x2;
	y1 = y2;
	
	for(int i = min(xa,x1); i<=max(xa,x1); i++) an.insert({i, min(ya,y1)});
	for(int i = min(ya,y1);i<=max(ya,y1); i++) an.insert({ (min(ya,y1) == ya ? x1 : xa), i });
	
	x1 = x3;
	y1 = y3;
	
	for(int i = min(xa,x1); i<=max(xa,x1); i++) an.insert({i, min(ya,y1)});
	for(int i = min(ya,y1);i<=max(ya,y1); i++) an.insert({ (min(ya,y1) == ya ? x1 : xa), i });
	cout << an.size() << '\n';
	for(auto x : an) cout << x.F << " " << x.S << '\n';
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