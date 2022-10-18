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

const int N = int(1e5)+10;
const int INF = int(2e9);
VI graph[N],g[N];
int arr[N],dep[N],T;
int visited[N],vis[N];
bool cycle;
VI cmp;
void dfs(int u)
{
	arr[u] = T++;
	visited[u]=1;
	for(int i=0;i<SZ(graph[u]);i++)
	{
		int w = graph[u][i];
		if(!visited[w])
			dfs(w);
		else if(dep[w]==INF)
			cycle = true;
	}
	dep[u]=T++;
}
void dfs2(int u)
{
	cmp.PB(u);
	vis[u]=1;
	for(int i=0;i<SZ(g[u]);i++)
		if(!vis[g[u][i]])
			dfs2(g[u][i]);
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		si(u);si(v);
		u--;v--;
		graph[u].PB(v);
		g[u].PB(v);
		g[v].PB(u);
	}
	int ans=0;
	for(int i=0;i<n;i++)dep[i]=INF;
	for(int i=0;i<n;i++)
		if(!vis[i])
		{
			cycle = false;cmp.clear();
			dfs2(i);
			for(int j=0;j<SZ(cmp);j++)
				if(!visited[cmp[j]])
					dfs(cmp[j]);
			ans+=(cycle?SZ(cmp):SZ(cmp)-1);
		}
	dout(ans);

	return 0;
}