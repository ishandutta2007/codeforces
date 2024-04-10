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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dp1[MAXN][MAXN], dp2[MAXN][MAXN], dp3[MAXN][MAXN], dp4[MAXN][MAXN], a[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	dp1[0][0] = a[0][0];
	for(int i = 1; i < m; i++) dp1[0][i] = dp1[0][i - 1] + a[0][i];
	for(int i = 1; i < n; i++) dp1[i][0] = dp1[i - 1][0] + a[i][0];
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++) dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + a[i][j];
	}
	
	
	dp2[0][m - 1] = a[0][m - 1];
	for(int i = m - 2; i >= 0; i--) dp2[0][i] = dp2[0][i + 1] + a[0][i];
	for(int i = 1; i < n; i++) dp2[i][m - 1] = dp2[i - 1][m - 1] + a[i][m - 1];
	for(int i = 1; i < n; i++){
		for(int j = m - 2; j >= 0; j--) dp2[i][j] = max(dp2[i - 1][j], dp2[i][j + 1]) + a[i][j];
	}
	
	dp3[n - 1][0] = a[n - 1][0];
	for(int i = 1; i < m; i++) dp3[n - 1][i] = dp3[n - 1][i - 1] + a[n - 1][i];
	for(int i = n - 2; i >= 0; i--) dp3[i][0] = dp3[i + 1][0] + a[i][0];
	for(int i = n - 2; i >= 0; i--){
		for(int j = 1; j < m; j++) dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + a[i][j];
	}
	
	dp4[n - 1][m - 1] = a[n - 1][m - 1];
	for(int i = m - 2; i >= 0; i--) dp4[n - 1][i] = dp4[n - 1][i + 1] + a[n - 1][i];
	for(int i = n - 2; i >= 0; i--) dp4[i][m - 1] = dp4[i + 1][m - 1] + a[i][m - 1];
	for(int i = n - 2; i >= 0; i--){
		for(int j = m - 2; j >= 0; j--) dp4[i][j] = max(dp4[i + 1][j], dp4[i][j + 1]) + a[i][j];
	}
	
	/*for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cerr << dp2[i][j] << " ";
		cerr << endl;
	}*/
	
	ll ans = 0;
	for(int i = 1; i < n - 1; i++){
		for(int j = 1; j < m - 1; j++) {
			//debug(i);
			//debug(j);
			ans = max(ans, dp1[i - 1][j] + dp2[i][j + 1] + dp3[i][j - 1] + dp4[i + 1][j]);
			ans = max(ans, dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] + dp4[i][j + 1]);
			//ans = max(ans, max(dp1[i - 1][j] + dp2[i][j + 1] + dp3[i][j - 1] + dp4[i + 1][j], dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] + dp4[i][j + 1]));
			//debug(ans);
		}
	}
	cout << ans;
	return 0;
}


/*
4 4
1 2 3 5
4 3 4 1
5 1 2 3
2 3 1 3

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