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
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;


ll ans = 0;
ll a[MAXN];
ll dp[MAXN][9];
vector<ll> P[MAXN], G[MAXN];

void DFS(ll u, ll p){
	ll wa, w = P[u].size();
	for(int i = 0;i<w;i++) dp[u][i] = 1;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u);
		wa = P[adj].size();
		for(int i = 0;i<w;i++){
			for(int j = 0; j < wa; j++){
				if(P[u][i] == P[adj][j]){
					ans = max(ans, dp[u][i] + dp[adj][j]);
					dp[u][i] = max(dp[u][i], dp[adj][j] + 1);
				}
			}
		}
	}
	return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll v, d;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		v = a[i];
		d = 2;
		while(d * d <= v){
			if(v % d == 0){
				P[i].pb(d);
				while(v % d == 0) v/=d;
			}
			d++;
		}
		if(v > 1) P[i].pb(v);
	}
	ll u;
	for(int i = 1;i<n;i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	
	if((*max_element(a, a + n)) == 1) return cout << 0, 0;
	ans = 1;
	DFS(1, -1);
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