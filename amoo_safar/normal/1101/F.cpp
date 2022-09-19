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
const ll MAXN = (ll) 250000 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[410];
ll b[MAXN];
pair<pll, pll> t[MAXN];

bool check(ll ind, ll V){
	ll fu = V;
	ll r = t[ind].S.S;
	ll up = t[ind].S.F;
	for(int ci = t[ind].F.F; ci < t[ind].F.S; ci++){
		if((a[ci+1] - a[ci]) * up > V) return false;
		if((a[ci+1] - a[ci]) * up > fu){
			fu = V;
			r--;
		}
		fu -= ( (a[ci+1] - a[ci]) * up );
	}
	return r >= 0;
}

int main(){
    ios::sync_with_stdio(0);
	srand ( unsigned ( std::time(0) ) );

	ll n, m;
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 0; i < m; i++) b[i] = i;
	for(int i = 0; i < m; i++) scanf("%lld%lld%lld%lld", &t[i].F.F, &t[i].F.S, &t[i].S.F, &t[i].S.S);
	random_shuffle(b, b + m);
	ll ans = 0;
	ll i, l, r, mid;
	for(int j = 0;j<m;j++){
		i = b[j];
		//debug(i);
		if(check(i, ans)){
			continue;
		}
		l = ans, r = INF;
		while(l + 1 < r){
			mid = (l + r) / 2;
			if(check(i, mid)) r = mid;
			else l = mid;
		}
		ans = max(ans, r);
	}
	printf("%lld\n", ans);
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