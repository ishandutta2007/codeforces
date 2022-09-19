#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e2 + 10;
const ll Inf = 1e18 + 10;
const ll Log = 30;

ll dp[Maxn][Maxn];

ll calc(str s){
	//cerr << s << '\n';
	memset(dp, 0, sizeof dp);
	int n = s.size();
	str t = '!' + s;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(t[i] != ')'){
				dp[i][j] += dp[i - 1][j - 1];
			}
			dp[i][j] = min(dp[i][j], Inf);
		}
		for(int j = 0; j <= n; j++){
			if(t[i] != '('){
				dp[i][j] += dp[i - 1][j + 1];
			}
			dp[i][j] = min(dp[i][j], Inf);
		}
	}
	return dp[n][0];
}

ll mn[2 * Maxn], ind[Maxn + Maxn];

bool CMP(int i, int j){
	return mn[i] < mn[j];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll v;
	memset(mn, 31, sizeof mn);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> v;
			mn[i + j] = min(mn[i + j], v);
		}
	}
	
	str ans = "";
	for(int i = 0; i < n + m - 1; i++) ind[i] = i;
	for(int i = 0; i < n + m - 1; i++) ans += '?';
	sort(ind, ind + n + m - 1, CMP);
	int ii;
	ll cl;
	for(int i = 0; i < n + m - 1; i++){
		ii = ind[i];
		ans[ii] = '(';
		cl = calc(ans);
		if(cl >= k){
			
		} else {
			ans[ii] = ')';
			k -= cl;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i + j];
		}
		cout << '\n';
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