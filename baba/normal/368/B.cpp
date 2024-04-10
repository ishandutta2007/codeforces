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

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vi arr(n);
	int i;
	for(i=0;i<n;i++)
		din(arr[i]);
	vi dp(n);
	vi freq(100001,0);
	dp[n-1]=1;
	freq[arr[n-1]]++;

	for(i=n-2;i>=0;i--)
	{
		dp[i]=dp[i+1] + (freq[arr[i]]?0:1);
		freq[arr[i]]++;
	}
	int in;
	for(i=0;i<m;i++)
	{
		din(in);
		dout(dp[in-1]);
	}

	return 0;
}