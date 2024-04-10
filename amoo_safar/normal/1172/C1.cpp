#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353;
const ll MAXN = (ll) 52;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll LOG = (ll) 30;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}
ll add(ll a ,ll b){
	return (a + b) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b , p - 1));
	return pw(mul(b, b), p >> 1);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

ll dp[MAXN][MAXN][MAXN], a[MAXN], w[MAXN], n, m;

void solve(ll idx){
	memset(dp, 0, sizeof dp);
	ll pw = 0, nw = 0, sw = 0;
	for(int i = 1; i <= n; i++){
		sw += w[i];
		if(i == idx) continue;
		if(a[i] == 1) pw += w[i];
		else nw += w[i];
	}
	dp[0][0][0] = 1;
	int l, W, iv, C;
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k + j <= i; k++){
				l = i - j - k;
				W = sw + k - l + (a[idx] == 0 ? -j : j);
				iv = inv(W);
				C = mul(iv, dp[i][j][k]);
				if(l > nw) continue;
				if(a[idx] == 0 and j > w[idx]) continue;
				
				dp[i + 1][j][k] = add(dp[i + 1][j][k], mul( C, nw - l ));
				dp[i + 1][j + 1][k] = add(dp[i + 1][j + 1][k], mul( C, w[idx] + (a[idx] == 0 ? -j : j)));
				dp[i + 1][j][k + 1] = add(dp[i + 1][j][k + 1], mul( C, pw + k));
			}
		}
	}
	ll ans = 0;
	for(int j = 0; j <= m; j++){
		for(int k = 0; k + j <= m; k++){
			l = m - j - k;
			if(l > nw) continue;
			if(a[idx] == 0 and j > w[idx]) continue;
			ans  = add(ans, mul(dp[m][j][k], w[idx] + (a[idx] == 0 ? -j : j)));
		}
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) solve(i);
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