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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e2 + 10;
const ll INF = (ll) 1e9 + 7;
const ld EPS = (ld) 1e-8;

ll dp[62][MAXN][MAXN];
ll out[62][MAXN][MAXN];
ll a[MAXN];

ll pop_count(ll n){
	ll ans = 0;
	while(n > 0){
		if(n % 2ll == 1ll) ans ++;
		n /= 2ll;
	}
	return ans;
}

int main(){
	for(int i = 0; i < MAXN; i++) out[0][i][i] = 1;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, l;
	cin >> n >> l;
	l --;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(pop_count( (a[i] ^ a[j]) ) % 3 == 0) dp[0][i][j] = 1;
		}
	}
	
	for(int k = 1; k < 62; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k2 = 0; k2 < n; k2++){
					dp[k][i][j] += (dp[k-1][i][k2] * dp[k-1][k2][j]);
					dp[k][i][j] %= MOD;
				}
			}
		}
	}
	//for(int i = 0; i < n; i++){
		//for(int j = 0; j < n;j++) cout << dp[0][i][j] << " " << i << " " << j << endl;
	//}
	ll cnt = 0;
	ll last = 0;
	while(l > 0){
		debug(l);
		if(l % 2ll == 1ll){
			debug(cnt);
			last ++;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					for(int k = 0; k < n; k++){
						out[last][i][j] += (out[last - 1][i][k] * dp[cnt][k][j]);
						out[last][i][j] %= MOD;
					}
				}
			}
		}
		cnt ++;
		l /= 2ll;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans += out[last][i][j];
			ans %= MOD;
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