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
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll p[Maxn];
map<vector<pll>, ll> mp;
map<ll, ll> cn;
vector<pll> v, v2;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(p, -1, sizeof p);
	for(int i = 2; i < Maxn; i++) for(int j = i; j < Maxn; j+=i) if(p[j] == -1) p[j] = i;
	
	ll n, k;
	cin >> n >> k;
	ll V;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		cn.clear();
		v.clear();
		v2.clear();
		cin >> V;
		while(V > 1){
			cn[p[V]] ++;
			V /= p[V];
		}
		for(auto x : cn) if(x.S % k) v2.pb({x.F, (k - (x.S % k)) % k});
		for(auto x : cn) if(x.S % k) v.pb({x.F, (x.S % k)});
		
		ans += (mp.count(v2) ? mp[v2] : 0);
		mp[v] ++;
		
	}
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