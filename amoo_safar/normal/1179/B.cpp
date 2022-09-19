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

ll n, m;

ll solve2(ll x, ll y){
	ll p1 = 1;
	ll p2 = n;
	ll w = 0;
	for(int i = 0; i < n + n; i++){
		if(w == 0) cout << p1 << " " << x << '\n';
		else cout << p2 << " " << y << '\n';
		if(w == 0) p1 ++;
		else p2 --;
		w = 1 - w;
	}
}
ll solve(ll x){
	ll p1 = 1;
	ll p2 = n;
	ll w = 0;
	for(int i = 0; i < n; i++){
		if(w == 0) cout << p1 << " " << x << '\n';
		else cout << p2 << " " << x << '\n';
		if(w == 0) p1 ++;
		else p2 --;
		w = 1 - w;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ll p1 = 1;
	ll p2 = m;
	while(p1 <= p2){
		if(p1 == p2) solve(p1);
		else {
			solve2(p1, p2);
		}
		p1 ++;
		p2 --;
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