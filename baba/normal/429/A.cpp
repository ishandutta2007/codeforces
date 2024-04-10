//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;
typedef vector< vi > 	vvi;
#define lli long long int
#define ulli unsigned long long int

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define gu getchar
#define pu putchar
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; din(t); while(t--)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define INF 1000000000  //1 billion (10^9) 

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

vector< vi > graph;
vi visited;
int count=0;
vi ans;
vi init,goal;

void dfs(int u,int h,int odd,int even)
{
	visited[u]=1;
	if((h&1 && odd&1) || (!(h&1) && even&1))
		init[u] = (init[u]+1)%2;
	
	if(init[u]!=goal[u])
	{
		init[u]=(init[u]+1)%2;
		ans.PB(u+1);
		if(h&1)
			odd++;
		else
			even++;
	}

	for(int i=0;i<SZ(graph[u]);i++)
	{
		int w=graph[u][i];
		if(!visited[w])
			dfs(w,h+1,odd,even);
	}
}

int main()
{
	int n;
	din(n);
	graph = vector< vi >(n);
	visited = vi(n,0);
	init = vi(n);
	goal = vi(n);

	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		graph[a-1].PB(b-1);
		graph[b-1].PB(a-1);
	}
	for(int i=0;i<n;i++)
		din(init[i]);
	for(int i=0;i<n;i++)
		din(goal[i]);

	dfs(0,0,0,0);
	dout(SZ(ans));
	for(int i=0;i<SZ(ans);i++)
		dout(ans[i]);



	return 0;
}