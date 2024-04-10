#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 200 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;


ll pw(ll b, ll p){
	if(p == 0ll) return 1ll;
	b %= MOD;
	if(p % 2ll == 1ll) return (b * pw(b, p - 1ll)) % MOD;
	return pw(b * b, p / 2ll);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

const ll LOG = 150;

ll dp[LOG][MAXN][MAXN];
ll G[MAXN][MAXN];

vector<ll> bt;

ll a[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll kp = k;
	for(int i = 0; i < n; i++) cin >> a[i];
	ll c0 = 0;
	for(int  i = 0; i < n; i++) if(a[i] == 0) c0 ++;
	ll c00 = 0;
	for(int i = 0; i < n; i++) if((a[i] == 0) and (i < c0)) c00 ++;
	ll c1 = n - c0;
	ll m = n;
	n = c0 + 1;
	ll sm = 0;
	for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++){
		if(i == j){
			dp[0][i][j] = ( i * (c0 - i) ) + ((c0 - i) * (c1 - (c0 - i))  ) + (c0 * (c0 - 1) / 2ll) + ((c1 * (c1 - 1))/2ll);
		}
		if(i - 1 == j){
			dp[0][i][j] = (i * (c1 - (c0 - i)));
		}
		if(i + 1 == j){
			dp[0][i][j] = ((c0 - i) * (c0 - i));
		}
		G[i][j] = dp[0][i][j];
	}
	}
	while(k > 0){
		bt.pb(k % 2ll);
		k /= 2ll;
	}
	bt.pop_back();
	ll lg = 0;
	while(bt.size()){
		lg++;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int mid = 0; mid < n; mid ++){
					dp[lg][i][j] += (dp[lg - 1][i][mid] * dp[lg - 1][mid][j]);
					dp[lg][i][j] %= MOD;
				}
			}
		}
		if(bt.back() == 1){
			lg++;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					for(int mid = 0; mid < n; mid ++){
						dp[lg][i][j] += (dp[lg - 1][i][mid] * G[mid][j]);
						dp[lg][i][j] %= MOD;
					}
				}
			}
		}
		bt.pop_back();
	}
	ll ans = dp[lg][c00][c0] % MOD;
	
	cout << (ans * inv(pw(m * (m - 1ll) / 2ll, kp))) % MOD;
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