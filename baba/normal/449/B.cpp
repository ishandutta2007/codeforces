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
const int N = int(2e5) + 20;
const int M = 2*N;
const LL INF = LL(1e18);
const int road = 0,train = 1;
const int removed = 0,notremoved = 1;
int U[M],V[M],W[M],type[M];
VI graph[N];
int visited[N];
LL dist[N];
int trains[M];
int adj(int u,int edge)
{
	return (U[edge]==u?V[edge]:U[edge]);
}

typedef pair< pair<pair<LL,int> , pair<int,int> >, int > State;
	// distance,road/train , removed[train] , trainEgde , last vertex 
	// 			(valid only if incoming is train else -1)

State mp(LL dist,int Type,int isNotRemoved,int e, int u)
{
	return MP(MP(MP(dist,Type) , MP(isNotRemoved,e) ) , u );
}
int main()
{
	int n,m,k;
	si(n);si(m);si(k);
	int len=0;
	for(len=0;len<m;len++)
	{
		scanf("%d %d %d",U+len,V+len,W+len);
		type[len] = road;
		graph[U[len]].PB(len);
		graph[V[len]].PB(len);
	}
	for(int i=0;i<k;i++)
	{
		U[len] = 1;
		scanf("%d %d",V+len,W+len);
		type[len]=train;
		graph[U[len]].PB(len);
		graph[V[len]].PB(len);
		len++;
	}
	for(int i=0;i<len;i++)
		trains[i] = notremoved;
	for(int i=0;i<=n;i++)
		dist[i] = INF;
	set< State > Q;	
	// distance,road/train , removed[train] , trainEgde , last vertex 
	// 			(valid only if incoming is train else -1)
	int source = 1;
	dist[source]=0;
	Q.insert(mp(0,road,-1,-1,source));
	while(!Q.empty())
	{
		State top = *Q.begin();
		Q.erase(Q.begin());
		int u = top.S;
		if(visited[u])
			continue;
		visited[u]=1;
		int ptype = top.F.F.S;	
		int trainState = top.F.S.F;
		int trainNo = top.F.S.S;
		if(ptype == train)
		{
			trains[trainNo] = removed;
			trainState = removed;
		}

		for(int i=0;i<SZ(graph[u]);i++)
		{
			int e = graph[u][i];
			int w = adj(u,e);
			if(dist[u] + W[e] <= dist[w])
			{
				dist[w] = dist[u] + W[e];
				int newPtype = type[e]==train?train:ptype;
				int newTrainState = type[e]==train?trains[e] : trainState;
				int newTrainNo = type[e]==train?e : trainNo;
				Q.insert(mp(dist[w],newPtype,newTrainState,newTrainNo,w));
			}
		}

	}
	int ans = 0;
	for(int i=0;i<len;i++)
		if(type[i] == train && trains[i] == notremoved)
			ans++;
	dout(ans);
	
	return 0;
}