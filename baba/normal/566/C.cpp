//Mobius_Treap
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
LL P[N];
int U[N],V[N],W[N];
bool done[N];
VI g[N];
double dir[N];
pair<int,double> ans;
int sub[N];
int vis[N];
int adj(int u,int e)
{
	return U[e]==u?V[e]:U[e];
}
void dfs(int u,int ee,int p,int d)
{
	dir[p] += P[u]*sqrt(d); 
	for(int i=0;i<SZ(g[u]);i++)
	{
		int e = g[u][i];
		if(e==ee)continue;
		int w = adj(u,e);
		dfs(w,e,p,d+W[e]);
	}
}
int go(int u)
{
	int mn=u;
	double sum=0;
	for(int i=0;i<SZ(g[u]);i++)
	{
		int e = g[u][i];
		int w = adj(u,e);
		dir[w]=0.0;
		dfs(w,e,w,W[e]);
		sum+=dir[w];
	}
	for(int i=0;i<SZ(g[u]);i++)
	{
		int e = g[u][i];
		int w = adj(u,e);
		if(sum-2*dir[w] < 0)
			mn = w;
	}
	return mn;
}
double get(int u,int ee=-1,int d=0)
{
	double ret=P[u]*d*sqrt(d);
	for(int i=0;i<SZ(g[u]);i++)
		if(g[u][i]!=ee)
			ret+=get(adj(u,g[u][i]),g[u][i],d+W[g[u][i]]);
	return ret;
}
int nn;
int dfs1(int u,int ee)
{
	nn++;
	sub[u]=1;
	for(int i=0;i<SZ(g[u]);i++)
		if(g[u][i]!=ee && !done[g[u][i]])
			sub[u]+=dfs1(adj(u,g[u][i]),g[u][i]);
	return sub[u];
}
int dfs2(int u,int ee)
{
	for(int i=0;i<SZ(g[u]);i++)
	{
		int e = g[u][i];
		if(e==ee || done[e])continue;
		int w = adj(u,e);
		if(sub[w]>nn/2)
			return dfs2(w,e);
	}
	return u;
}
void decompose(int u)
{
	nn=0;
	dfs1(u,-1);
	int centroid = dfs2(u,-1);
	vis[centroid]=1;
	double curr = get(centroid);
	if(curr<ans.S)
		ans.S=curr,ans.F=centroid;
	
	int w = go(centroid);
	if(vis[w])return;
	for(int i=0;i<SZ(g[centroid]);i++)
	{
		int e = g[centroid][i];
		if(adj(centroid,e)==w)
			done[e]=true;
	}
	decompose(w);
}
int main()
{
	int n;si(n);
	for(int i=0;i<n;i++)
		sll(P[i]);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d %d",U+i,V+i,W+i);
		U[i]--;V[i]--;
		g[U[i]].PB(i);
		g[V[i]].PB(i);
	}
	ans.S=2e20;
	decompose(0);
	printf("%d %.8lf\n",ans.F+1,ans.S);
	return 0;
}