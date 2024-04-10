#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
#define int ll
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e4 + 10;
const ll INF = (ll) 10000000000ll;
const ld EPS = (ld) 1e-8;

ll a[17][MAXN];

ll d[17][17], dp[17][(1ll << 16)][17];

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
	
	ll mn;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		mn = INF;
		for(int k = 0; k < m; k++){
			mn =  min(mn, abs(a[i][k] - a[j][k]));
		}
		d[i][j] = mn;
		if(i == j) d[i][j] = INF;
	}
	//debug("BG");
	ll mk;
	
	for(int i = 0;i<n;i++) dp[i][(1ll << i)][i] = INF;
	
	for(int k = 1; k < (1ll << n); k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int l = 0; l < n; l++){
					if( (k ^ (1ll << l)) > k){
					
						mk = k + (1ll << l);
					
						dp[i][mk][l] = max(dp[i][mk][l], min(dp[i][k][j], d[l][j]));
					}
				}
			}
		}
	}
	
	ll val, ans = 0;
	ll u = (1ll << n) - 1ll;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		val = dp[i][u][j];
		for(int k = 0; k < m - 1; k++){
			val = min(val, abs(a[i][k + 1] - a[j][k]));
		}
		ans = max(val, ans);
	}
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