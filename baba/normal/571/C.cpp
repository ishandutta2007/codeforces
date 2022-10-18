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
VII g[N];
VI C[N];
int ans[N];
int sz[N];
int val[N];
int comp;
bool istree;
int root;
int vis[N],vis2[N];
set<int> S[N];
int assign(int x,int v)
{
	if(S[v].count(x))
		return 1;
	else
		return 0;
}
void dfs(int u,int ee)
{
	vis[u]=1;
	sz[comp]++;
	if(val[u]==1)
	{
		root=u;
		istree=false;
		return;
	}
	for(int i=0;i<SZ(g[u]);i++)
	{
		int w = g[u][i].F;
		int e = g[u][i].S;
		if(vis[w] && e!=ee)
		{
			istree=false; 
			root = w;
			ans[e] = assign(e,w);
			return;
		}
		else if(!vis[w])
			dfs(w,e);
		if(root!=-1)return;
	}
}
void dfs2(int u,int ee)
{
	vis2[u]=1;
	for(int i=0;i<SZ(g[u]);i++)
	{
		int w = g[u][i].F;
		int e = g[u][i].S;
		if(!vis2[w])
		{
			ans[e] = assign(e,w);
			dfs2(w,e);
		}
	}
}
int main()
{
	int n,m;si(n);si(m);
	for(int i=1;i<=n;i++)
	{
		int k;si(k);
		for(int j=0;j<k;j++)
		{
			int x;
			si(x);
			S[i].insert(x);
			if(x<0)
				C[-x].PB(-i);
			else
				C[x].PB(i);
		}
	}
	for(int i=1;i<=m;i++)
		ans[i]=-1;
	for(int i=1;i<=m;i++)
	{
		if(SZ(C[i])==0)
		{
			ans[i]=1;
			continue;
		}
		if(SZ(C[i])==2 && (LL)C[i][0]*(LL)C[i][1]<0)
		{
			g[abs(C[i][0])].PB(MP(abs(C[i][1]),i));
			g[abs(C[i][1])].PB(MP(abs(C[i][0]),i));
			continue;
		}
		else if(C[i][0]<0)
			ans[i]=0;
		else
			ans[i]=1;
		if(SZ(C[i])==1)
			val[abs(C[i][0])]=1;
		else 
			val[abs(C[i][0])]=val[abs(C[i][1])]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis2[i])
		{
			istree=true;
			root=-1;
			dfs(i,-1);
			if(istree && sz[comp]==1 && val[i]==1)
				istree=false;
			if(istree)
			{
				puts("NO");
				return 0;
			}
			dfs2(root,-1);
			comp++;
		}
	}
	for(int i=1;i<=m;i++)
		if(ans[i]==-1)
			ans[i]=1;
	puts("YES");
	for(int i=1;i<=m;i++)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}