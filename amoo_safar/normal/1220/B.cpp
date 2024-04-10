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
const int Maxn = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n;
ll a[Maxn][Maxn], b[Maxn];
vector<ll> D;

bool check(ll d){
	b[1] = d;
	for(int i = 2; i <= n; i++) b[i] = a[1][i] / d;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
		if(i == j) continue;
		if(b[i] * b[j] > a[i][j]) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
	
	ll g = 0;
	for(int i = 2; i <= n; i++){
		g = __gcd(g, a[1][i]);
	}
	for(ll i = 1; i * i <= g; i++) if(g % i == 0){
		D.pb(g/i);
		D.pb(i);
	}
	sort(all(D));
	int l = -1;
	int r = D.size();
	int mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(check(D[mid])) l = mid;
		else r = mid;
	}
	
	cout << D[r];
	for(int i = 2; i <= n; i++) cout << " " << a[1][i] / D[r]; 
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