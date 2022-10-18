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
#define MAX 100002

vector< vii >graph;
vii road;
lli fromUpVal[MAX];
lli fromUpCount[MAX];
lli fromDownVal[MAX];
lli fromDownCount[MAX];
int visited[MAX];
int parent[MAX];
double ans;


int binarysearch(int r,int elem)
{
	int first=0;
	int last=SZ(graph[r])-1;
	int middle=(first+last)/2;
	while(first<=last)
	{
		if(graph[r][middle].F<elem)
			first=middle+1;
		else if(graph[r][middle].F==elem)
			return middle;
		else
			last=middle-1;

		middle = (first + last)/2;
	}
	return -1;
}


void changeLength(int r,int w)
{
	int p = ((parent[road[r].F]==road[r].S) ? road[r].S : road[r].F);
	int c = ((parent[road[r].F]==road[r].S) ? road[r].F : road[r].S);
	int oldW;
	int pos = binarysearch(p,c);
	oldW = graph[p][pos].S;
	graph[p][pos].S=w;

	pos = binarysearch(c,p);
	graph[c][pos].S=w;

	
	ans += ((double)(w - oldW)*((double)(fromDownCount[c]+1)*fromUpCount[c]));

}




void calcFromUp(int u)
{
	visited[u]=1;
	for(int i=0;i<SZ(graph[u]);i++)
	{
		int w=graph[u][i].F;
		int weight = graph[u][i].S;
		if(!visited[w])
		{
			parent[w]=u;
			fromUpCount[w] = fromUpCount[u] + fromDownCount[u] - fromDownCount[w];
			fromUpVal[w]=fromUpVal[u] + fromDownVal[u] - fromDownVal[w] + weight*(fromUpCount[w] - fromDownCount[w]-1);
			calcFromUp(w);
		}

	}
}



int calcFromDown(int u)
{
	fromDownVal[u]=0;
	fromDownCount[u]=0;
	int count=0;

	visited[u]=1;

	for(int i=0;i<SZ(graph[u]);i++)
	{
		int w=graph[u][i].F;
		int weight = graph[u][i].S;
		if(!visited[w]){
			count=calcFromDown(w) + 1;
			fromDownVal[u]+=fromDownVal[w] + weight*count;
			fromDownCount[u]+=count;
		}
	}
	return fromDownCount[u];
}



int main()
{
	int n;
	din(n);
	graph = vector< vii >(n);
	road = vii(n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,l;
		scanf("%d %d %d",&a,&b,&l);
		road[i] = MP(a-1,b-1);
		graph[a-1].PB(MP(b-1,l));
		graph[b-1].PB(MP(a-1,l));
	}

	for(int i=0;i<n;i++)
		sort(graph[i].begin(),graph[i].end());

	SET(visited,0);
	calcFromDown(0);
	
	SET(visited,0);
	fromUpVal[0]=0;
	fromUpCount[0]=0;
	parent[0]=-1;
	calcFromUp(0);

	ans=0;
	for(int i=0;i<n;i++)
		ans+=fromUpVal[i]+fromDownVal[i];
	ans/=2;

	int q;
	din(q);
	for(int i=0;i<q;i++)
	{
		int r,l;
		din(r);din(l);
		changeLength(r-1,l);
		printf("%.10lf\n",((ans*6)/((double)n*(double)(n-1))));
	}


	return 0;
}