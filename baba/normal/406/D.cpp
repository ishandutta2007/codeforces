//Tanuj Khattar
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define TRACE
using namespace std;

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


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


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

/*LL power(LL a, LL p, LL mod)
{LL ret = 1;while(p){if(p&1)ret = (ret*a)%mod;a=(a*a)%mod;p/=2;}return ret;}*/


#define LOGN 20
#define N 100010

class point{
    public:
        LL x,y;
        point(){x=0;y=0;}
        point(LL _x,LL _y) : x(_x),y(_y){}
        ~point(){}
};

class vect{
    public:
        LL x,y;
        vect(){x=0;y=0;}
        vect(point a,point b){x = b.x-a.x; y = b.y-a.y;}
        ~vect(){}
};

LL cross(vect a, vect b)
{
    return (a.x*b.y - b.x*a.y);
}


int DP[N][LOGN]; //DP[a][i] = 2^i'th parent of i.
vector< VI >graph;
int visited[N];
int level[N];

void dfs(int u)
{
	visited[u]=1;
	for(int i=0;i<SZ(graph[u]);i++)
	{
		int w = graph[u][i];
		if(!visited[w])
		{
			DP[w][0]=u;
			level[w] = level[u] + 1;
			dfs(w);
		}
	}
}


int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int d = level[b]-level[a];
	
	for(int i=0;(1<<i)<=d;i++)
		if(d&(1<<i))
			b = DP[b][i];


	// a and b are at same level now
	
	if(a == b) return a;

	//find "h" the common height of both from LCA
	int msb=0;
	for(int i=0;DP[a][i]!=DP[b][i];i++)
		msb = i;
	
	for(int i=msb;i>=0;i--)
	{
		if(DP[a][i] != DP[b][i])
		{
			a = DP[a][i];
			b = DP[b][i];
		}
	}
	return DP[a][0];
}






int main()
{

    int n;
    si(n);
    vector<point> arr;
    for(int i=0;i<n;i++)
    {
        LL a,b;
        sll(a);sll(b);
        arr.PB(point(a,b));
    }
    
    stack<point> s;
    stack<vect> prev;
    stack<int> index;

    s.push(point(arr[n-1].x,0));
    index.push(-1);
    
    prev.push(vect(arr[n-1],s.top()));
    
    s.push(arr[n-1]);
    index.push(n-1);
    
    graph = vector< VI >(n);

    for(int i=n-2;i>=0;i--)
    {
        vect next = vect(arr[i],s.top());
        while(cross(prev.top(),next)<0ll)
        {
            s.pop();
            index.pop();
            prev.pop();
            next = vect(arr[i],s.top());
        }
        			
        graph[i].PB(index.top());
        graph[index.top()].PB(i);
        
	s.push(arr[i]);
        index.push(i);
        prev.push(next);
    }

    //0-Based indexing graph generated. I'll work on the LCA code and try to write it myself. :)

    SET(visited,0);
    DP[n-1][0]=n-1;
    level[n-1]=0;

    //dfs(n-1);
    //BFS instead of DFS ... 
    queue<int> q;
    q.push(n-1);
    visited[n-1]=1;
    while(!q.empty())
    {
	    int u = q.front();
	    q.pop();
	    for(int i = 0;i<SZ(graph[u]);i++)
	    {
		    int w = graph[u][i];
		    if(!visited[w])
		    {
			    DP[w][0]=u;
			    level[w]=level[u]+1;
			    visited[w]=1;
			    q.push(w);
		    }
	    }
    }
    //BFS ENDS


    for(int j=1;j<LOGN;j++)
    	for(int i=0;i<n;i++)
	    DP[i][j] = DP[DP[i][j-1]][j-1];

    int m;
    si(m);
    for(int i=0;i<m;i++)
    {
	    int a,b;
	    si(a);si(b);
	    printf("%d ",lca(a-1,b-1)+1);
    } 
    printf("\n");

    return 0;
}