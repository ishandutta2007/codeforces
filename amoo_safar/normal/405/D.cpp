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
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
vector<ll> out;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, v ;
	cin >> n;
	ll s = (ll) 1e6;
	for(int i = 0;i<n;i++){
		cin >> v;
		a[v] = 1;
	}
	ll t = 0, x = 0;
	ll j;
	for(int i = 1; i <= s;i++){
		j = s + 1 - i;
		
		if(a[i] == 1 and a[j] == 1 and (i<j)) t++;
		if(a[i] == 0 and a[j] == 1){
			out.pb(i);
		}
		if(a[j] == 0 and a[i] == 0) x++;
	}
	//debug(t);
	j = 0;
	ll c;
	while(t > 0){
		j++;
		c = s + 1 - j;
		if(a[j] == 0 and a[c] == 0){
			t--;
			out.pb(j);
			out.pb(c);
		}
	}
	cout << out.size() << endl;
	for(auto vv:out) cout << vv << " ";
	cout << endl;
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