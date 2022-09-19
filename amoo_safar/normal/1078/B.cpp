#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e2 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][MAXN * MAXN], dp_tmp[MAXN][MAXN * MAXN];

map<ll, ll> m;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	ll v;
	for(int i = 0; i < n; i++){
		cin >> v;
		m[v] ++;
	}
	dp[0][0] = 1;
	
	ll cnt, val;
	for(auto x : m){
		val = x.F;
		cnt = x.S;
		for(int i = 0; i < MAXN; i++){
			for(int j = 0; j < MAXN * MAXN; j++) dp_tmp[i][j] = dp[i][j];
		}
		
		for(int i = 1; i <= cnt; i++){
			for(int j = n; j >= 0; j--){
				for(int k = 0; k <= 10000; k++){
					if(i * val > k) continue;
					if(i > j) continue;
					dp_tmp[j][k] += dp[j - i][k - (i * val)];
					dp_tmp[j][k] = min(2ll, dp_tmp[j][k]);
				}
			}
		}
	
		for(int i = 0; i < MAXN; i++){
			for(int j = 0; j < MAXN * MAXN; j++) dp[i][j] = dp_tmp[i][j];
		}
	}
	ll s = m.size();
	//debug(s);
	if(s == 1) return cout << n, 0;
	
	if(s == 2){
		ll fl = 0;
		for(auto x : m){
			if(dp[x.S][x.F * x.S] == 1){
				fl = 1;
			}
		}
		if(fl == 1) return cout << n, 0;
	}
	ll ans = 1;
	for(auto x : m){
		val = x.F;
		cnt = x.S;
		for(int i = 1; i <= cnt; i++){
			if(dp[i][i *  val] == 1) ans = max(ans, (ll)i);
		}
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