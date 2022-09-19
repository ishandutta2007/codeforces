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
	ll n;
	cin >> n;
	for(int i = 2; i <= n; i++) cin >> a[i];
	d[1] = 0;
	for(int i = 2; i <= n; i++) d[i] = d[i - 1] + a[i];
	ll mx = 1;
	for(int i = 2; i <= n; i++){
		if(d[mx] < d[i]) mx = i;
	}
	ans[1] = n - d[mx];
	for(int i = 2; i <= n; i++) ans[i] = d[i] + ans[1];
	for(int i = 1; i<=n;i++){
		if(ans[i] < 1 or ans[i] > n) return cout << -1, 0;
		cnt[ans[i] ] ++;
		if(cnt[ans[i] ] == 2) return cout << -1, 0;
	}
	for(int i = 1; i<=n;i++) cout << ans[i] << " ";
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