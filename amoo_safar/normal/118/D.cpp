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

const ll MOD = (ll) 1e8;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dp1[201][201][11], dp2[201][201][11];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	dp1[1][1][1] = 1;
	dp2[1][1][1] = 1;
	for(int i = 2; i <= n1 + n2; i++){
		for(int j = 1; j <= n1; j++){
			if(j > i) continue;
			
			dp1[i][j][1] = 0;
			for(int k = 1; k <= k2; k++) dp1[i][j][1] = (dp1[i][j][1] + dp2[i - 1][i - j][k]) % MOD;
			
			for(int k = 2; k <= k1; k++){
				dp1[i][j][k] = dp1[i - 1][j - 1][k - 1];
			}
		}
		
		for(int j = 1; j <= n2; j++){
			if(j > i) continue;
			
			dp2[i][j][1] = 0;
			for(int k = 1; k <= k1; k++) dp2[i][j][1] = (dp2[i][j][1] + dp1[i - 1][i - j][k]) % MOD;
			
			for(int k = 2; k <= k2; k++){
				dp2[i][j][k] = dp2[i - 1][j - 1][k - 1];
			}
		}
	}
	
	ll ans = 0;
	for(int k = 1; k <= k1; k++) ans = (ans + dp1[n1 + n2][n1][k]) % MOD;
	for(int k = 1; k <= k2; k++) ans = (ans + dp2[n1 + n2][n2][k]) % MOD;
	
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