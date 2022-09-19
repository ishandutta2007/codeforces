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

pll ans[Maxn];
deque<ll> deq;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n >> q;
	ll v;
	for(int i = 0 ; i < n; i++){
		cin >> v;
		deq.pb(v);
	}
	ll a, b;
	for(int i = 1; i <= n; i++){
		a = deq.front();
		deq.pop_front();
		b = deq.front();
		deq.pop_front();
		ans[i] = {a, b};
		deq.push_back(min(a, b));
		deq.push_front(max(a, b));
	}
	//for(auto x:deq) cout <<x << " ";
	//cout<<'\n';
	ll m, ind;
	for(int i = 0; i < q; i++){
		cin >> m;
		if(m <= n) cout << ans[m].F << " " << ans[m].S << '\n';
		else {
			ind = 1 + ((m - n - 1) % (n - 1));
			cout << deq[0] << " " << deq[ind] << '\n';
		}
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