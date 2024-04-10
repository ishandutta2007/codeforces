//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int N = int(1e5)+10;
const int M = int(1e5)+10;
VI tree[N],g[N];//edge list representation of graph
int U[M],V[M],vis[N],arr[N],T,cmpno,A[N],C[N];
bool isbridge[M]; // if i'th edge is a bridge edge or not 
int adj(int u,int e){
	return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge){ //mark bridges
	vis[u]=1;arr[u]=T++;
	int dbe = arr[u];
	for(int i=0;i<SZ(g[u]);i++){
		int e = g[u][i];int w = adj(u,e);
		if(!vis[w])dbe = min(dbe,dfs0(w,e));
		else if(e!=edge)dbe = min(dbe,arr[w]);
	}
	if(dbe == arr[u] && edge!=-1)isbridge[edge]=true;
	return dbe;
}
void dfs1(int u){//Build the bridge tree
	vis[u]=1;C[u]=cmpno;
	for(auto e:g[u])
		if(!isbridge[e] && !vis[adj(u,e)])
			dfs1(adj(u,e));
}
void buildBridgeTree(int n,int m)
{
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs0(i,-1);
	SET(vis,0);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs1(i),cmpno++;
	for(int i=0;i<m;i++)
		if(C[U[i]]!=C[V[i]])
			tree[C[U[i]]].PB(C[V[i]]),
				tree[C[V[i]]].PB(C[U[i]]);
	for(int i=1;i<=n;i++)
		A[C[i]]++;
}
int ans,add=1;
void dfs(int u)
{
	vis[u]=1;
	if(A[u]>1)add=0;
	for(auto w:tree[u])
		if(!vis[w])
			dfs(w);
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",U+i,V+i);
		g[U[i]].PB(i);
		g[V[i]].PB(i);
	}
	buildBridgeTree(n,m);
	SET(vis,0);
	for(int i=0;i<cmpno;i++)
		if(!vis[i])
			dfs(i),ans+=add,add=1;
	dout(ans);
	return 0;
}