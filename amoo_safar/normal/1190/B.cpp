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

ll a[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n;
	ll s = 0, S = n * (n - 1LL) / 2LL;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s += a[i];
	
	}
	sort(a,a + n );
	ll cnt = 0;
	ll l = -1;
	for(int i = 0; i + 1 < n; i++){
		if(a[i] == a[i + 1]){
			cnt ++;
			l = i;
		}
	}
	if(cnt >= 2) return cout << "cslnb", 0;
	if(cnt == 1){
		if(l == 0){
			if(a[l] == 0) return cout << "cslnb", 0;
		} else {
			if(a[l - 1] == a[l] - 1) return cout << "cslnb", 0;
		}
	}
	
	cout << ((s - S) % 2 == 1 ? "sjf":"csl")<< "nb";
	
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