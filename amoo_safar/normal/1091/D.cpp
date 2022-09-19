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

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;


ll pw(ll b, ll p){
	if(p == 0) return 1;
	b %= MOD;
	if(p % 2 == 1) return (b * pw(b, p - 1)) % MOD;
	return pw(b * b, p / 2);
}

ll fact[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fact[0] = 1;
	for(ll i = 1;i<MAXN;i++)fact[i] = (i * fact[i-1]) % MOD;
	ll n;
	cin >> n;
	ll ans = fact[n];
	ll c = n;
	for(int i = n - 1;i >= 2; i--){
		ans += (fact[n] - c);
		ans %= MOD;
		c*=i;
		c%=MOD;
		//debug(ans);
	}
	cout<<((ans%MOD)+MOD)%MOD;
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