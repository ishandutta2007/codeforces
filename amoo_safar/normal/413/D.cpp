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
const ll MAXN = (ll) 2e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][2048];
ll pw[MAXN], cnt[MAXN];
ll a[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for(int i = 1; i < MAXN; i++) pw[i] = (pw[i - 1] << 1) % MOD;
	ll n, k;
	cin >> n >> k;
	k = (1ll << k);
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll c0 = 0;
	for(int i = n; i >= 0; i--){
		cnt[i] = c0;
		if(a[i] == 0) c0 ++;
	}
	if(a[1] == 2){
		dp[1][2] = 1;
	}
	if(a[1] == 4){
		dp[1][4] = 1;
	}
	if(a[1] == 0){
		dp[1][2] = dp[1][4] = 1;
	}
	ll ans = 0;
	for(int i = 1; i < n; i++){
		for(int j = 2; j < 2048; j++){
			if(dp[i][j] == 0) continue;
			
			ll nx = a[i + 1];
			if(nx != 4){
				ll sm = j + 2;
				if(sm >= k){
					//debug(cnt[i + 1]);
					//debug(dp[i][j]);
					ans += (pw[cnt[i + 1]] * dp[i][j]);
					ans %= MOD;
				} else {
					dp[i + 1][sm] += dp[i][j];
					dp[i + 1][sm] %= MOD;
				}
			}
			if(nx != 2){
				if(j % 4 == 2){
					dp[i + 1][4] += dp[i][j];
				} else {
					ll sm = j + 4;
					if(sm >= k){
						//debug(cnt[i + 1]);
						
						//debug(dp[i][j]);
						ans += (pw[cnt[i + 1]] * dp[i][j]);
						ans %= MOD;
					} else {
						dp[i + 1][sm] += dp[i][j];
						dp[i + 1][sm] %= MOD;
					}
				}
			}
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