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
const int Maxn = 5e5 + 10;
const ll Inf = 200000000LL;
const ll Log = 33;

vector<pll> E;
vector<ll> M;
ll mk[Maxn];
int MAIN(){
	ll n, m;
	cin >> n >> m;
	E.clear();
	M.clear();
	fill(mk, mk + n + n + n+ 3, 0);
	
	ll u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		if((mk[u] == 1) || (mk[v] == 1)) continue;
		M.pb(i);
		mk[u] = 1;
		mk[v] = 1;
	}
	if(M.size() >= n){
		cout << "Matching\n";
		for(int i = 0; i < n; i++){
			cout << M[i] << " ";
		}
		cout << '\n';
		return 0;
	}
	ll cnt = n;
	cout << "IndSet\n";
	for(int i = 1; i <= n + n + n; i++) if((mk[i] == 0) && (cnt > 0)){
		cout << i << " ";
		cnt --;
	}
	cout << '\n';
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