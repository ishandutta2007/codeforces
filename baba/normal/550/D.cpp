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

const int N = int(1e6)+10;
set<int> graph[N];
set<II> e;
int U[N],V[N];
int len;
int start;
void build(int k)
{
	for(int i=start;i<=k+start;i++)
		for(int j=i+1;j<=k+start;j++)
		{
			graph[i].insert(j);
			graph[j].insert(i);
		}
	int next = start+k+1;
//	trace1(next);
	graph[start].erase(start+1);
	graph[start+1].erase(start);
	graph[start+1].insert(next);
	graph[next].insert(start+1);
	for(int i=start+2;i+1<=k+start;i+=2)
	{
		graph[i].erase(i+1);
		graph[i+1].erase(i);
		graph[i].insert(next);
		graph[i+1].insert(next);
		graph[next].insert(i);
		graph[next].insert(i+1);
	}
	for(int i=start;i<=next;i++)
		for(auto j=graph[i].begin();j!=graph[i].end();j++)
			if(!e.count(MP(*j,i)))
				e.insert(MP(i,*j));
	start = next+1;
}
int main()
{
	int k;si(k);
	if(k%2==0)
	{
		printf("NO\n");
		return 0;
	}
	if(k==1)
	{
		printf("YES\n2 1\n1 2\n");
		return 0;
	}
	start = 1;
	build(k);
	e.insert(MP(1,start));
	build(k);
	printf("YES\n");
	printf("%d %d\n",start-1,SZ(e));
	for(auto it = e.begin();it!=e.end();it++)
		printf("%d %d\n",it->F,it->S);
	return 0;
}