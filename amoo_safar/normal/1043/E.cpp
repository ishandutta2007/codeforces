#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

pll a[MAXN];

ll out[MAXN], x[MAXN], y[MAXN];;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll s = 0;
	for(int i = 0;i<n;i++){
		cin >> x[i] >> y[i];
		a[i] = {y[i] - x[i], i};
		s += x[i];
	}
	for(int i = 0;i < n; i++) out[i] = s + ((n - 2) * x[i]);
	
	ll ps = 0;
	sort(a, a + n);
	for(int i = 0;i < n;i++){
		out[a[i].S] += (ps + (n - i - 1) * a[i].F);
		ps +=a[i].F;
	}
	ll u,v, mi;
	for(int i = 0;i<m;i++){
		cin >> u >> v;
		u--;v--;
		mi = min(x[u] + y[v], x[v] + y[u]);
		out[v] -= mi;
		out[u] -= mi;
	}
	
	for(int i = 0;i<n;i++) cout << out[i] << " ";
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