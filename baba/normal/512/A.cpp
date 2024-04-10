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

int visited[30];
vector< vi > graph;
string seq;
int t=0;
int arr[30],dep[30];
void dfs(int u)
{
	visited[u]=1;
	arr[u]=t++;
	for(int i=0;i<SZ(graph[u]);i++)
	{
		int w = graph[u][i];
		if(!visited[w])
			dfs(w);
	}
	dep[u] = t++;
}


int main()
{
	int n;
	din(n);
	vector<string> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];

	graph = vector< vi >(30);

	vi indeg(30,0);
	vi outdeg(30,0);

	int test = 1;
	for(int i=0;i<n-1;i++)
	{
		test = 1;
		for(int j=0;j<SZ(A[i]);j++)
			if(j<SZ(A[i+1]))
			{
				if(A[i][j]!=A[i+1][j])
				{
					graph[A[i][j]-'a'].PB(A[i+1][j]-'a');
					indeg[A[i+1][j]-'a']++;
					outdeg[A[i][j]-'a']++;
					test = 0;
					break;
				}
			}
		if(test && SZ(A[i+1])<SZ(A[i]))
		{
			printf("Impossible\n");
			return 0 ;
		}
	}

	/*for(int i=0;i<26;i++)
	  {
	  cout<<char(i+'a')<< " : ";
	  for(int j=0;j<SZ(graph[i]);j++)
	  cout<<char(graph[i][j]+'a')<< "  ";
	  cout<<endl;
	  }
	*/

	SET(arr,0);
	SET(dep,0);
	SET(visited,0);

	for(int i=0;i<26;i++)
		if(!visited[i])
			dfs(i);

	//trace4(arr['o'-'a'],dep['o'-'a'],arr['s'-'a'],dep['s'-'a']);

	int cycle=0;
	for(int u = 0;u<26;u++)
	{
		for(int i = 0;i<SZ(graph[u]);i++){
			int v = graph[u][i];
			if(arr[u]>arr[v] && dep[u]<dep[v])
			{
				cycle=1;
				break;
			}
		}
		if(cycle)
			break;
	}


	if(cycle)
	{
		printf("Impossible\n");
		return 0;
	}

	queue<int> Q;
	for(int i=0;i<26;i++)
		if(indeg[i]==0)
			Q.push(i);
	while(!Q.empty())
	{
		int head = Q.front();
		Q.pop();
		for(int i=0;i<SZ(graph[head]);i++)
		{
			int w = graph[head][i];
			indeg[w]--;
			if(indeg[w]==0)
				Q.push(w);
		}
		seq.PB(head+'a');
	}

	cout<<seq<<endl;


	return 0;
}