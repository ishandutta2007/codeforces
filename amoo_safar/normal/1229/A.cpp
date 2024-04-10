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

vector<pll> V;
ll a[Maxn];
map<ll, ll> mp;
ll in[Maxn];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0 ; i < n; i++) cin >> a[i];
	ll b;
	ll ans = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> b;
		V.pb({a[i], b});
	}
	sort(all(V));
	fill(in, in + n, 1);
	for(int i = n - 1;i >=0;i--){
		in[i] = 0;
		for(int j = 0; j <= n; j++){
			if(j == i) continue;
			if(in[j] == 0) continue;
			if(V[j].F == (V[j].F | V[i].F)){
				in[i] = 1;
			}
		}
		if(in[i] == 1) ans += V[i].S, cnt ++;;
	}
	cout << (cnt < 2 ? 0 : ans);
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