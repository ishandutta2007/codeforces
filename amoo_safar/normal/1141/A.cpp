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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

map<ll, vector<pll>> mp;
ll a[MAXN];
ll ps[MAXN];
ll d[MAXN], ans[MAXN];
//ll mn[MAXN]
ll cnt[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n>> m;
	ll ans = 0;
	while(n != m){
		if(m % n != 0) return cout << -1, 0;
		ans ++;
		if(m % (n + n) == 0){
			n *= 2ll; continue;}
		if(m % (n + n + n) == 0){ n *= 3ll; continue;}
		
		return cout << -1, 0;
	}
	cout << ans;
	/*ps[0] = 0;
	for(int i = 1; i <= n; i++) ps[i] = a[i] + ps[i - 1];
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			mp[ps[r] - ps[l - 1]].pb({l, r});
		}
	}
	ll ans = -1;
	for(auto x : mp){
		ll sm = x;
		
	}*/
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