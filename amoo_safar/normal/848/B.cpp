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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

typedef pair<ll, pll> ppll;

vector<ll> dan[2 * MAXN];
vector<ppll> odan[2 * MAXN];
ll a[MAXN];
ppll oa[MAXN];
ll x[MAXN], t[MAXN];
pll out[MAXN], ans[MAXN];

bool CMP(ppll a, ppll b){
	return x[a.F] < x[b.F];
}
bool CMP2(ll i, ll j){
	return x[i] < x[j];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, w, h, m = 0;
	cin >> n >> w >> h;
	ll g;
	for(int i = 0; i < n; i++){
		cin >> g >> x[i] >> t[i];
		t[i] = -t[i] + MAXN;
		if(g == 1){
			a[m] = i;
			oa[m] = {i, {x[i], h}};
			m++;
		} else {
			dan[x[i] + t[i]].pb(i);
			odan[x[i] + t[i]].pb({i, {w, x[i]}});
		}
	}
	
	for(int i = 0; i < 2 * MAXN; i++){
		sort(all(odan[i]), CMP);
		sort(all(dan[i]), CMP2);
	}
	sort(oa, oa + m, CMP);
	sort(a, a + m, CMP2);
	
	debug(m);
	ll co;
	for(int i = 0; i < m; i++){
		co = x[a[i]] + t[a[i]];
		//debug(i);debug(co);
			if(dan[co].size() != 0){
			//debug(g);
			dan[co].insert(dan[co].begin(), a[i]);
			a[i] = dan[co].back();
			dan[co].pop_back();
		}
	}
	for(int i = 0; i < m; i++){
		ans[a[i]] = oa[i].S;
	}
	ll s;
	for(int i = 0; i < 2 * MAXN; i++){
		s = dan[i].size();
		for(int j = 0;j<s;j++){
			ans[dan[i][j]] = odan[i][j].S;
		}
	}
	for(int i = 0;i < n; i++) cout << ans[i].F << ' ' << ans[i].S << '\n';
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