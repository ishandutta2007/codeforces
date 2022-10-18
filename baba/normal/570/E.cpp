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
const int N = 505;
string s[N];
int n,m;
LL dp[2][N][N];
int len;
const int MOD = int(1e9)+7;
int dist(int r1,int c1,int r2,int c2)
{
	return abs(r1-r2) + abs(c1-c2);
}
bool isvalid(int r1,int c1,int r2,int c2)
{
	bool ret=true;
	ret = ret & (r1>=0 && r1<n);
	ret = ret & (r2>=0 && r2<n);
	ret = ret & (c1>=0 && c1<m);
	ret = ret & (c2>=0 && c2<m);
	ret = ret & (r1<=r2 && c1<=c2);
	return ret;
}
int oup(int x)
{
	return len-x;
}
int odn(int x)
{
	return n+m-2-len-x;
}
int main()
{
	si(n);si(m);
	for(int i=0;i<n;i++)
		cin>>s[i];
	len = dist(0,0,n-1,m-1);
	len = len/2;
	int curr=0,nxt=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(isvalid(i,oup(i),j,odn(j)) && s[i][oup(i)] == s[j][odn(j)])
				dp[curr][i][j] = 1;
	for(len = len-1;len>=0;len--)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(isvalid(i,oup(i),j,odn(j)) && s[i][oup(i)] == s[j][odn(j)])
					dp[nxt][i][j] = (dp[curr][i][j]+dp[curr][i+1][j]+dp[curr][i][j-1]+dp[curr][i+1][j-1])%MOD;
				else
					dp[nxt][i][j] = 0;
		swap(nxt,curr);
	}
	lldout(dp[curr][0][n-1]);
	return 0;
}