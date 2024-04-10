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
typedef pair<ll, pll> ppll;
const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

vector<pll> g[MAXN];
vector<ll> ans;
ll vis[MAXN];
priority_queue<ppll, vector<ppll>, greater<ppll>> pq;
map<pll, ll> ma;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll v,u,w;
	
	for(int i = 0;i<m;i++){
		cin >> u >> v >> w;
		u--;v--;
		g[u].pb({v, w});
		g[v].pb({u, w});
		ma[{u, v}] = i+1;
		ma[{v, u}] = i + 1;
	}
	pq.push({0, {0, -1}});
	
	ll ww;
	ppll t;
	while(pq.size() > 0){
		t = pq.top();
		if(vis[t.S.F] == 1){
			pq.pop();
			continue;
		}
		ww = t.F;
		for(auto e : g[t.S.F]){
			pq.push({ww + e.S, {e.F, t.S.F}});
		}
		
		if(t.S.S != -1){
			ans.pb( ma[t.S] );
		}
		vis[t.S.F] = 1;
		pq.pop();
	}
	
	//for(auto x : ans) cout << x << endl;
	k = min(n - 1, k);
	cout << k << endl;
	for(int i = 0;i<k;i++) cout << ans[i] << " ";
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