#include <bits/stdc++.h>

#define pb push_back
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
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN], b[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i < n; i+=2) cin >> a[i];
	
	ll c, d, se;
	for(int i = 1; i < n; i+=2){
		for(ll j = 1; j*j < a[i]; j++){
			if(a[i]%j == 0){
				se = a[i]/j;
				d = (se + j);
				if(d % 2ll == 1ll) continue;
				if(d == 0) continue;
				d /= 2;
				c = se - d;
				//debug(d); debug(c);
				if(i == 1){
					b[i] = d;
					b[i - 1] = c;
					continue;
				}
				if(c > b[i - 2]){
					b[i] = d;
					b[i - 1] = c;
				}
				//cerr << '\n';
			}
			
		}
	}

	ll su = 0;
	if(b[0] == 0) return cout << "No", 0;
	for(int i = 1; i< n;i++){
		if(b[i] <= b[i - 1]) return cout << "No", 0;
	}
	cout << "Yes\n";
	for(int i = 0;i<n;i++){
		cout << (b[i] * b[i]) - su << " ";
		su = (b[i]*b[i]);
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