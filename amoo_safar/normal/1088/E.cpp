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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll mx = -INF;
ll a[MAXN], dp1[MAXN], dp2[MAXN], dp3[MAXN];
vector<ll> g[MAXN];

void DFS1(ll node, ll par){
	ll s = a[node];
	for(auto adj : g[node]){
		if(adj == par) continue;
		DFS1(adj, node);
		s += max(0ll, dp1[adj]);
	}
	dp1[node] = s;
	mx = max(mx, dp1[node]);
	return ;
}

void DFS2(ll node, ll par){
	for(auto adj : g[node]){
		if(adj == par) continue;
		DFS2(adj, node);
		dp3[node] += max(dp2[adj] + (dp1[adj] == mx ? 1 : 0) ,dp3[adj]);
		if(dp1[node] <= 0){
			dp2[node] += max(dp2[adj] + (dp1[adj] == mx ? 1 : 0) ,dp3[adj]);
		} else {
			dp2[node] += dp2[adj];
		}
	}
	return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	DFS1(1, -1);
	DFS2(1, -1);
	ll k = max(dp2[1] + (dp1[1] == mx ? 1 : 0), dp3[1]);
	cout << mx * k << " " << k << '\n';
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