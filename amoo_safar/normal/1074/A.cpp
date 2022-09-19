#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN], b[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin >> n >> m;
	ll mi = (ll) 1e9;
	ll v;
	for(int i = 0;i<n;i++){
		cin >> a[i];
		mi = min(mi, v);
	}
	a[n] = (ll)1e9;

	sort(a,a + n + 1);
	
	//ll ans = 0;
	ll x,y,z;
	ll t = 0;
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		//if(x == 1 and y >= mi) ans ++;
		if(x == 1){
			t++;
			b[t - 1] = y;
		}
	}
	m = t;
	sort(b, b + m);
	ll ans = n + m + 1;
	for(int i = 0;i<=n;i++){
		ll l = lower_bound(b, b + m, a[i]) - b;
		ans = min(ans, i + m - l);
		//debug((m - l));
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