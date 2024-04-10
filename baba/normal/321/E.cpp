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
const int N = int(4e3)+10;
const int K = 800+10;
const int INF = int(2e9);
int A[N];
int U[N][N];
int DP[K][N],Best[K][N];
int cost[N][N],sum[N][N];
/************ Using Divide and Conquer DP optimization. Based on the fact that Best[i] are monotonic *************/
int k;
void solve(int l,int r,int L,int R)
{
	if(l>r)return;
	int mid = (l+r)/2;
	int best;
	DP[k][mid]=INF;
	for(int i = min(R,mid-1);i>=L;i--)
		if(DP[k-1][i] + cost[i+1][mid] <= DP[k][mid])
		{
			DP[k][mid] = DP[k-1][i] + cost[i+1][mid];
			best = i;
		}
	solve(l,mid-1,L,best);
	solve(mid+1,r,best,R);
}
char buffer[10000];
int main()
{
	int n,kk;
	si(n);si(kk);
	FLUSHN;
	for(int i=1; i<=n; i++) 
	{
		gets(buffer);
		for(int j=1; j<=n; j++)
		{
			U[i][j] = buffer[2 * (j - 1)] - '0';
			sum[i][j] = sum[i][j-1]+U[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cost[i][j] = cost[i][j-1] + sum[j][j] - sum[j][i-1];
	for(int i=1;i<=n;i++)
		DP[1][i]=cost[1][i];
	for(k = 2;k<=kk;k++)
		solve(1,n,1,n);
	dout(DP[kk][n]);
	return 0;
}