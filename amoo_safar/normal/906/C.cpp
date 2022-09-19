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
const ll MAXN = (ll) 2e2 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
const ll N = (1ll << 22);

ll adj[MAXN];
ll dp[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	if(m == n * (n - 1) / 2) return cout << 0, 0;
	ll u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u --; v --;
		adj[v] |= (1ll << u);
		adj[u] |= (1ll << v);
	}
	
	for(int i = 0; i < n; i++) adj[i] |= (1ll << i);
	for(int i = 0; i < n; i++) dp[1ll << i] = adj[i];
	
	for(int i = 0; i < (1ll << n); i++){
		for(int j = 0; j < n; j++){
			if(((dp[i] & (1ll << j)) > 0) and ( (i & (1ll << j)) == 0)){
				dp[(i | (1ll << j))] |= (dp[i] | adj[j]);
			}
		}
	}
	ll ans = n + n;
	ll mk = 0;
	for(int i = 0; i < (1ll << n); i++){
		if(dp[i] < (1ll << n) - 1) continue;
		if(__builtin_popcountll(i) < ans){
			ans = __builtin_popcountll(i);
			mk = i;
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++){
		if(mk & (1ll << i)) cout << i + 1 << " ";
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