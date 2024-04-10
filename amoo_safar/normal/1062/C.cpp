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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll ps[MAXN], psc[MAXN];

ll ch(ll n){
	return (n * (n-1)) / 2ll;
}

ll p[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	p[0] = 1;
	for(int i = 1;i<MAXN-1;i++) p[i] = (2ll * p[i - 1]) % MOD;
	psc[0] = 0;
	psc[1] = 1;
	for(int i = 2;i < MAXN - 1; i++) psc[i] = (psc[i - 1] + p[i-1]) % MOD;
	//for(int i = 0; i < 6;i++) cerr << psc[i] << " ";
	ll n, q;
	cin >> n >> q;
	str s;
	cin >> s;
	ps[0] = 0;
	for(int i = 1;i<=n;i++) ps[i] = ps[i - 1] + (s[i - 1] - '0');
	ll l, r, su;
	for(int i = 0;i < q; i++){
		cin >> l >> r;
		su = ps[r] - ps[l-1];
		//debug(su);
		cout << (((psc[r - l+1] - psc[r - l - su + 1]) %MOD)+MOD)%MOD << endl;
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