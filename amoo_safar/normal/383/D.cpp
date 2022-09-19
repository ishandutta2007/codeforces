#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 1e9 + 7;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][20003];
ll a[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dp[0][10000] = 1;
	for(int i = 1; i <= n; i++){
		dp[i][10000] = 1;
		for(int j = 0; j < 20001; j++){
			if((j + a[i] <= 20000) and (j + a[i] >= 0)) {
				dp[i][j] += dp[i-1][j + a[i]];
			}
			if((j - a[i] >= 0) and (j - a[i] <= 20000)) {
				dp[i][j] += dp[i-1][j - a[i]];
			}
			//dp[i][j] += dp[i - 1][j];
			dp[i][j] %= MOD;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = ans + dp[i][10000] - 1;
		ans %= MOD;
	}
	cout << (ans + MOD) % MOD;
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