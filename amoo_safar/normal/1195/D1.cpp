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

const ll Mod = 998244353LL;
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll lg(ll x){
	if(x == 0) return 0;
	return 1 + lg(x / 10LL);
}
ll mul(ll a , ll b){
	return (a * b) % Mod;
}

ll cnt[Maxn], a[Maxn], p1[Maxn], ps[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	p1[0] = 1;
	for(int i = 1; i < Maxn; i++) p1[i] = (p1[i - 1] * 10LL) % Mod;
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[lg(a[i])] ++;
	}
	for(int i = Maxn - 2; i >= 0; i++) ps[i] = ps[i + 1] + cnt[i];
	ll m, ans = 0;
	for(int i = 0; i < n; i++){
		m = a[i];
		ll C = 0, d;
		while(m){
			d = m % 10;
			for(int j = 1; j <= 10; j++){
				ans += mul(cnt[j],  mul(d, p1[C + min(C, (ll) j)]) );
				ans %= Mod;
				ans += mul(cnt[j],  mul(d, p1[C + min(C + 1, (ll) j)]) );
				ans %= Mod;
			}
			C ++;
			m /= 10;
			//cerr << ans << '\n';
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