#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=101,LOG=18,block=450,mod=1e9+7,N=1e6+12;
vector<int>g[maxn],G[maxn];
int n,m,q,p2[maxn];
int tin[maxn],tout[maxn],timer,up[maxn][20],depth[maxn];
int pr[maxn],was[maxn];
int sz[maxn],p[maxn];
int getp(int v){
	if(p[v]==v)
		return v;
	return p[v]=getp(p[v]);
}
void Merge(int v,int u){
	v=getp(v);
	u=getp(u);
	if(v==u)
		return;
	if( sz[v] < sz[u] )
		swap(v,u);
	sz[v]+=sz[u];
	p[u]=v;
}
void DFS(int v){
	was[v]=1;
	for(auto to:g[v]){
		if( to!=pr[v] ){
			if(was[to] ){
				if(getp(v)==getp(to))
					continue;
				int u=v;
				while(u!=to){
					u=pr[u];
					Merge(v,u);
				}
			}else{
				pr[to]=v;
				DFS(to);
			}
		}
	}
}
void dfs(int v,int p){
	depth[v]=depth[p];
	if( sz[v] != 1 )
		depth[v]++;
	tin[v]=++timer;
	up[v][0]=p;
	for(int i=1;i<LOG;i++)
		up[v][i]=up[up[v][i-1]][i-1];
    for( auto to:G[v] )
		if( to!=p && to!=v )
			dfs(to,v);
	tout[v]=timer;
}
bool upper(int v,int u){
	return ( tin[v]<= tin[u] && tin[u]<=tout[v]);
}
int lca(int v,int u){
	if( upper(v,u) )
		return v;
	if( upper(u,v) )
		return u;
	for(int i=LOG-1;i>=0;i--)
		if(!upper(up[v][i],u))
			v=up[v][i];
	return up[v][0];
}
int dis(int v,int u){
	return depth[v]+depth[u]-2*depth[lca(v,u)]+(sz[lca(v,u)]!=1);
}       
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    IOS                          
	p2[0]=1;
	for(int i=1;i<maxn;i++)
		p2[i]=p2[i-1]*2%mod;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int v,u;
		cin>>v>>u; 
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i=1;i<=n;i++)
		sz[i]=1,p[i]=i;
	DFS(1);
	for(int v=1;v<=n;v++)
		for(auto to:g[v] )
			G[getp(v)].pb(getp(to));
	dfs(getp(1),getp(1));
	cin>>q;
	while(q--){
		int v,u;
		cin>>v>>u;
		cout<<p2[dis(getp(v),getp(u))]<<endl;
	}
}