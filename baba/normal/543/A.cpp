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

int DP[2][501][501];	//Using space optimization technique because of MLE
//DP[i][j][k] = No of ways in which till i'th person, a total of j lines have been written with a total of k bugs
//The above state would form a O(n^4) DP coz DP[i]][j][k] = Sum(DP[i-1][j-r][k-A[i]*r]) for r=0 to j
//Instead we can see that DP[i][j][k] = DP[i-1][j][k] (if the i'th person doesn't write anything) 
//							+ DP[i][j-1][k-A[i]] (if the i'th person writes at-least one line)

int A[501];
int main()
{
	int n,m,b,mod;
	scanf("%d %d %d %d",&n,&m,&b,&mod);
	for(int i=0;i<n;i++)
		si(A[i]);
	for(int i=0;i<=m;i++)
		if(i*A[0]<=b)
			DP[0][i][i*A[0]] = 1;
	int prev=0,curr=1;
	for(int i=1;i<n;i++)
	{
		DP[curr][0][0]=1;
		for(int j=1;j<=m;j++)
			for(int k=0;k<=b;k++)
			{
				DP[curr][j][k] = DP[prev][j][k];
				if(k-A[i]<0) continue;
				DP[curr][j][k] =  (DP[curr][j][k] + DP[curr][j-1][k-A[i]])%mod;
				//trace4(i+1,j,k,DP[curr][j][k]);
			}
		if(i!=n-1)
			swap(curr,prev);
	}
	if(n==1)swap(prev,curr);
	int ans = 0;
	for(int i=0;i<=b;i++)
		ans = (ans + DP[curr][m][i])%mod;
	dout(ans);
	return 0;
}