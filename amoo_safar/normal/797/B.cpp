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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll a[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	ll p = 0;
	ll s = 0, v;
	ll cnt = 0;
	for(int i =0;i<n;i++){
		cin >> v;
		if(v >= 0) s += v;
		if(((v%2)+2)%2==1){
			if(v > 0) cnt++;
			a[p] = v;
			p++;
		}
	}
	//debug(p);
	sort(a,a+p);
	if(cnt %2 == 1){
		cout << s;
	} else {
		//debug(a[0]);
		ll ind = -1;
		for(int i =0;i<p;i++){
			if(a[i] < 0){
				ind = i;
			}else break;
		}
		//debug(ind);
		if(ind == p-1){
			s += a[p-1];
			cout << s;
		}
		else if(ind == -1){
			s -= a[0];
			cout << s;
		} else {
			cout << s - (min(abs(a[ind]), a[ind+1]));
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