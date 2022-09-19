#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)
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

vector<ll> re;

ll ask(ll l, ll r){
	debug(r);
	cout << "1 " << r - l + 1 << " 1 ";
	for(int i = l; i <= r; i++) cout << i << " ";
	cout << endl;
	ll ans;
	cin >> ans;
	return ans;
}

int MAIN(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll f = ask(2, n);
	ll l = 1;
	ll r = n + 1;
	ll mid;
	while(l + 1 < r){
		mid = (l + r) / 2;
		if(ask(2, mid) == f) r = mid;
		else l = mid;
	}
	cout << "1 " << n - 1 << " " << r << " ";
	for(int i = 1; i <= n; i++) if(i != r) cout << i << " ";
	cout << endl;
	ll y;
	cin >> y;
	cout << "-1 " << y << endl;
	return 0;
}
int main(){
	ll T;
	cin >> T;
	while(T--) MAIN();
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