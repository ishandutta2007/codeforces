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
const int Maxn = 2e5 + 10;
const ll Inf = 200000000LL;
const ll Log = 33;

struct Q {
	ll t;
	ll p, x;
		
};

vector<Q> que;

ll ans[Maxn], mk[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	Q a;
	for(int i = 1; i <= n; i++){
		a.t = 1;
		a.p = i;
		cin >> a.x;
		que.pb(a);
	}
	ll q;
	cin >> q;
	for(int i = 0 ; i < q; i++){
		cin >> a.t;
		if(a.t == 1) cin >> a.p;
		cin >> a.x;
		que.pb(a);
	}
	ll mx = 0;
	reverse(all(que));
	for(auto x : que){
		//cerr << x.t << " " << mx<< '\n';
		if(x.t == 1){
			if(mk[x.p]) continue;
			mk[x.p] = 1;
			ans[x.p] = max(x.x, mx);			
		} else {
			mx = max(mx, x.x);
		}
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
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