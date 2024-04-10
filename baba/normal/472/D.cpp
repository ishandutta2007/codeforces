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
const int N = 2001;
int d[N][N];
VII tree[N];
int visited[N];
int d1[N][N];
int dsu[N];
pair<int,II> edges[N*N];
void showtree(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" : ";
		for(int j=0;j<SZ(tree[i]);j++)
			cout<<"("<<1+tree[i][j].F<<","<<tree[i][j].S<<") ";
		cout<<endl;
	}
}
void dfs(int u)
{
	visited[u]=1;
	for(int i=0;i<SZ(tree[u]);i++)
		if(!visited[tree[u][i].F])
			dfs(tree[u][i].F);
}
int Find(int x)
{
	if(dsu[x]==x)
		return x;
	return dsu[x] = Find(dsu[x]);
}
void Union(int a,int b)
{
	if(a==b)
		return;
	dsu[a]=b;
}
int main()
{
	int n;
	si(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			si(d[i][j]);
	bool ok = true;
	//basic checks
	for(int i=0;i<n;i++)
		if(d[i][i]!=0)
			ok = false;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(d[i][j]!=d[j][i] || d[i][j]==0)	//because ex5 suggests tree must be connected
				ok = false;
	//basic checks done
	if(!ok)
	{
		printf("NO\n");
		return 0;
	}

	//build the tree
	int len=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			edges[len++] = MP(d[i][j],MP(i,j));
	sort(edges,edges+len);
	for(int i=0;i<n;i++)
		dsu[i]=i;
	for(int i=0;i<len;i++)
	{
		int u = edges[i].S.F;
		int v = edges[i].S.S;
		if(Find(u)==Find(v))
			continue;
		Union(Find(u),Find(v));
		tree[u].PB(MP(v,edges[i].F));
		tree[v].PB(MP(u,edges[i].F));
	}
	//tree built
	
	//showtree(n);

	//check if connected
	SET(visited,0);
	dfs(0);
	for(int i=0;i<n;i++)
		if(!visited[i])
			ok = false;
	if(!ok)
	{
		printf("NO\n");
		return 0;
	}
	
	//Now check for distances
	for(int i=0;i<n;i++)
	{
		SET(visited,0);
		queue<int> Q;
		Q.push(i);
		visited[i]=1;
		d[i][i]=0;
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(int j=0;j<SZ(tree[u]);j++)
			{
				int w = tree[u][j].F;
				int weight = tree[u][j].S;
				if(!visited[w])
				{
					d1[w][i]=d1[i][w] = d1[i][u] + weight;
					Q.push(w);
					visited[w]=1;
				}
			}
		}
	}
	//trace1(ok);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
	//		trace4(i+1,j+1,d[i][j],d1[i][j]);
			if(d1[i][j]!=d[i][j])
				ok = false;
		}
	printf("%s\n",ok?"YES":"NO");
	return 0;
}