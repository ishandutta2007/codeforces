#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 21;

ll sp[Maxn][Log];

pll LCA(ll u, ll v){
	for(int i = Log - 1; i>=0;i--){
		if(sp[u][i] != sp[v][i]){
			u = sp[u][i];
			v = sp[v][i];
		}
	}
	return {u, v};
}

ll ind[Maxn], edge[Maxn];

ll CMP(ll u, ll v){
	if(u == v) return u;
	pll res = LCA(u, v);
	if(edge[res.F] < edge[res.S]) return u;
	return v;
}


vector<pll> G[Maxn];
ll len[Maxn], dis[Maxn], ans[Maxn], pw[10];
vector<pll> par[Maxn];
set<pll> st;
ll mod[Maxn];

ll nx[Maxn][11];

ll cnt = 0;

ll get(ll u, ll d){
	if(nx[u][d] == 0){
		cnt ++;
		nx[u][d] = cnt;
		mod[cnt] = (mod[u] * 10 + d) % Mod;
		edge[cnt] = d;
		sp[cnt][0] = u;
		for(int i = 1; i < Log; i++) sp[cnt][i] = sp[sp[cnt][i - 1]][i - 1];
	}
	return nx[u][d];
}

vector<int> V;
ll add(ll u, ll num){
	while(num){
		V.pb(num%10);
		num/=10;
	}
	while(V.size()){
		u = get(u, V.back());
		V.pop_back();
	}
	return u;
}

vector<ll> PP;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	len[0] = 0;
	for(int i = 1; i < Maxn; i++) len[i] = 1 + len[i / 10];
	pw[0] = 1;
	for(int i = 1; i < 7; i++) pw[i] = 10 * pw[i - 1];
	
	
	
	ll n, m;
	cin >> n >> m;
	ll u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].pb({v, i});
		G[v].pb({u, i});
	}
	memset(dis, 31, sizeof dis);
	dis[1] = 0;
	ind[1] = 0;
	st.insert({0, 1});
	
	ll P;
	ll adj, id;
	while(!st.empty()){
		u = st.begin() -> S;
		st.erase(st.begin());
		
		if(u != 1){
			PP.clear();
			for(auto x : par[u]){
				PP.pb(add(ind[x.F], x.S));
			}
			P = PP.back();
			for(auto x : PP) P = CMP(P, x);
			ind[u] = P;
			//ans[u] = (ans[P] * pw[len[u]] + u) % Mod;
		}
		
		//cerr << u << ' ' << dis[u] << ' ' << mod[ind[u]] << '\n';
		for(auto E : G[u]){
			adj = E.F; id = E.S;
			if(dis[adj] > dis[u] + len[id]){
				st.erase({dis[adj], adj});
				dis[adj] = dis[u] + len[id];
				st.insert({dis[adj], adj});
				par[adj].clear();
			}
			if(dis[adj] == dis[u] + len[id]){
				par[adj].pb({u, id});
			}
		}
		
	}
	for(int i = 2; i <= n; i++) cout << mod[ind[i]] << '\n';
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