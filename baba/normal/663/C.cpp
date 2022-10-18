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

const int N = int(2e5)+10;
const int M = int(1e5)+5;
const int INF = int(1e9);
int U[N],V[N],W[N],vis[N],D[N],comp[N],val[N],ans[N],parent;
VI g[N],rg[N],G[N],nodes;
int n,m;
int adj(int u,int e)
{
	return U[e]^V[e]^u;
}
void get(int u)
{
	nodes.PB(u);nodes.PB(u+M);vis[u]=1;
	for(auto e:G[u]){
		int w = adj(u,e);
		if(vis[w])continue;
		get(w);
	}		
}
int NOT(int u)
{
	if(u<M)return u+M;
	else return u-M;
}
void addEdge(int u,int v)
{
//	trace(u,v);
	u=NOT(u);
	g[u].PB(v);rg[v].PB(u);
	u=NOT(u);v=NOT(v);swap(u,v);
	g[u].PB(v);rg[v].PB(u);
}
void clear(int u)
{
	g[u].clear(),rg[u].clear(),vis[u]=0,val[u]=0,comp[u]=0;
	for(auto e:G[u])
		D[e]=0;
}
VI order,component;
//g:graph,rg:reverse graph 
void dfs1(int u){
  vis[u]=1;
	for(auto w:g[u])
		if(!vis[w])
			dfs1(w);
  order.PB(u);
}
void dfs2(int u){
  vis[u]=1;comp[u]=parent;
	for(auto w:rg[u])
		if(!vis[w])
			dfs2(w);
} 
int go(int t)
{
	for(auto u:nodes)clear(u);
	for(auto u:nodes)
		for(auto e:G[u])
			if(!D[e]){
				D[e]=1;
				if(W[e]==t)addEdge(U[e],V[e]),addEdge(NOT(U[e]),NOT(V[e]));
				else addEdge(U[e],NOT(V[e])),addEdge(NOT(U[e]),V[e]);
			}
	order.clear();
	for(auto i:nodes)
	 if(!vis[i])
			dfs1(i);
	for(auto u:nodes)vis[u]=0;
	reverse(ALL(order));VI Cmp;
	for(auto i:order){
		if(!vis[i])
			parent = i,Cmp.PB(i),dfs2(i);	
	}
	for(auto u:nodes)
	{
	//	trace(u,NOT(u),comp[u],comp[NOT(u)]);
		if(comp[u]==comp[NOT(u)])
			return INF;
	}
	reverse(ALL(Cmp));
	int a = 0, b = 0;
	for(auto u : Cmp)
	{
	//	trace(u,val[u]);
		if(!val[u])
		{
			val[u]=1;
			val[comp[NOT(u)]]=-1;
		}
	}
	for(auto u:nodes)
		if(u<M)
			(val[comp[u]]==1)?a++:b++;
	int V = (a>b?0:1);
	for(auto u:nodes)
		if(u<M && val[comp[u]]==1)
			ans[u]=V;
		else if(u<M)
			ans[u]=1-V;
	//trace(a,b);
	return min(a,b);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		char x;
		scanf("%d %d %c",U+i,V+i,&x);
		G[U[i]].PB(i);G[V[i]].PB(i);
		W[i]=(x=='R'?1:0);
	}
	LL Ans1 = 0, Ans2 = 0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			nodes.clear();get(i);
			Ans1+=go(0);Ans2+=go(1);
		}
	LL Ans = min(Ans1,Ans2);
	if(Ans >= INF)puts("-1");
	else 
	{
		lldout(Ans);int t = (Ans == Ans1?0:1);
		SET(vis,0);
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				nodes.clear();get(i);go(t);
			}
		for(int i=1;i<=n;i++)
			if(ans[i])
				printf("%d ",i);
		puts("");
	}
	return 0;
}