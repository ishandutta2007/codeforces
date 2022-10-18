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
const int LOGN = 20;
int DP[LOGN][N],level[N],sub[N],arr[N],dep[N],T;
LL dist[N],up[N];
VI g[N];
void dfs(int u,int p)
{
	sub[u]=1;DP[0][u]=p;arr[u]=T++;
	for(auto w:g[u])
	{
		if(w==p)continue;
		level[w]=level[u]+1;
		dfs(w,u);
		sub[u]+=sub[w];
		dist[u]+=dist[w] + sub[w];
	}
	dep[u]=T++;
}
void dfs2(int u,int p)
{
	for(auto w:g[u])
		if(w!=p)
		{
			up[w]=up[u]+(dist[u]-sub[w]-dist[w]) + (sub[u]-sub[w]) + sub[1]-sub[u];
			dfs2(w,u);
		}
}
bool anc(int p,int u)
{
	return arr[u]>arr[p] && dep[u]<dep[p];
}
int goup(int u,int d)
{
	for(int i=0;i<LOGN;i++)
		if((1<<i)&d)
			u=DP[i][u];
	return u;
}
int lca(int u,int v)
{
	if(level[u]>level[v])swap(u,v);
	if(anc(u,v))return u;
	v = goup(v,level[v]-level[u]);
	for(int i=LOGN-1;i>=0;i--)
		if(DP[i][u]!=DP[i][v])
			u=DP[i][u],v=DP[i][v];
	return DP[0][u];
}
double go(int u,int v)
{
	if(level[u]>level[v])swap(u,v);
	LL cnt1,cnt2,d1,d2,d;
	int LCA = lca(u,v);
	d = level[u]+level[v]-2*level[LCA];
	if(anc(u,v))
	{
		cnt1=sub[v],d1=dist[v];
		int w = goup(v,level[v]-level[u]-1);
		cnt2=sub[1]-sub[w],d2=up[u] + dist[u]-sub[w]-dist[w];
	}
	else
	{
		cnt1=sub[v],d1=dist[v];
		cnt2=sub[u],d2=dist[u];
	}
	LL cnt = cnt1*cnt2;
	return ((d+1.0)*cnt + d1*cnt2 + d2*cnt1)/(1.0*cnt);
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		si(u);si(v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,1);dfs2(1,1);
	for(int i=1;i<LOGN;i++)
		for(int j=1;j<=n;j++)
			DP[i][j]=DP[i-1][DP[i-1][j]];
	while(m--)
	{
		int u,v;
		si(u);si(v);
		printf("%.7lf\n",go(u,v));
	}
	return 0;
}