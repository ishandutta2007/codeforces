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
const int Maxn = 2e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll cnt[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector< vector<bool> > t(n + 2);
	vector< vector<bool> > a(n + 2);
	vector< vector<bool> > b(n + 2);
	for(int i = 0; i < n + 2; i++){
		for(int j = 0; j < m + 2; j++){
			t[i].pb(false);
			a[i].pb(false);
			b[i].pb(false);
		}
	}
	str s;
	for(int i = 1; i <= n; i++){
		cin >> s;
		s = '!' + s;
		for(int j = 1; j <= m; j++){
			if(s[j] == '.') t[i][j] = true;
		}
	}
	a[1][1] = true;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) a[i][j] = ( (a[i - 1][j] || a[i][j - 1] || a[i][j]) & t[i][j] );
	
	b[n][m] = true;
	for(int i = n; i >= 1; i--) for(int j = m; j >= 1; j--) b[i][j] = ( (b[i + 1][j] || b[i][j + 1] || b[i][j]) & t[i][j] );
	if(!b[1][1]) return cout << 0, 0;
	//cerr << a[1][4] << '\n';
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
		if(a[i][j] & b[i][j]) {
			//cerr << i << " " << j << '\n';
			cnt[i + j] ++;
		}
	}
	for(int i = 3; i <= n + m - 1; i++){
		if(cnt[i] == 1) return cout<< 1, 0;
	}
	cout << 2;
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