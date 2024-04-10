#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n';
//#define int ll
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll LOG = (ll) 25;

ll a[MAXN];
map<ll, ll> mp, rev;
ll dp[2][2 * LOG];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll b = 1;
	for(int i = 1; i < LOG; i++){
		if((1ll << i) <= n) b = (1ll << i);
	}	
	ll c = 3 * (b / 2ll);
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		if((b % i == 0) || ((c <= n) && (c % i == 0))){
			mp[i] = cnt ++;
			rev[mp[i]] = i;
		}
	}
	
	dp[1][mp[b]] = 1;
	if(c <= n) dp[1][mp[c]] = 1;
	ll d, z, ii;
	for(int i = 2; i <= n; i++){
		ii = i & 1;
		memset(dp[ii], 0, sizeof dp[ii]);
		for(int j = 0; j < cnt; j++){
			d = rev[j];
			z = n / d;
			if(i > z) continue;
			dp[ii][j] = dp[ii ^ 1][j] * (z - (i - 1));
			if(mp.count(2 * d)) dp[ii][j] += (dp[ii ^ 1][mp[d + d]] * (z - (n / (d + d))));
			if(mp.count(3 * d)) dp[ii][j] += (dp[ii ^ 1][mp[d + d + d]] * (z - (n / (d + d + d))));
			dp[ii][j] %= MOD;
		}
	}
	cout << dp[n & 1][mp[1]] << '\n';
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