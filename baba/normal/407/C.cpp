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
const int K = 105;
const int MOD = int(1e9)+7;
LL dp[K][N];
LL C[N][K];
int main()
{
	C[0][0]=1;
	for(int i=1;i<N;i++)
	{
		C[i][0]=1;
		for(int j=1;j<min(K,i+1);j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
	}
	int n,m;
	si(n);si(m);
	for(int i=1;i<=n;i++)
		sll(dp[0][i]);
	while(m--)
	{
		int l,r,k;
		si(l);si(r);si(k);
		dp[k+1][l]=(dp[k+1][l] + 1)%MOD;
		for(int i = 1;i<=k+1;i++)
			dp[i][r+1] = (dp[i][r+1] - C[k+1-i+r-l][k+1-i]+MOD)%MOD;
	}
	for(int i=K-2;i>=0;i--)
	{
		LL temp=0;
		for(int j=1;j<=n;j++)
		{
			temp += dp[i+1][j];
			temp %= MOD;
			dp[i][j]+=temp;
			dp[i][j]%=MOD;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",dp[0][i]);
	printf("\n");
	return 0;
}