#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << '\n'; 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll N = 1e5 + 100;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;


vector<ll> G[MAXN];
ll dp1[MAXN], dp2[MAXN];
ll lf[MAXN];

ll mul(ll a , ll b){
	return (a * b) % MOD;
}
ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p % 2 == 0) return pw(mul(b,b), p / 2);
	return mul(b , pw(b, p - 1));
}

ll inv(ll x){
	return pw(x , MOD - 2);
}

int main(){
	ll n, p;
	cin >> n;
	for(int i = 2; i <= n; i++){
		cin >> p;
		lf[p] = 1;
		G[p].pb(i);		
	}
	for(int i = n; i > 0; i--){
		if(lf[i] == 0){
			dp1[i] = 1;
			dp2[i] = 1;
			continue;
		}
		ll z = 1;
		for(auto x : G[i]) z = (z * dp1[x]) % MOD;
		ll sm = 0;
		
		for(auto x : G[i]) sm += (dp1[x]);
		sm %= MOD;
		ll ans = 1;
		for(auto x : G[i]) ans = (ans * (dp1[x] + dp2[x])) % MOD;
		dp2[i] = ans - z;
		dp2[i] %= MOD;
		ll y = 0;
		for(auto x : G[i]){
			//debug(y);
			y += (((z * inv(dp1[x])) % MOD) * dp2[x]);
			y %= MOD;
		}
		//debug(y);
		dp1[i] = dp2[i] - y + z;
	}
	cout << ((dp1[1] % MOD) + MOD) % MOD;
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