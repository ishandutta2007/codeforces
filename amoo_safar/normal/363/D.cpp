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
ll p[MAXN];
ll mon;

bool check(ll cnt){
	ll money = mon;
	for(int i = 0, j = cnt - 1; i < cnt; i++, j--){
		if(a[i] < p[j]) money -= (p[j] - a[i]);
	}
	if(money < 0) return false;
	return true;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin >> n >> m >> mon;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	for(int i = 0; i < m; i++) cin >> p[i];
	sort(p, p + m);
	
	ll dw = 0, up = min(n, m) + 1;
	ll mid;
	while(dw + 1 < up){
		mid = (dw + up) / 2;
		if( check(mid) ) dw = mid;
		else up = mid;
	}
	cout << dw << " ";
	ll sum = 0;
	for(int i = 0; i < dw; i++) sum += p[i];
	
	cout << max(0ll, sum - mon);
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