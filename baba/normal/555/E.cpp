//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(2e5)+10;
const int LOGN = 20;
int U[N],V[N];
VI graph[N];
VI tree[N];
int isbridge[N],comp[N],comp2[N],cmpno;
int vis[N],up[N],down[N];
int arr[N],T;
queue<int> Q[N];
int DP[N][LOGN],level[N];
bool ok;
int adj(int u,int e)
{
	return u==U[e]?V[e]:U[e];
}
int dfs0(int u,int ee)	//mark the bridges
{
	comp2[u] = cmpno;
	arr[u]=T++;
	int dbe = arr[u];
	vis[u]=1;
	for(int i=0;i<SZ(graph[u]);i++)
	{
		int e = graph[u][i];
		int w = adj(u,e);
		if(!vis[w])
			dbe = min(dbe,dfs0(w,e));
		else if(e!=ee)
			dbe = min(dbe,arr[w]);
	}
	if(dbe == arr[u] && ee!=-1)
		isbridge[ee]=1;
	return dbe;
}
void dfs1(int u)	//build the bridge tree
{
	int currcmp = cmpno;
	Q[currcmp].push(u);
	vis[u]=1;
	while(!Q[currcmp].empty())
	{
		int v = Q[currcmp].front();
		Q[currcmp].pop();
		comp[v] = currcmp;
		for(int i=0;i<SZ(graph[v]);i++)
		{
			int e = graph[v][i];
			int w = adj(v,e);
			if(vis[w])continue;
			if(isbridge[e])
			{
				cmpno++;
				tree[currcmp].PB(cmpno);
				tree[cmpno].PB(currcmp);
				dfs1(w);
			}
			else
			{
				Q[currcmp].push(w);
				vis[w]=1;
			}
		}
	}
}
void dfs2(int u)
{
	vis[u]=1;
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(!vis[w])
		{
			level[w]=level[u]+1;
			DP[w][0]=u;
			dfs2(w);
		}
	}
}
int lca(int a,int b)
{
	if(level[a]>level[b])
		swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<LOGN;i++)
		if((1<<i)&d)
			b = DP[b][i];
	if(a==b)
		return a;
	for(int i=LOGN-1;i>=0;i--)
		if(DP[a][i]!=DP[b][i])
		{
			a = DP[a][i];
			b = DP[b][i];
		}
	return DP[a][0];
}
void dfs3(int u)
{
	vis[u]=1;
	for(int i=0;i<SZ(tree[u]);i++)
	{
		int w = tree[u][i];
		if(vis[w])continue;
		dfs3(w);
		up[u] += up[w];
		down[u]+= down[w]; 
	}
	if(up[u]>0 && down[u]>0)
		ok = false;
}
int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",U+i,V+i);
		graph[U[i]].PB(i);
		graph[V[i]].PB(i);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			dfs0(i,-1);
			cmpno++;
		}
	SET(vis,0);
	cmpno=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			dfs1(i);
			cmpno++;
		}
	SET(vis,0);
	for(int i=0;i<cmpno;i++)
		if(!vis[i])
		{
			level[i]=0;
			DP[i][0]=i;
			dfs2(i);
		}
	for(int j=1;j<LOGN;j++)
		for(int i=0;i<cmpno;i++)
			DP[i][j]=DP[DP[i][j-1]][j-1];
	while(q--)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		if(comp2[u]!=comp2[v])
		{
			printf("NO\n");
			return 0;
		}
		u = comp[u];
		v = comp[v];
		if(u==v)
			continue;
		up[u]++;
		down[v]++;
		int LCA = lca(u,v);
		up[LCA]--;down[LCA]--;
	}
	ok = true;
	SET(vis,0);
	for(int i=0;i<cmpno;i++)
		dfs3(i);
	printf("%s\n",ok?"YES":"NO");
	return 0;
}