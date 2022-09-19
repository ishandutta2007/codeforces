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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
map<ll, ll> ma;
vector<ll> cnt;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	ll v;
	for(int i = 0;i<n;i++){
		cin >> v;
		ma[v]++;
	}
	for(auto x : ma) cnt.pb(x.S);
	sort(all(cnt));
	cnt.pb(INF);
	
	
	ll m = cnt.size();
	debug(m);
	for(int i = 0;i < m;i++) a[i] = cnt[i];
	ll ans = 0;
	ll pr, po;
	ll f;
	ll up;
	for(int i = 1;i<=n;i++){
		po = 0;
		pr = 0;
		f = i;
		while(true){
			//debug(po);
			if(po >= m - 1) break;
			up = po + ( upper_bound(a + po, a + m, f - 1) - (a + po) );
			//debug(up);
			if(up >= m - 1) break;
			po = up + 1;
			//debug(po);
			pr += f;
			f *= 2ll;
		}
		ans = max(ans, pr);
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