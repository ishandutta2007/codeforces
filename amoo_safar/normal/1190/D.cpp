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
const int Maxn = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

set<ll> st;
vector<pll> V, V2;
vector<ll> t[Maxn];
map<ll, ll> mp, C;

ll fen[Maxn];

ll add(ll x, ll d = 1){
	for(; x < Maxn; x += (x & (-x))) fen[x] += d;
}
ll get(ll idx){
	ll res = 0;
	for(; idx; idx -= (idx & (-idx))) res += fen[idx];
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll x, y;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		st.insert(x);
		st.insert(y);
		V.pb({x, y});
	}
	ll cnt = 1;
	for(auto el : st) mp[el] = cnt ++;
	
	for(auto po : V){
		t[mp[po.S]].pb(mp[po.F]);
		if(C[mp[po.F]] == 0) add(mp[po.F], 1);
		C[mp[po.F]] ++;
	}
	ll ans = 0;
	ll M, rem = C.size();
	for(int i = 0; i < Maxn; i++){
		if(t[i].size() == 0) continue;
		sort(all(t[i]));
		//cerr << rem << '\n';
		ans += (rem * (rem + 1) / 2LL);
		ll N = t[i].size();
		for(int j = 0; j + 1 < N; j++){
			M = get(t[i][j + 1] - 1) - get(t[i][j]);
			ans  -= ((M * (M + 1)) / 2LL);
		}
		M = get(t[i][0] - 1);
		ans  -= ((M * (M + 1)) / 2LL);
		M = rem - get(t[i][N - 1]);
		ans  -= ((M * (M + 1)) / 2LL);
		for(auto X : t[i]){
			C[X] --;
			if(C[X] == 0){
				rem --;
				add(X, -1);
			}
		}
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