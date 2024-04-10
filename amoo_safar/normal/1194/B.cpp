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
const int Maxn = 5e4 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

str a[Maxn];
ll smr[Maxn], smc[Maxn];

int C(char c){
	return (c == '*' ?  1 : 0);
}

int MAIN(){
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = '!' + a[i];
	}
	for(int i = 1; i <= n; i++) smr[i] = 0;
	for(int j = 1; j <= m; j++) smc[j] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			smr[i] += C(a[i][j]);
			smc[j] += C(a[i][j]);
		}
	}
	ll mx = 0;
	
	for(int i = 1; i <= n;i++){
		for(int j = 1; j<=m; j++) mx = max(mx, smr[i] + smc[j] - C(a[i][j]));
	}
	cout << n + m - 1 - mx << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		MAIN();
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