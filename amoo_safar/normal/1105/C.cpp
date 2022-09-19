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

ll dp[MAXN][3];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, l, r;
	cin >> n >> l >> r;
	l --;
	ll b0 = (r / 3) - (l / 3); 
	r++;
	l++;
	ll b2 = (r / 3) - (l / 3); 
	r++;
	l++;
	ll b1 = (r / 3) - (l / 3); 
	r++;
	l++;
	
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			dp[i + 1][j] += (dp[i][j] * b0);
			dp[i + 1][(j + 1) % 3] += (dp[i][j] * b1);
			dp[i + 1][(j + 2) % 3] += (dp[i][j] * b2);
			for(int k = 0; k<3;k++) dp[i + 1][k] %= MOD;
		}
	}
	cout << dp[n][0] % MOD;
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