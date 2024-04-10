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

struct edge {
	ll u;
	ll v;
	ll w;
};

ll anssss = 0, lm = 1;
ll par[MAXN], ind[MAXN], an[MAXN], mark[MAXN], dep[MAXN];
edge E[MAXN];
vector<ll> G[MAXN], V;

ll get_par(ll node){
	if(par[node] == node) return node;
	return par[node] = get_par(par[node]);
}

void merge(ll u, ll v){
	u = get_par(u);
	v = get_par(v);
	if(u == v) return ;
	par[u] = v;
}

bool CMP(ll i, ll j){
	return E[i].w < E[j].w;
}

ll DFS(ll node, ll edg, ll d){
	//debug(node);
	//debug(lm);
	ll res, adj, ans = d;
	mark[node] = lm;
	dep[node] = d;
	
	for(auto in : G[node]){
		if(in == edg) continue;
		
		adj = (E[in].u == node ? E[in].v : E[in].u);
		
		if(mark[adj] == lm) {
			//debug(adj);
			anssss ++;
			an[in] = 1;
			ans = min(ans, dep[adj]);
		}
		if(mark[adj] < lm) {
			res = DFS(adj, in, d + 1);
		}
	}
	
	mark[node] = lm + 1;
	return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(an, -1, sizeof an);
	
	for(int i = 0; i < MAXN; i++) par[i] = i;
	
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> E[i].u >> E[i].v >> E[i].w;
		ind[i] = i;
	}
	sort(ind, ind + m, CMP);
	E[m].w = INF;
	
	ll i, j;
	edge e;
	ll k = 0;
	while(k < m){
		//debug(k);
		j = k;
		while((E[ ind[k] ].w == E[ ind[j] ].w) and (j < m)) j++;
		//debug(j);
		for(int i = k; i < j; i++){
			e = E[ ind[i] ];
			if(get_par(e.u) == get_par(e.v)) {
				//debug(ind[i]);
				an[ ind[i] ] = 0;
				continue;
			}
			
			e.u = par[e.u]; e.v = par[e.v];
			E[ ind[i] ] = e;
			
			G[par[e.u]].pb(ind[i]);
			G[par[e.v]].pb(ind[i]);
			
			V.pb(par[e.u]); V.pb(par[e.v]);
			//debug(par[e.u]); debug(par[e.v]);
		}
		
		for(auto node : V){
			if(mark[node] < lm) {
				//debug(node);
				DFS(node, -1, 0);
			}
		}
		
		for(int i = k; i < j; i++){
			e = E[ ind[i] ];
			G[par[e.u]].clear();
			G[par[e.v]].clear();
			merge(e.u, e.v);
		}
		V.clear();
		lm += 4;
		
		k = j;
	}
	
	cout << anssss;
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