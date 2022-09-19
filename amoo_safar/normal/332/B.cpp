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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN], dp[MAXN], s[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < k; i++) s[0] += a[i];
	for(int i = 1; i + k <= n; i++) s[i] = s[i-1] - a[i - 1] + a[i + k - 1];
	dp[n - k] = n - k;
	for(int i = n - k - 1; i >= 0; i--){
		if(s[i] >= s[ dp[i + 1] ]) dp[i] = i;
		else dp[i] = dp[i + 1];
	}
	ll ans = 0;
	for(int i = 0; i <= n - k - k; i++){
		ans = max( ans, s[i] + s[ dp[i + k] ] );
	}
	for(int i = 0; i <= n - k - k; i++){
		if(ans == s[i] + s[ dp[i + k] ] ) return cout << i + 1 << " " << dp[i + k] + 1, 0;
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