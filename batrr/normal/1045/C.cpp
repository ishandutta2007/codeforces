#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, LOG = 20;
const ll INF = 1e18;

vector< int > g[N], G[N];
int n, m, q, V = 1e5 + 1, pr[N], p[N], sz[N], depth[N];
int tin[N], tout[N], timer, up[N][LOG], lvl[N];
bool was[N];

int getp(int v){
	if(p[v] == v)
		return v;	
	return p[v] = getp(p[v]);
}
void Merge(int v,int u){
	v = getp(v);
	u = getp(u);
	if(v == u)
		return;
	if(sz[v] > sz[u])
		swap(v, u);
	sz[v] += sz[u];
	p[u] = v;
}
void dfs1(int v){
	was[v] = 1;
	pii mn = {1e9, 0}; 
	for(auto to : g[v]){
		if(to == pr[v])
			continue;
		if(!was[to]){
			pr[to] = v;
			depth[to] = depth[v] + 1;
			dfs1(to);
		}else
			mn = min(mn, {depth[to], to});
	}
	int u = mn.s;
	if(u == 0 || getp(v) == getp(u))
		return;
	vector< int > vec;
	while(true){
		G[v].pb(V);
		G[V].pb(v);
		Merge(v, V);
		vec.pb(v);
		if(v == u)
			break;
		v = pr[v];
	}                             
	V++;
}
void dfs2(int v, int pr){
	tin[v] = timer++;
	up[v][0] = pr;
	lvl[v] = lvl[pr] + 1;
	for(int i = 1; i < LOG; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(auto to : G[v])
		if(to != pr)
			dfs2(to, v);
	tout[v] = timer++;
}
bool upper(int v,int u){
	return tin[v] <= tin[u] && tin[u] <= tout[v];
}
int lca(int v,int u){
	if(upper(v, u))
		return v;	
	if(upper(v, u))
		return u;	
	for(int i = LOG - 1; i >= 0; i--)
		if(!upper(up[v][i], u))
			v = up[v][i];
	return up[v][0];
}
int dist(int v,int u){
	return lvl[v] + lvl[u] - 2 * lvl[lca(v, u)];
}
int main(){
	for(int i = 0; i < N; i++)
		p[i] = i, sz[i] = 1;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < m; i++){
    	int v, u;
    	scanf("%d%d", &v, &u);
    	g[v].pb(u);
    	g[u].pb(v);
    } 
	dfs1(1);
	for(int v = 0; v < N; v++)
    	for(auto to : g[v])
    		if(getp(v) != getp(to)){
    			Merge(v, V);
    			Merge(to, V); 
    			G[v].pb(V);
    			G[V].pb(v);
    			G[to].pb(V);
    			G[V].pb(to);
    			V++;
    		}
	dfs2(1, 1);     			
    while(q--){
    	int v, u;
    	scanf("%d%d", &v, &u);
    	printf("%d\n", dist(v, u) / 2);
    }

	return 0;
}