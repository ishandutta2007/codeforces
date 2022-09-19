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
const ll MAXN = (ll) 19 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll N = (1ll << 19);

ll dp[N][MAXN];
ll A[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n>> m;
	ll u, v;
	for(int i = 0; i < m;i++){
		cin >> u >> v; u--; v--;
		A[u][v] = 1;
		A[v][u] = 1;
		ll mx = max(u, v);
		ll mn = min(u, v);
		dp[(1ll << mx) + (1ll << mn)][mn] = 1;
	}
	ll ans = 0;
	for(int i = 0; i < (1ll << n); i++){
		ll bt = __builtin_popcountll(i);
		if(bt <= 2) continue;
		//debug(bt);
		ll mx = 0;
		for(int j = 0; j < n;j++){
			if(i & (1ll << j)) mx = j;
		}
		if(i == 7) debug(mx);
		for(int j = 0; j < n;j++){
			for(int k = 0; k < n ; k++){
				if((1ll << (k + 1)) > i) continue;
				if(A[j][k] == 0) continue;
				if((i & (1ll << j) )== 0) continue;
				if(((1ll << k) & i) == 0) continue;
				dp[i][j] += dp[(i - (1ll << j))][k];
				//if(dp[(i - (1ll << j))][k] > 0) debug(i - (1ll << j));
			}
			
			//debug(dp[i][j]);
			if(A[mx][j]){
				ans += dp[i][j];
			}
		}
	}
	cout << ans / 2;
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