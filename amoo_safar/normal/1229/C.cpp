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

const ll Mod = 1e9 + 7;
const int Maxn = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
ll Base = 101;
vector<int> in[Maxn];
ll inp[Maxn], out[Maxn];
ll ans = 0;
void rev(ll u){
	ll v = in[u].back();
	ans -= out[u];
	ans -= inp[v];
	in[u].pop_back();
	inp[u] --; inp[v] ++;
	out[u] ++; out[v] --;
	in[v].pb(u);
	
	ans += out[v];
	ans += inp[u];
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll u, v;
	for(int i = 0 ; i < m; i++){
		cin >> u >> v;
		if(u > v) swap(u, v);
		inp[u] ++;
		out[v] ++;
		in[u].pb(v);
		//out[v].insert(u);
	}
	for(int i = 1; i <= n; i++){
		ans += (inp[i]) * (out[i]);
		//cerr << ans << '\n';
	}
	cout << ans << '\n';
	ll q;
	cin >> q;
	
	for(int i =0 ; i < q; i++){
		cin >> v;
		while(in[v].size()){
			rev(v);
		}
		cout << ans << '\n';
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