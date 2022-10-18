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
double dp[105][105][105];
double den(int r,int s,int p)
{
	int ret = r*s + s*p + p*r;
	if(ret == 0)
		ret = 1 ;
	return ret;
}
int main()
{
	int r,s,p;
	si(r);si(s);si(p);
	for(int i=0;i<105;i++)
		for(int j=0;j<105;j++)
			for(int k=0;k<105;k++)
				dp[i][j][k] = 0.0;
	dp[r][s][p] = 1.0;
	for(int i=r;i>=0;i--)
		for(int j=s;j>=0;j--)
			for(int k=p;k>=0;k--)
			{
				if(i!=r)
					dp[i][j][k] += dp[i+1][j][k]*((i+1)*k)/den(i+1,j,k);
				if(j!=s)
					dp[i][j][k] += dp[i][j+1][k]*((j+1)*i)/den(i,j+1,k);
				if(k!=p)
					dp[i][j][k] += dp[i][j][k+1]*((k+1)*j)/den(i,j,k+1);
				//trace4(i,j,k,dp[i][j][k]);
			}
	
	double ansr = 0.0;
	for(int i=r;i>0;i--)
		ansr+=dp[i][0][0];
	double anss = 0.0;
	for(int i=s;i>0;i--)
		anss+=dp[0][i][0];
	double ansp = 0.0;
	for(int i=p;i>0;i--)
		ansp+=dp[0][0][i];
	printf("%.9lf %.9lf %.9lf\n",ansr,anss,ansp);

	return 0;
}