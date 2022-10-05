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
vector<int>g[maxn];
int n,q;
int tin[maxn],tout[maxn],timer,up[maxn][20],depth[maxn];
int p[maxn],used[maxn],cnt[maxn],dp[maxn];
void DFS(int v,int p){
	tin[v]=++timer;
	up[v][0]=p;
	depth[v]=depth[p]+1;
	for(int i=1;i<LOG;i++)
		up[v][i]=up[up[v][i-1]][i-1];	
	for(auto to:g[v])
		if( to!=p )
			DFS(to,v);
	tout[v]=timer;
	cnt[v]=tout[v]-tin[v]+1;
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
	return depth[v]+depth[u]-2*depth[lca(v,u)];
}
void dfs(int v,int p){
	cnt[v]=1;
	for( auto to:g[v] )
		if(!used[to] && to!=p){
			dfs(to,v);
			cnt[v]+=cnt[to];
		}
}
int getctr(int v,int p,int sz){
	for( auto to:g[v] )
		if( !used[to] && to!=p && cnt[to]>sz/2 )
			return getctr(to,v,sz);
	return v;
}
void build(int v){
	used[v]=1;
	for( auto to:g[v] )
		if( !used[to] ){
			dfs(to,to);
			to=getctr(to,to,cnt[to]);
			p[to]=v;
			build(to);
		}
}
void paint(int v){
	int u=v;
	while(u!=0){
		dp[u]=min(dp[u],dis(u,v));
		u=p[u];
	}
}
int get(int v){
	int u=v,res=1e9;
	while(u!=0){
		res=min(dp[u]+dis(u,v),res);
		u=p[u];
	}
	return res;
}

int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    IOS                          
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int v,u;
		cin>>v>>u; 
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i=1;i<=n;i++)
		dp[i]=1e9;
	DFS(1,1);
	dfs(1,1);
	build(getctr(1,1,n));
	paint(1);
	while(q--){
		int type,v;
		cin>>type>>v;
		if(type==1)
			paint(v);	
		else
			cout<<get(v)<<endl;
	}
	
}