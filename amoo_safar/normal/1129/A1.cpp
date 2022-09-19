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
const ll MAXN = (ll) 5e3 + 10;
const ll N = (ll) 1e3 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
ll cnt[MAXN];
ll nd[MAXN];

queue<ll> q;
vector<pll> P;
vector<ll> C[MAXN];
ll n;

ll dis2(ll i, ll j){
	return j - i;
}
ll dis(ll i, ll j){
	//debug(i); debug(j);
	if(i < j) return j - i;
	return dis2(i, n) + 1 + dis2(1, j);
}

ll sc;

bool CMP(ll a, ll b){
	return dis(sc, a) > dis(sc, b);
}

vector< pair<pll, ll> > K;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll m;
	cin >> n >> m;
	ll u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		C[u].pb(v);
	}
	for(int i = 1; i <= n; i++){
		sc = i;
		sort(all(C[i]), CMP);
	}
	
	for(int i = 1; i <= n; i++){
		ll ans = 0;
		ll x = i - 1;
		for(int j = 0; j < n; j++){
			x++;
			if(x == n + 1) x = 1;
			ll t = 0;
			for(auto c : C[x]){
				ans = max(ans, t * n + j + dis(x, c));
				t++;
			}
		}
		cout << ans << " ";
		
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