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

const int LOGN = 20;
const int MAXN = int(1e5)+1;
vector<VI> graph;
int DP[MAXN][LOGN];
int level[MAXN];
int visited[MAXN];
int numSubtree[MAXN];
int root=0;


int dfs(int u)
{
	visited[u]=1;
	numSubtree[u]=0;
	for(int i=0;i<SZ(graph[u]);i++)
	{
		int v = graph[u][i];
		if(!visited[v])
		{
			level[v]=level[u]+1;
			DP[v][0]=u;
			numSubtree[u]+=dfs(v);
		}
	}
	return numSubtree[u]+1;
}



int lca(int a,int b)
{
	if(level[a]>level[b])
		swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;(1<<i)<=d;i++)
		if(d & (1<<i))
			b = DP[b][i];

	if(a == b)
		return a;

	int msb=0;
	for(int i=0;i<LOGN;i++)
		if(DP[a][i]!=DP[b][i])
			msb = i;
		else
			break;

	for(int i=msb;i>=0;i--)
		if(DP[a][i]!=DP[b][i])
		{
			a = DP[a][i];
			b = DP[b][i];
		}

	return DP[a][0];
}

/*
int middle(int L,int x)
{
	int x = (level[x]-level[L]);	
	
	for(int i=0;(1<<i)<=d;i++)
		if(d & (1<<i))
			x = DP[x][i];


	
}
*/

int middle(int a,int b)
{
		int L = lca(a,b);
		int d = level[a]-level[L];
		for(int i=0;(1<<i)<=d;i++)
			if(d & (1<<i))
				b = DP[b][i];

		a = L;

		d = level[b]-level[a];
		if(d&1)
			return 0;
		d = d/2;
		int child = b;
	
		for(int i=0;(1<<i)<=d;i++)
			if(d & (1<<i))
				b = DP[b][i];
		
		d--;

		for(int i=0;(1<<i)<=d;i++)
			if(d & (1<<i))
				child = DP[child][i];

		//trace2(child+1,b+1);

		return (numSubtree[b]+1) - (numSubtree[child]+1);


}

int solve(int a,int b)
{

	if(level[a]==level[b])
	{

		if(a==b)
		{
			return numSubtree[root]+1;
		}
		//LCA
		int msb=0;
		for(int i=0;i<LOGN;i++)
			if(DP[a][i]!=DP[b][i])
				msb = i;
			else
				break;

		for(int i=msb;i>=0;i--)
			if(DP[a][i]!=DP[b][i])
			{
				a = DP[a][i];
				b = DP[b][i];
			}

		return (numSubtree[DP[a][0]]+1) - (numSubtree[a]+1) - (numSubtree[b]+1) + (numSubtree[root] - numSubtree[DP[a][0]]);
	}

	if(level[a]<level[b])
		return middle(a,b);

	else
		return middle(b,a);
	/*	
	int d = level[a]-level[L];
		for(int i=0;(1<<i)<=d;i++)
			if(d & (1<<i))
				b = DP[b][i];

		a = L;

		d = level[b]-level[a];
		if(d&1)
			return 0;
		d = d/2;
		int child = b;
	
		for(int i=0;(1<<i)<=d;i++)
			if(d & (1<<i))
				b = DP[b][i];
		
		d--;

		for(int i=0;(1<<i)<=d;i++)
			if(d & (1<<i))
				child = DP[child][i];

		return (numSubtree[b]+1) - (numSubtree[child]+1);
	}
	else
	{
		swap(a,b);
	int d = level[a]-level[L];
		for(int i=0;(1<<i)<=d;i++)
			if(d & (1<<i))
				b = DP[b][i];

		a = L;

		d = level[b]-level[a];
		if(d&1)
			return 0;
		d = d/2;
		for(int i=0;(1<<i)<=d;i++)
			if(d & (1<<i))
				b = DP[b][i];
		return (numSubtree[b]+1);

	}*/
}


int main()
{
	int n;
	si(n);
	graph = vector<VI>(n);

	for(int i=0;i<n-1;i++)
	{
		int u,v;
		si(u);si(v);
		graph[u-1].PB(v-1);
		graph[v-1].PB(u-1);
	}

	SET(visited,0);
	DP[root][0]=root;
	level[root]=0;
	dfs(root);


	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[j][i] = DP[DP[j][i-1]][i-1];


	int m;
	si(m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		si(x);si(y);
		dout(solve(x-1,y-1));
	}
	return 0;
}