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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 1e17;
const ld EPS = (ld) 1e-8;

ll a[MAXN], dp[5100][5100];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	for(int i = 0; i < 5100; i++) fill(dp[i], dp[i] + 5100, INF);
	
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	ll re = n % k;
	ll si = n / k;
	
	dp[0][0] = 0;
	for(int i = 1; i <= k; i++){
		dp[i][0] = dp[i-1][0] + a[i * si - 1] - a[(i - 1) * si];
		//debug(dp[i][0]);
		for(int j = 1; j <= re; j++){
			dp[i][j] = min( dp[i-1][j] + a[i * si - 1 + j] - a[(i - 1) * si + j], dp[i - 1][j - 1] + a[i * si - 1 + j] - a[(i - 1) * si + j - 1]);
			//debug(dp[i][j]);
		}
	}
	
	cout << dp[k][re] << endl;

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