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

const int N = int(1e5)+10;
const int LOGN = 20;
const int MOD = int(1e9)+7;
VI g[N];
int up[N];
int down[N];
int U[N],V[N],D[N];
int DP[LOGN][N];
int level[N];
LL ans;
LL power(LL a,LL p)
{
	LL ret=1;
	while(p)
	{
		if(p&1)ret=(ret*a)%MOD;
		a = (a*a)%MOD;
		p = p/2;
	}
	return ret;
}
int adj(int u,int e)
{
	return U[e]==u?V[e]:U[e];
}
void dfs0(int u,int ee)
{
	for(int i=0;i<SZ(g[u]);i++)
	{
		int e = g[u][i];
		int w = adj(u,e);
		if(e==ee)continue;
		level[w]=level[u]+1;
		DP[0][w]=u;
		dfs0(w,e);
	}
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<LOGN;i++)
		if(d&(1<<i))
			b = DP[i][b];
	if(a==b)return a;
	for(int i=LOGN-1;i>=0;i--)
		if(DP[i][a]!=DP[i][b])
			a = DP[i][a],b=DP[i][b];
	return DP[0][a];
}
void dfs(int u,int ee)
{
	for(int i=0;i<SZ(g[u]);i++)
	{
		int e = g[u][i];
		int w = adj(u,e);
		if(e==ee)continue;
		dfs(w,e);
		up[u]+=up[w];
		down[u]+=down[w];
	}
	if(ee==-1)return;
	if(D[ee]==0)return;
	if(U[ee]==u)ans = (ans - 1 + power(2,down[u]))%MOD;
	else ans = (ans - 1 + power(2,up[u]))%MOD;
}
int main()
{
	int n;si(n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d %d",U+i,V+i,D+i);
		g[U[i]].PB(i);
		g[V[i]].PB(i);
	}
	DP[0][1]=1;
	dfs0(1,-1);
	for(int i=1;i<LOGN;i++)
		for(int j=1;j<=n;j++)
			DP[i][j]=DP[i-1][DP[i-1][j]];
	int k;si(k);
	int u=1;
	for(int i=0;i<k;i++)
	{
		int v;
		si(v);
		int LCA = lca(u,v);
		up[u]++;down[v]++;
		up[LCA]--;down[LCA]--;
		swap(u,v);
	}
	dfs(1,-1);
	lldout(ans);
	return 0;
}