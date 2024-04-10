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

ll ec = 0, ed = 0;

ll a, b;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	a = 0;
	b = 0;
	//ll ec = 0, ed = 0;
	ll big = 0, ans, res;
	
	cout << "? 0 0" << endl;
	cin >> big;
	for(int i = 29; i >= 0; i--){
		debug(big);
		if(big == 1){
			cout << "? " << ec + (1ll << i) << " " << ed + (1ll << i) << endl;
			cin >> res;
			if(res == 1){
				cout << "? " << ec + (1ll << i) << " " << ed << endl;
				cin >> res;
				if(res != 1){
					ec += (1ll << i);
					ed += (1ll << i);
				}
			} else {
				ec += (1ll << i);
				cout << "? " << ec << " " << ed << endl;
				cin >> big;
			}
		} else if (big == -1){
			cout << "? " << ec + (1ll << i) << " " << ed + (1ll << i) << endl;
			cin >> res;
			if(res == -1){
				cout << "? " << ec + (1ll << i) << " " << ed << endl;
				cin >> res;
				if(res != 1){
					ec += (1ll << i);
					ed += (1ll << i);
				}
			} else {
				ed += (1ll << i);
				cout << "? " << ec << " " << ed<< endl;
				cin >> big;
			}
		} else {
			cout << "? " << ec + (1ll << i) << " " << ed << endl;
			cin >> res;
			if(res == -1){
				ec += (1ll << i);
				ed += (1ll << i);
			}
		}
	}
	
	cout << "! " << ec << " " << ed << endl;
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