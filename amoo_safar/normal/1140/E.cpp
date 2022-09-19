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
const ll MAXN = (ll) 3e5 + 100;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

vector<ll> a, b;
ll nx[MAXN];
ll dp1[MAXN], dp2[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll v;
	for(int i = 0; i< n;i++){
		cin >> v;
		if(i % 2 == 0) a.pb(v);
		else b.pb(v);
	}
	ll m = a.size();
	ll la = INF;
	for(int i = m - 1; i >= 0; i--){
		nx[i] = la;
		if(a[i] != -1) la = a[i];
	}
	a.pb(-INF);
	if(a[0] == -1){
		dp1[0] = k - 1;
		dp2[0] = 1;
	} else {
		if(a[0] == nx[0]) dp2[0] = 1;
		else dp1[0] = 1;
	}
	
	for(int i = 1; i < m; i++){
		if(nx[i] == INF){
			dp2[i] = 0;
			if(a[i] == -1){
				dp1[i] = dp1[i - 1] * (k - 1);
				dp1[i] %= MOD;
			} else {
				dp1[i] = dp1[i - 1];
			}
		}
		if(a[i] == -1){
			dp2[i] = dp1[i - 1];
			dp2[i] % MOD;
			dp1[i] = (dp1[i - 1] * (k - 2) ) + (dp2[i - 1] * (k - 1));
			dp1[i] %= MOD;
		} else {
			if(a[i] == nx[i]){
				dp1[i] = 0;
				dp2[i] = dp1[i - 1];
			} else {
				dp2[i] = 0;
				dp1[i] = dp1[i - 1];
			}
		}
	}
	ll ans = dp1[m - 1] + dp2[m - 1];
	ans %= MOD;
	debug(ans);
	a.clear();
	for(auto x : b) a.pb(x);
	
	memset(dp1, 0, sizeof dp1);
	memset(dp2, 0, sizeof dp2);
	
	m = a.size();
	la = INF;
	for(int i = m - 1; i >= 0; i--){
		nx[i] = la;
		if(a[i] != -1) la = a[i];
	}
	a.pb(-INF);
	if(a[0] == -1){
		dp1[0] = k - 1;
		dp2[0] = 1;
	} else {
		if(a[0] == nx[0]) dp2[0] = 1;
		else dp1[0] = 1;
	}
	
	for(int i = 1; i < m; i++){
		if(nx[i] == INF){
			dp2[i] = 0;
			if(a[i] == -1){
				dp1[i] = dp1[i - 1] * (k - 1);
				dp1[i] %= MOD;
			} else {
				dp1[i] = dp1[i - 1];
			}
		}
		if(a[i] == -1){
			dp2[i] = dp1[i - 1];
			dp2[i] % MOD;
			dp1[i] = (dp1[i - 1] * (k - 2) ) + (dp2[i - 1] * (k - 1));
			dp1[i] %= MOD;
		} else {
			if(a[i] == nx[i]){
				dp1[i] = 0;
				dp2[i] = dp1[i - 1];
			} else {
				dp2[i] = 0;
				dp1[i] = dp1[i - 1];
			}
		}
	}
	
	ans *= (dp1[m - 1] + dp2[m - 1]);
	ans %= MOD;
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