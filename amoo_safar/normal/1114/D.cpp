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
const ll MAXN = (ll) 5e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-12;

ll dp[MAXN][MAXN];
ll a[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i< n; i++) cin >> a[i];
	memset(dp, 31, sizeof dp);
	for(int i = 0; i < n; i++) dp[i][i + 1] = 0, dp[i][i] = 0;
	dp[n][n] = 0;
	for(int l = 2; l <= n; l++){
		for(int i = 0; i< n;i++){
			ll j = i + l;
			if(j > n) continue;
			dp[i][j] = min(dp[i +1 ][j] + 1, dp[i][j - 1] + 1);
			if(a[i] == a[i + 1]) dp[i][j] = min(dp[i][j], dp[i +1][j]);
			if(a[j - 1] == a[j - 2]) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			if(a[i] == a[j - 1]){
				dp[i][j] = min(dp[i + 1][j - 1] + 1, dp[i][j]);
			}
		}
	}
	
	cout << dp[0][n];
	return 0;
}


/*
6  3
1  1  3  3  3  5
10  2  3
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