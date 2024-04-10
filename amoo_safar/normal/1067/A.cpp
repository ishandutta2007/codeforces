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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
ll dp[2][210][2];
ll ps0[210], ps1[210];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	a[0] = 0;
	a[n + 1] = 0;
	for(int i = 1;i <=n;i++) cin >> a[i];
	
	if(a[1] != -1){
		dp[1][a[1]][0] = 1;
	} else {
		for(int i = 1; i <= 200; i++) dp[1][i][0] = 1;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1;j <= 200;j++){
			dp[i & 1][j][0] = 0;
			dp[i & 1][j][1] = 0;
		}
		if(a[i] != -1){
			for(int j = 1; j < a[i]; j ++){
				dp[i & 1][a[i]][0] += (dp[i & 1 ^ 1][j][0] + dp[i & 1 ^ 1][j][1]);
				dp[i & 1][a[i]][0] %= MOD;
			}
			
			dp[i & 1][a[i]][1] = (dp[i & 1 ^ 1][a[i]][1] + dp[i & 1 ^ 1][a[i]][0])%MOD;
			for(int j = a[i] + 1; j <= 200;j++){
				dp[i & 1][a[i]][1] += dp[i & 1 ^ 1][j][1];
				dp[i & 1][a[i]][1] %= MOD;
			}
			continue;
		}
		
		ps0[0] = 0;
		ps1[0] = 0;
		for(int j = 1;j <= 200; j++){
			ps0[j] = ps0[j - 1] + dp[i & 1 ^ 1][j][0];
			ps0[j] %= MOD;
			ps1[j] = ps1[j - 1] + dp[i & 1 ^ 1][j][1];
			ps1[j] %= MOD;
		}
		for(int j = 1;j <= 200; j++){
			dp[i & 1][j][0] = ps0[j - 1] + ps1[j - 1];
			dp[i & 1][j][0] %= MOD;
			dp[i & 1][j][1] = dp[i & 1 ^ 1][j][0] + ps1[200] - ps1[j - 1];
			dp[i & 1][j][1] %= MOD;
		}
	}
	//debug(dp[2][2][0]);
	ll ans = 0;
	for(int i = 1;i<=200;i++) {
		ans += dp[n & 1][i][1];
		ans %= MOD;
	}
	cout << (ans + MOD) %MOD;
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