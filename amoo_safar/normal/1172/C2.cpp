#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
#define int ll
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353;
const ll MAXN = (ll) 3e3 + 10;
const ll N = 2e5 + 10;
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

ll dp[MAXN][MAXN], a[N], w[N], n, m;

pll solve(){
	memset(dp, 0, sizeof dp);
	ll pw = 0, nw = 0, sw = 0;
	for(int i = 1; i <= n; i++){
		sw += w[i];
		if(a[i] == 1) pw += w[i];
		else nw += w[i];
	}
	ll j= 0;
	dp[0][0] = 1;
	int l, W, iv, C;
	for(int i = 0; i < m; i++){
			for(int k = 0; k <= i; k++){
				l = i - k;
				W = sw + k - l;
				iv = inv(W);
				C = mul(iv, dp[i][k]);
				if(l > nw) continue;
				dp[i + 1][k] = add(dp[i + 1][k], mul( C, nw - l ));
				//dp[i + 1][j + 1][k] = add(dp[i + 1][j + 1][k], mul( C, w[idx] + (a[idx] == 0 ? -j : j)));
				dp[i + 1][k + 1] = add(dp[i + 1][k + 1], mul( C, pw + k));
			}
	}
	ll ansp = 0, ansn = 0;
		for(int k = 0; k <= m; k++){
			l = m - k;
			if(l > nw) continue;
			ansp = add(ansp, mul(dp[m][k], pw + k));
			ansn = add(ansn, mul(dp[m][k], nw - l));
		}
	return {ansp, ansn};
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> w[i];
	pll res = solve();
	ll pw = 0, nw = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1) pw += w[i];
		else nw += w[i];
	}
	ll ivp = inv(pw);
	ll ivn = inv(nw);
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			cout << mul(mul(w[i], ivp), res.F) << '\n';
		} else {
			cout << mul(mul(w[i], ivn), res.S) << '\n';
		}
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