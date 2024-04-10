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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
ll d[] = {1,1,2,3,1,3,2};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	
	ll ans = 0;
	for(int i = 0; i < 7; i++){
		ll aa = a;
		ll bb = b;
		ll cc = c;
		ll res = 0;
		for(int j = i; j < 7; j++){
			if(d[j] == 1) aa --;
			if(d[j] == 2) bb --;
			if(d[j] == 3) cc --;
			if(min({aa,bb,cc}) < 0) break;
			res ++;
		}
		//debug(res);
		if(min({aa,bb,cc}) < 0){
			ans = max(ans, res);
			continue;
		}
		ll mn = min({aa/3,bb/2,cc/2});
		res += 7*mn;
		aa -= (3ll * mn);
		bb -= (2ll * mn);
		cc -= (2ll * mn);
		for(int j= 0; j < 7; j++){
			if(d[j] == 1) aa --;
			if(d[j] == 2) bb --;
			if(d[j] == 3) cc --;
			if(min({aa,bb,cc}) < 0) break;
			res ++;
		}
		ans = max(ans, res);
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