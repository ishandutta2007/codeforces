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



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str  s;
	cin >> s;
	ll n= s.size();
	ll p1 = 0;
	str s1 = "[:";
	
	ll e1, e2;
	for(int i = 0; i <n ;i++){
		if(s[i] == s1[p1]) p1++;
		if(p1 == 2){
			e1 = i;
			break;
		}
	}
	if(p1 < 2) return cout << -1, 0;
	ll p2 = 0;
	str s2 = "]:";
	for(int i = n - 1; i >= 0 ; i--){
		if(s[i] == s2[p2]) p2++;
		if(p2 == 2){
			e2 = i;
			break;
		}
	}
	if(p2 < 2) return cout << -1, 0;
	if(e2 <= e1) return cout << -1, 0;
	ll ans = 4;
	for(int i = e1 + 1; i < e2; i++){
		if(s[i] == '|') ans ++;
	}
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