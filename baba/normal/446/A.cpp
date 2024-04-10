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

//#define TRACE

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
	int n,i;
	din(n);
	vi arr(n),dp(n),end(n);
	din(arr[0]);
	end[0]=1;
	for(i=1;i<n;i++)
	{	
		din(arr[i]);
		if(arr[i]>arr[i-1])
			end[i]=end[i-1]+1;
		else
			end[i] = 1;
	}
	
	dp[n-1]=1;
	for(i=n-2;i>=0;i--){
		if(arr[i]<arr[i+1])
			dp[i]=dp[i+1]+1;
		else
			dp[i]=1;
	}
	/*
	for(i=0;i<n;i++)
		printf("%d ",dp[i]);
	printf("\n");
*/
	int maxlen=0;
	for(i=0;i<n;i++){
		if(i==0)
		{
			if(arr[i]<arr[i+1])
				maxlen = max(maxlen,dp[0]);
			else
				maxlen = max(maxlen,1 + dp[1]);
		}
		else if(i==n-1)
		{
			if(arr[i-1]<arr[i])
				maxlen = max(maxlen,end[i]);
			else
				maxlen = max(maxlen,end[i-1]+1);
		}
		else
		{
			if(arr[i-1]+1<arr[i+1])
				maxlen = max(maxlen,end[i-1]+1+dp[i+1]);
			else
				maxlen = max(max(maxlen,end[i-1]+1),1+dp[i+1]);
		}
		/*if(dp[i]==1)
		{
			if(i==n-1)
				maxlen = max(maxlen,end[i-1]+1);
			else if(arr[i]<arr[i+2] && arr[i]!=arr[i+2]-1)
				maxlen = max(maxlen,end[i]+dp[i+1]);
			else
				maxlen = max(maxlen,end[i]+1);
		}
		else
			maxlen = max(maxlen,dp[i]);
		*/
	
		trace3(maxlen,dp[i],arr[i]);
	}
	dout(maxlen);




	return 0;
}