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
const ll N = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
vector<ll> G[N];
ll mk[N];
ll DFS(ll u , ll p){
	mk[u] = 1;
	ll sz = 1;
	for(auto adj : G[u]){
		if(adj == p) continue;
		sz += DFS(adj, u);
	}
	return sz;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll u, v, t;
	for(int i = 1; i<n;i++){
		cin >>u >> v>>t;
		if(t == 0){
			G[u].pb(v);
			G[v].pb(u);
		}
	}
	ll ans = 1;
	for(int i = 0; i< k;i++){
		ans *= n;
		ans %= MOD;
	}
	for(int i = 1; i<= n;i++){
		if(mk[i] == 0){
			ll res = DFS(i, -1);
			//debug(res);
			ll mn = 1;
			for(int j = 0; j<k;j++){
				mn *= res;
				mn %= MOD;
			}
			ans -= mn;
			ans %= MOD;
		}
	}
	cout << (((ans % MOD)+MOD) % MOD);
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