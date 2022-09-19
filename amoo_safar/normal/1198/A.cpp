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
const int Maxn = 4e5 + 10;
const ll Inf = 200000000LL;
const ll Log = 33;

ll a[Maxn];
map<ll, ll> mp;
vector<ll> V;
ll ps[Maxn], ps2[Maxn];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, sz;
	cin >> n >> sz;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	ll ans = n;
	sz *= 8;
	ll k = sz / n;
	ll mx = 1ll << min(32LL, k);
	V.pb(0);
	for(auto x : mp) V.pb(x.S);
	ll m = V.size() - 1;
	ps[0] = 0;
	for(int i = 1; i <= m; i++) ps[i] = ps[i - 1] + V[i];
	ps2[0] = 0;
	for(int i = 1; i <= m; i++) ps2[i] = ps2[i - 1] + V[m - i + 1];
	for(int i = 0; i <= m; i++){
		ll m2 = max(0LL, m - mx - i);
		ans = min(ans, ps[i] + ps2[m2]);
	}
	cout << ans << '\n'; 
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