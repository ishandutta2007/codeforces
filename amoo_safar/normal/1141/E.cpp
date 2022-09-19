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
const ll MAXN = (ll) 4e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll n;
ll a[MAXN], d[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll H;
	cin >>H >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	d[0] = a[0];
	for(int i = 1; i<n;i++) d[i] = a[i]  + d[i - 1];
	ll mn = *(min_element(d,d + n));
	if(H+mn > 0 and d[n - 1] >= 0) return cout << -1, 0;
	ll h = H + mn;
	if(h <= 0){
		for(int i = 0; i < n; i++){
			H += a[i];
			if(H <= 0) return cout << i + 1, 0;
		}
	}
	ll del = abs(d[n - 1]);
	
	ll k = (h + del - 1) / del;
	ll ans = k * n;
	//debug(del);
	//cout << ans;
	H -= (del * k);
	
		for(int i = 0; i < n; i++){
			H += a[i];
			if(H <= 0) return cout << ans + i + 1, 0;
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