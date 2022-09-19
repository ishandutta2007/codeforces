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
const int Maxn = 2e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

str s[Maxn];
ll D[Maxn][Maxn];
ll R[Maxn][Maxn];
ll dp1[Maxn][Maxn], dp2[Maxn][Maxn];
ll ps1[Maxn][Maxn], ps2[Maxn][Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	if(n + m == 2) return cout << 1, 0;
	for(int i = 0; i < n; i++) cin >> s[i];
	
	for(int i = 0; i < n; i++){
		R[i][m - 1] = 0;
		for(int j = m - 2; j >= 0; j--) R[i][j] = R[i][j + 1] + (s[i][j + 1] == '.');
	}
	for(int j = 0; j < m; j++){
		D[n - 1][j] = 0;
		for(int i = n - 2; i >= 0; i--) D[i][j] = D[i + 1][j] + (s[i + 1][j] == '.');
	}
	dp1[0][0] = dp2[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i) ps1[i][j] += ps1[i - 1][j];
			if(j) ps2[i][j] += ps2[i][j - 1];
			if(i + j) dp1[i][j] = ps1[i][j];
			if(i + j) dp2[i][j] = ps2[i][j];
			
			dp1[i][j] %= Mod;
			dp2[i][j] %= Mod;
			
			ps1[i + 1][j] += dp2[i][j];
			ps1[i + D[i][j] + 1][j] -= dp2[i][j];
			
			ps2[i][j + 1] += dp1[i][j];
			ps2[i][j + R[i][j] + 1] -= dp1[i][j];
		}
	}
	cout << (dp1[n - 1][m - 1] + dp2[n - 1][m - 1] +Mod + Mod) % Mod<< '\n';
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