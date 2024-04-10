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
const int Maxm = 2e5 + 10;
const int N = 12;
const int mk = (1 << N) + 10;

const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N][Maxm];
ll dp[mk];
ll ans[mk];
ll mx[Maxm];
ll ind[Maxm];

bool CMP(ll i, ll j){
	return mx[i] > mx[j];
}

int Main(){
	ll n, m;
	cin >> n >> m;
	memset(mx, 0, sizeof mx);
	memset(dp, 0, sizeof dp);
	
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		cin >> a[i][j];
		mx[j] = max(mx[j], a[i][j]);
	}
	iota(ind, ind + m, 0);
	sort(ind, ind + m, CMP);
	
	ll k = min(m, n);
	
	for(int i = 0; i < k; i++){
		//cerr << ind[i] << ' ';
		memset(ans, 0, sizeof ans);
		int jj = ind[i];
		for(int j = 0 ; j < (1 << n); j++){
			ll r = 0;
			for(int d = 0; d < n; d++){
				r = 0;
				for(int ii = 0 ; ii < n; ii++){
					if(j & (1 << ii)) r += a[(ii + d) % n][jj];
				}
				ans[j] = max(ans[j], r);
			}
		}
		for(int j = (1 << n) - 1; j >= 0; j--){
			ll sub = j;
			while(sub){
				dp[j] = max(dp[j], dp[j ^ sub] + ans[sub]);
				sub = (sub - 1) & j;
			}
		}
	}
	//cerr << '\n';
	cout << dp[(1 << n) - 1 ] << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) Main();

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