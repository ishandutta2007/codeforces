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

set<ll> ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll s, p;
	for(ll i = 1; i*i<=n; i++){
		if(n % i == 0){
			/*s = 0;
			p = 1;
			while(p < n + 1){
				s += p;
				p += i;
			}
			ans.insert(s);
			s = 0;
			p = 1;
			while(p < n + 1){
				s += p;
				p += (n/i);
			}
			ans.insert(s);*/
			s = (n - i + 2) * (n / i) / 2;
			ans.insert(s);
			ll j = n/i;
			s = ((n - j + 2) * (n / j) / 2);
			ans.insert(s);
		}
	}
	for(auto x : ans) cout << x << " ";
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