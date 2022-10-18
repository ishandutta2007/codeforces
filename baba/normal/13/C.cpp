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
int s[5001];
LL val[5001];
LL dp[2][5001];
LL dp2[2][5001];
map<int,int> m;
const LL LINF = LL(2e18);
int main()
{
	int n;si(n);
	set<int> S;
	for(int i=0;i<n;i++)
	{
		si(s[i]);
		S.insert(s[i]);
	}
	int len=0;
	while(!S.empty())
	{
		val[len] = *S.begin();
		m[*S.begin()] = len;
		len++;
		S.erase(S.begin());
	}
	for(int i=0;i<n;i++)
		s[i] = m[s[i]];
	int curr=0,next=1;
	for(int i=0;i<len;i++)
	{
		dp[curr][i] = abs(val[i] - val[s[0]]);
		dp2[curr][i] = (i==0?dp[curr][i]:min(dp[curr][i],dp2[curr][i-1]));
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<len;j++)
			dp[next][j] = dp2[curr][j] + abs(val[j] - val[s[i]]);
		for(int j=0;j<len;j++)
			dp2[next][j] = (j==0?dp[next][j] : min(dp[next][j],dp2[next][j-1]));
		swap(curr,next);
	}
	LL ans = LINF;
	for(int i=0;i<len;i++)
		ans = min(ans,dp[curr][i]);
	lldout(ans);
	return 0;
}