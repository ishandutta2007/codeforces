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
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][MAXN], ps[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, a, b, k, mid;
	cin >> n >> a >> b >> k;
	dp[0][a] = 1;
	for(int i = 1; i <= k; i++){
		ps[0] = 0;
		for(int j = 0; j <= n; j++) ps[j + 1] = (ps[j] + dp[i - 1][j]) % MOD;
		
		for(int j = 1; j < b; j++){
			mid = j + (b - j - 1) / 2;
			dp[i][j] = ( ps[mid + 1] - ps[0] - dp[i - 1][j] ) % MOD;
		}
		for(int j = b + 1; j <= n; j++){
			mid = j - (j - b - 1) / 2;
			dp[i][j] = ( ps[n + 1] - ps[mid] - dp[i - 1][j] ) % MOD;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans = ( ans + dp[k][i] ) % MOD;
	cout << ( ans + MOD ) % MOD;
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