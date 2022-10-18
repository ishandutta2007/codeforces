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
const int N = int(2e5)+10;
const LL LINF = LL(2e18);
VI graph[N];
int A[N];
int visited[2][N];
LL ans[2][N];
int iscycle[2][N];
int arr[2][N];
const int nil = 0;
stack<int> S;
int T;
bool ok[2][N];

void dfs(int u,int state)
{
	//trace2(u,state);
	if(u == nil)return;
	S.push(u);
	arr[state][u]=T++;
	visited[state][u]=1;
	int v = graph[u][state];
	int st = state;
	if(v==nil)
		ok[st][u]=1;
	if(v == 1)
	{
		while(!S.empty())
		{
			int w = S.top();
			S.pop();
			iscycle[st][w] = true;
			st = (st+1)%2;
		}
		return;
	}
	//trace3(u,v,state);
	if(!visited[(state+1)%2][v])
		dfs(v,(state+1)%2);
	else if(arr[(state+1)%2][v] < arr[state][u] && !ok[(state+1)%2][v])
	{
		while(!S.empty() && !(S.top()==v && st == (state+1)%2))
		{
	//		trace1(S.top());
			iscycle[st][S.top()] = true;
			st = (st+1)%2;
			S.pop();
		}
		if(!S.empty())
		{
			iscycle[st][v] = true;
			S.pop();
		}
	}
	if(!S.empty() && S.top()==u && st == state)
	{
		ok[st][u]=true;
		S.pop();
	}
}

void dfs1(int u,int state)
{
	if(u == nil)
		return;
	if(iscycle[state][u])
	{
		ans[state][u] = -LINF;
		return;
	}
	visited[state][u]=1;
	int w = graph[u][state];
	int nxtst = (state+1)%2;
	if(!visited[nxtst][w])
		dfs1(w,nxtst);
	//trace6(u,w,state,nxtst,ans[nxtst][w],A[u]);
	ans[state][u] = ans[nxtst][w] + A[u];
}

int main()
{
	int n;si(n);
	for(int i=2;i<=n;i++)
		si(A[i]);
	for(int i=2;i<=n;i++)
	{
		if(i + A[i] <= n)
			graph[i].PB(i+A[i]);
		else 
			graph[i].PB(nil);
		if(i - A[i] > 0 )
			graph[i].PB(i - A[i]);
		else
			graph[i].PB(nil);
	}
	for(int i=2;i<=n;i++)
	{
		if(!visited[0][i])
			dfs(i,0);
		if(!visited[1][i])
			dfs(i,1);
	}
	SET(visited,0);
	for(int i=2;i<=n;i++)
	{
		if(!visited[0][i])
			dfs1(i,0);
		if(!visited[1][i])
			dfs1(i,1);
	}
	for(int i=2;i<=n;i++)
		for(int j=0;j<2;j++)
			if(ans[j][i]<0)
				ans[j][i]=-1;
	//for(int i=2;i<=n;i++)
	//	trace3(i,ans[0][i],ans[1][i]);
	for(int i=1;i<n;i++)
		if(ans[1][1+i]==-1)
			dout(-1);
		else
			lldout(i + ans[1][1+i]);

	return 0;
}