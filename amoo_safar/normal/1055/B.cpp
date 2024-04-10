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
	ll n, m, l;
	cin >>  n >> m >> l;
	ll v;
	for(int i = 0;i<n;i++){
		cin >> v;
		if(v > l) a[i] = 1;
		b[i] = v;
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(a[i] == 0 and a[i-1] == 1) ans ++;
	}
	ll t,p,d;
	for(int i = 0;i<m;i++){
		cin >> t;
		if(t == 0) cout << ans << '\n';
		else{
			cin >> p >> d;
			p--;
			if(a[p] == 1) continue;
			b[p] += d;
			if(b[p] <= l) continue;
			if(p == 0){
				if(a[1] == 0) ans ++;
			} else {
				if(a[p-1] == 0 and a[p + 1] == 0) ans ++;
				if(a[p-1] == 1 and a[p + 1] == 1) ans --;
			}
			if(b[p] > l) a[p] = 1;
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