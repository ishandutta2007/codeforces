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
const ll MAXN = (ll) 2e2 + 10;
const ll INF = (ll) 1e15;
const ld EPS = (ld) 1e-8;

deque<ll> de;
ll dp[MAXN][MAXN];
ll a[MAXN];

void pus(ll i, ll j){
	while(!de.empty() && dp[i][de.back()] < dp[i][j]) de.pop_back();
	de.pb(j);
}
void rem(ll j){
	while(!de.empty() && de.front() <= j) de.pop_front();
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 0;i<MAXN;i++){
		fill(dp[i], dp[i] + MAXN, -INF);
	}
	
	ll n, k, x;
	cin >> n >> k >> x;
	for(int i = 1; i <= n;i++) cin >> a[i];
	
	for(int i = 1; i <= k; i++) {
		dp[1][i] = a[i];
		pus(1, i);
	}
	for(int i = 2; i <= x;i++){
		de.clear();
		for(int j = 1; j < i; j++) pus(i - 1, j);
		for(int j = i; j <= n; j++){
			rem(j - k - 1);
			dp[i][j] = dp[i - 1][de.front()] + a[j];
			pus(i - 1, j);
		}
	}
	
	ll ans = -1;
	for(int i = n - k + 1; i <= n;i++) ans = max(ans, dp[x][i]);
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