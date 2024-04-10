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
const int N = 2*int(1e5) + 1;
const int INF = int(1e9);
bool exist = false;
int visited[N];
int arrival[N];
int nodeByArrival[N];
int parent[N];
int t = 0;
int start,finish;
bool done = false;

VI graph[N];
VI path[3];
int pathNum=0;

II dfs(int u)
{
	//trace1(u+1);
	if(done)
		return MP(INF,-1);
	
	arrival[u] = t;
	nodeByArrival[t]=u;
	t++;
	
	visited[u] = 1;
	
	int dbe = arrival[u];
	int minDbe = -INF,numDbe=0;
	int minNode,sminNode;
	int nodes[2];
	//if(u==1)
	//	trace1(SZ(graph[u]));
	for(int i=0;i<SZ(graph[u]);i++)
	{
		if(done)
			return MP(INF,-1);
		if(numDbe>=2)
			break;
		int w = graph[u][i];
		
		//trace2(w+1,parent[u]+1);
		if(w==parent[u]) 
			continue;
		
		if(!visited[w])
		{
			parent[w]=u;
			II temp = dfs(w);
			//if(u==1)
			//	trace2(w,temp);
			
			//dbe = min(dbe,temp);
			if(dbe>temp.F)
			{
				dbe = temp.F;
				//sminNode = w;
			}
			if(temp.F<arrival[u])
			{
				nodes[numDbe++] = temp.S;//MISTAKE
				if(minDbe<temp.F)
				{
					minDbe = temp.F;
					minNode = temp.S;
				}
			//	minDbe = max(minDbe,temp);
			}
		}
		else
		{
			//dbe = min(dbe,arrival[w]);
			if(dbe>arrival[w])
			{
				dbe = arrival[w];
				//sminNode = w;
			}
			if(arrival[w]<arrival[u])
			{
				nodes[numDbe++] = u;
			//	minDbe = max(minDbe,arrival[w]);
				if(minDbe<arrival[w])
				{
					minDbe = arrival[w];
					minNode = u;
				}
			}
		}
	}

	if(numDbe >= 2)
	{
		//trace3(u,nodeByArrival[minDbe],p);
		done=true;
		start = u;
		finish = nodeByArrival[minDbe];

		
		sminNode = (nodes[0]==minNode?nodes[1]:nodes[0]);

		//trace5(u+1,start+1,finish+1,minNode+1,sminNode+1);

		//Add first path
		for(int i=start;i!=finish;i=parent[i])
			path[0].PB(i);
		path[0].PB(finish);


		//Add second path
		for(int i=minNode;i!=start;i=parent[i])
			path[1].PB(i);
		path[1].PB(start);
		reverse(ALL(path[1]));
		path[1].PB(finish);

		//Add third path
		for(int i=sminNode;i!=start;i=parent[i])
			path[2].PB(i);
		path[2].PB(start);
		reverse(ALL(path[2]));
		path[2].PB(nodeByArrival[dbe]);
		stack<int> s;
		for(int i=finish;i!=nodeByArrival[dbe];i=parent[i])
			s.push(i);
		while(!s.empty())
		{
			path[2].PB(s.top());
			s.pop();
		}
		//ALL PATHS ADDED :)
	}
	return MP(dbe,minNode);
}

/*int actualVisited[N];

bool dfs(int u)
{
	if(u==finish)
		return true;
	if(pathNum==3)
		return false;
	

	visited[u]=1;
	for(int i=0;i<SZ(graph[u]);i++)
	{
		if(u==start)
		{
			SET(visited,0);
			visited[start]=1;
		}
		int w = graph[u][i];
		if(!visited[w] && !actualVisited[w])
		{
			if(dfs(w))
			{
				path[pathNum].PB(w+1);
				if(w!=finish)
					actualVisited[w]=1;
				if(u == start)
				{
					path[pathNum].PB(u+1);
					pathNum++;
				}
				else
					return true;
			}
		}

	}
	return false;
}
*/
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		si(u);si(v);
		graph[u-1].PB(v-1);
		graph[v-1].PB(u-1);
	}

	/*
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" : ";
		for(int j=0;j<SZ(graph[i]);j++)
			cout<<1 + graph[i][j]<<" ";
		cout<<endl;
	}
	*/


	SET(visited,0);
	for(int i=0;i<n && !done;i++)
	{
		if(!visited[i])
		{
			parent[i] = i;
			dfs(i);
		}
	}

	if(!done)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	
	//SET(visited,0);
	/*SET(actualVisited,0);
	actualVisited[start]=1;	
	dfs(start);*/
	//trace3(start,finish,pathNum);
	for(int i=0;i<3;i++)
	{
		printf("%d ",SZ(path[i]));
		for(int j=0;j<SZ(path[i]);j++)
			printf("%d ",path[i][j] + 1);
		printf("\n");
	}
	return 0;
}