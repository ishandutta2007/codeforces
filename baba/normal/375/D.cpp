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
const int N = int(1e5)+10;
VI g[N];
int tin[N],tout[N],T;
int A[N];
int sqt;int C[N];
int freq[N],K[N];
int ans[N];
pair<II,II> Q[N];
void dfs(int u,int p)
{
	++T;
	tin[u]=T;
	A[T]=C[u];
	for(int i=0;i<SZ(g[u]);i++)
		if(g[u][i]!=p)
			dfs(g[u][i],u);
	tout[u]=T;
}
bool cmp(pair<II,II> a,pair<II,II> b)
{
	if(a.F.F/sqt != b.F.F/sqt)
		return a.F.F/sqt < b.F.F/sqt;
	return a.F.S<b.F.S;
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=1;i<=n;i++)
		si(C[i]);
	for(int i=0;i<n-1;i++)
	{
		int u,v;si(u);si(v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,1);
	for(int i=0;i<m;i++)
	{
		int v,k;si(v);si(k);
		Q[i].F.F = tin[v];
		Q[i].F.S = tout[v];
		Q[i].S.F = k;
		Q[i].S.S = i;
	}
	sqt = sqrt(2*n);
	sort(Q,Q+m,cmp);
	int L = 1,R = 1;
	freq[A[1]]++;
	K[freq[A[1]]]++;
	for(int i=0;i<m;i++)
	{
		int l = Q[i].F.F;
		int r = Q[i].F.S;
		int k = Q[i].S.F;
		int pos = Q[i].S.S;
		while(L<l)
		{
			K[freq[A[L]]]--;
			freq[A[L]]--;
			L++;
		}
		while(L>l)
		{
			L--;
			freq[A[L]]++;
			K[freq[A[L]]]++;
		}
		while(R<r)
		{
			R++;
			freq[A[R]]++;
			K[freq[A[R]]]++;
		}
		while(R>r)
		{
			K[freq[A[R]]]--;
			freq[A[R]]--;
			R--;
		}
		ans[pos]=K[k];
	}
	for(int i=0;i<m;i++)
		dout(ans[i]);
	return 0;
}