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
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll cnt[35];
vector<ll> val[35];
ll a[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(cnt, 0, sizeof cnt);
	
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	ll v;
	for(int i = 0; i < m; i++){
		cin >> v;
		cnt[v]++;
		val[v].pb(1);
	}
	
	ll ans = 0, p, ma;
	for(int i = 0; i < 32; i++){
		p = (1ll << i);
		sort(all(val[i]));
		for(int j = 0; j < n; j++){
			if(( (a[j] & p) != 0) and (cnt[i] > 0)){
				cnt[i] --;
				ans += val[i].back();
				val[i].pop_back();
				
				a[j] -= p;
			}
		}
		if(val[i].size() % 2 == 1) val[i].insert(val[i].begin(), 0);
		for(int j = 0; j < val[i].size(); j += 2){
			val[i + 1].pb(val[i][j] + val[i][j + 1]);
			cnt[i + 1]++;
		}
	}
	cout << ans;
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