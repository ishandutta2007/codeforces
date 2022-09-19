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
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll p[2 * MAXN];
ll c[2 * MAXN];
ll f[2 * MAXN];
vector<pll> ed;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n + n; i++) cin >> p[i];
	ll u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		ed.pb({u, v});
		f[u] = v;
		f[v] = u;
	}
	ll t;
	cin >> t;
	ll last = 0;
	ll h;
	ll rem = 2 * n;
	if(t == 2){
		cin >> last;
		c[last] = 1;
		rem --;
	}
	
	ll fi, s, fl;
	while(rem > 0){
		if((f[last] != 0) and (c[f[last]] == 0)){
			cout << f[last] << endl;
			c[f[last]] = 1;
			rem --;
		} else {
			fl = 0;
			while(ed.size()){
				fi = ed.back().F;
				s = ed.back().S;
				if((c[fi] == 1) or(c[s] == 1)){
					ed.pop_back();
					continue;
				}
				fl = 1;
				rem--;
				if(p[fi] > p[s]){
					cout << fi << endl;
					c[fi] = 1;
				} else {
					cout << s << endl;	
					c[s] = 1;
				}
				break;
			}
			if(fl == 0){
				ll ind = -1;
				ll mi = -INF;
				for(int i = 1;i <= n + n;i++){
					if(c[i] == 0){
						if(p[i] > mi){
							ind = i;
							mi = p[i];
						}
					}
				}
				cout << ind <<endl;
				c[ind] = 1;
				rem--;
			}
		}
		
		if(rem){
			cin >> last;
			c[last] = 1;
			rem--;
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