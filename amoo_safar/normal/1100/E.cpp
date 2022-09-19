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

vector<pll> g[MAXN];
//set<ll> G[MAXN];
ll dep[MAXN], mk[MAXN], t = 1;
vector<ll> O[MAXN];
ll deg[MAXN], ind[MAXN];
ll n;

vector<pll> E;
vector<ll> tc;
queue<ll> q;



bool topo(){
	for(int i = 1;i<=n;i++){
		if(deg[i] == 0) q.push(i);
	}
	ll fr, cnt = 0;
	while(q.size()){
		fr = q.front();
		q.pop();
		for(auto adj : O[fr]){
			deg[adj] --;
			if(deg[adj] == 0) q.push(adj);
		}
		cnt ++;
		ind[fr] = cnt;
	}
	return cnt == n;
}

void build(ll x){
	for(int i = 1; i <= n; i++) {
		O[i].clear();
	}
	
	for(int i = 1; i <= n; i++){
		for(auto e : g[i]){
			if(e.S > x) {
				O[i].pb(e.F);
				deg[e.F] ++;
			}			
		}
	}
}

bool check(ll x){
	memset(deg, 0, sizeof deg);
	build(x);
	return topo();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll m;
	cin >> n >> m;
	ll u, v, c;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> c;
		g[u].pb({v, c});
		E.pb({u, v});
	}
	ll l = -1;
	ll r = INF;
	ll mid;
	//debug(check(1));
	while(l + 1 < r){
		mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << r << " ";
	
	/////
	check(r);
	////
	for(int i = 0 ; i < m; i++){
		if(ind[E[i].F] > ind[E[i].S]) tc.pb(i + 1);
	}
	cout << tc.size() << '\n';
	for(auto adj : tc) cout << adj << " ";
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