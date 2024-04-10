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

ll p[MAXN][5];
ll a[MAXN][MAXN];
ll dp[MAXN];
int main(){
	for(int i = 0; i < MAXN; i++) fill(a[i], a[i] + MAXN, 1);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for(int i = 0;i < k; i++){
		for(int j = 0; j < n; j++) cin >> p[j][i];
	}
	//debug(n);
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			for(int j2 = 0; j2 < j; j2++){
				a[p[j2][i]][p[j][i]] = 0;
			}
		}
	}
	//debug(n);
	ll m = 1;
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[p[i][0]][p[j][0]] == 1) dp[i] = max(dp[i], dp[j] + 1);
		}
		 m = max(m, dp[i]);
	}
	cout << m;

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