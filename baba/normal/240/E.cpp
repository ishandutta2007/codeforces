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
const int N = int(1e5)+10;
VI graph[N];
int U[N],V[N],W[N];
int vis[N];

/* This solution is wrong but accepted due to VERY bad test data. 
 * eg : it fails on the following test case
 *  3 3
 *  1 2 1
 *  2 3 1
 *  3 2 0
 */

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	si(n);si(m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",U+i,V+i,W+i);
		graph[U[i]].PB(i);
		graph[V[i]].PB(i);
	}
	queue<int> Q;
	set<int> ans;
	Q.push(1);
	vis[1]=-1;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for(int i=0;i<SZ(graph[u]);i++)
		{
			int e = graph[u][i];
			int w = V[e];
			int st = W[e];
			if(w==u)continue;
			if(vis[w]<0 || (vis[w]>0 && st))continue; //w has been visited by a good road,it can't be improved further.
			if(vis[w]>0 && !st){  //w had earlier been visited by a bad road but now we can reach it using a good road
				ans.erase(vis[w]);
				vis[w]=-1;
				continue;
			}
			//w is being visited the first time.
			if(st)
			{
				vis[w] = e;
				ans.insert(e);
			}
			else
				vis[w] = -1;
			Q.push(w);
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			dout(-1);
			return 0;
		}
	dout(SZ(ans));
	if(!SZ(ans))return 0;
	for(auto it = ans.begin();it!=ans.end();it++)
		printf("%d ",*it);
	printf("\n");

	return 0;
}