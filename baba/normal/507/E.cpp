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
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

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

vector< vii > graph;


int main()
{
	int n,m;
	din(n);din(m);
	graph = vector< vii >(n);
	int K=0;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		din(a);din(b);din(c);
		graph[a-1].PB(MP(b-1,c));
		graph[b-1].PB(MP(a-1,c));
		if(!c)
			K++;
	}

	int start = 0;
	int end = n-1;

	vi visited(n,0);
	vi parent(n,-1);
	vi dist(n,-1);
	vi dp(n,0);

	queue<int> Q;
	Q.push(start);
	visited[start]=1;
	dist[start]=0;
	dp[start]=0;

	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		for(int i=0;i<SZ(graph[u]);i++)
		{
			int v = graph[u][i].F;
			int state = graph[u][i].S;
			if(!visited[v])
			{
				visited[v]=1;
				parent[v]=u;
				dist[v]=dist[u]+1;
				if(state==1)
					dp[v]=dp[u];
				else
					dp[v]=dp[u]+1;
				Q.push(v);
			}
			else if(dist[v]==dist[u]+1)
			{
				int check = dp[u] + (state==1?0:1);
				if(check<dp[v]){
					dp[v]=check;
					parent[v]=u;
				}
			}
		//	trace5(u+1,v+1,parent[v],dist[v],dp[v]);
		}
	}

	int ans = m - dist[end] - K + 2*dp[end];
	dout(ans);
	/*for(int i=end;i!=-1;i=parent[i])
		printf("%d ",i);
	printf("\n");
	*/

	set< ii >Hp,Hp2;
	for(int i=end;i!=start;i=parent[i])
	{
		if(parent[i]<i)
			Hp.insert(MP(parent[i],i));
		else
			Hp.insert(MP(i,parent[i]));
	//	trace2(i,parent[i]);
	}

/*

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<SZ(graph[i]);j++)
			trace2(i,graph[i][j].F);
	}
*/

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<SZ(graph[i]);j++)
		{
			int u = i;
			int v = graph[i][j].F;
			int state = graph[i][j].S;
			//trace2(i,v);
			if(u>v)swap(u,v);

			int x = Hp.count(MP(u,v));
			int y = Hp2.count(MP(u,v));
			if(x && !y && state == 0)
			{
				Hp2.insert(MP(u,v));
				printf("%d %d %d\n",u+1,v+1,1);
			}
			else if(!x && !y && state==1)
			{
				Hp2.insert(MP(u,v));
				printf("%d %d %d\n",u+1,v+1,0);
			}


		}
	}

	return 0;
}