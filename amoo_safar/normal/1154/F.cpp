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

ll mxf[MAXN];
ll a[MAXN], dp[MAXN], ps[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	 ll x,  y;
	for(int i = 0; i < m;i++){
		cin >> x >> y;
		mxf[x] = max(mxf[x], y);
	}
	sort(a + 1 , a + n + 1);
	memset(dp, 31, sizeof dp);
	dp[0] = 0;
	
	for(int i = 1; i <= k; i++){
		ps[0] = 0;
		for(int j = i; j >= 0; j--) ps[i - j + 1] = ps[i - j] + a[j];
		for(int sz = 1; sz <= i; sz++){
			dp[i] = min(dp[i], dp[i - sz] + ps[ sz - mxf[sz] ]);
		}
		//debug(dp[i]);
	}
	//debug(dp[1]);
	cout << dp[k];
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