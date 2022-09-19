#include <bits/stdc++.h>

#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif

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
const ll MAXN = (ll) 5e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll mark[MAXN], order[MAXN];
map<ll, ll> ma[MAXN];
vector<ll> g[MAXN], to_DFS[MAXN], components[MAXN];
set<ll> not_visited;


bool CMP(ll i, ll j){
	return g[i].size() < g[j].size();
}

bool CMP2(ll i, ll j){
	return mark[i] > mark[j];
}

void DFS(ll node, ll in){
	if(mark[node]) return ;
	mark[node] = in;
	
	not_visited.erase(node);
	
	for(auto adj : not_visited){
		if(( ma[min(node, adj)].count(max(node, adj)) == 0) && (!mark[adj])){
			to_DFS[node].pb(adj);
		}
	}
	
	for(auto x : to_DFS[node]){
		not_visited.erase(x);
	}
	
	for(auto x : to_DFS[node]) DFS(x, in);
	return ;
}

void print(ll ind, ll cnt){
	for(int i = 0, j = ind; i < cnt; i++,j--) printf(" %lld", order[j]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	scanf("%lld%lld", &n, &m);
	ll u, v;
	for(int i = 0; i < m; i++){
		scanf("%lld%lld", &u, &v);
		if(u > v) swap(u, v);
		ma[u][v] = 1;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(int i = 1; i <= n; i++) not_visited.insert(i);
	//for(int i = 1; i <= n; i++) g[0].pb(i);
	//for(int i = 1; i <= n; i++) g[i].pb(0), ma[i][0] = true, ma[0][i] = true;
	ll ind = 1;
	
	for(int i = 1; i <= n; i++) {
		if(g[i].size() < g[ind].size()) ind = i;
	}
	
	ll coms = 1;
	DFS(ind, coms);
	coms ++;
	
	for(int i = 1; i <= n; i++){
		if(!mark[i]){
			DFS(i, coms);
			coms ++;
		}
	}
	
	//sort(order, order + n, CMP2);
	
	printf("%lld\n", coms - 1 - 1);
	
	//for(int i = 1; i <= n; i++) printf("%lld ", mark[i]);
	//printf("\n");
	/*
	for(int i = 1; i <= n; i++) components[mark[i]].pb(i);
	
	for(int i = 1; i < coms; i++){
		printf("%lld", (ll) components[i].size());
		for(int j = 0; j < components[i].size(); j++) printf(" %lld", components[i][j]);
		printf("\n");
	}
	*/
	/*
	ll cnt = 1;
	for(int i = 1; i < n; i++){
		if(mark[order[i]] == mark[order[i - 1]]) cnt ++;
		else {
			printf("%lld", cnt);
			print(i - 1, cnt);
			printf("\n");
			
			cnt = 1;
		}
	}
	
	printf("%lld", cnt);
	print(n - 1, cnt);
	printf("\n");*/
	/*for(int i = 0; i < coms; i++){
		printf("%lld", (ll) co[i].size());
		for(auto y : co[i]) printf(" %lld", y);
		printf("\n");
	}*/
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