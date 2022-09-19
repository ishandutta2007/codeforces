#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 998244353LL;
const int Maxn = 5e1 + 3;
const ll Inf = 200000000LL;
const ll Log = 33;

int dp[Maxn][Maxn][Maxn][Maxn];

ll ps[Maxn][Maxn], a[Maxn][Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	char c;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> c;
			if(c == '#') a[i][j] = 1;
			ps[i][j] = ps[i - 1][j] + ps[i][j - 1] + a[i][j] - ps[i - 1][j - 1];
		}
	}
	short int zero = 0;
	for(int l1 = 1; l1 <= n; l1++){
		for(int l2 = 1; l2 <= n; l2++){
			for(int i1 = 1; i1 + l1 <= n + 1; i1 ++){
				int j1 = i1 + l1;
				for(int i2 = 1; i2 + l2 <= n + 1; i2 ++){
					int j2 = i2 + l2;
					int sm = ps[j1 - 1][j2 - 1]	- ps[i1 - 1][j2 - 1] - ps[j1 - 1][i2 - 1] + ps[i1 - 1][i2 - 1];
					dp[i1][j1][i2][j2] = (sm == 0 ? zero : max(l1, l2));
					for(int mid = i1 + 1; mid < j1; mid ++) dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2], dp[i1][mid][i2][j2] + dp[mid][j1][i2][j2]);
					for(int mid = i2 + 1; mid < j2; mid ++) dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2], dp[i1][j1][i2][mid] + dp[i1][j1][mid][j2]);
				}
			}
		}
	}
	cout << dp[1][n + 1][1][n + 1]; 
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