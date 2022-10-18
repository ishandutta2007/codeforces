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

#define DRT() int t; din(t); while(t--)

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

const int MOD = int(1e9) + 7;


vector<LL> mult(vector<LL>& F,vector< vector<LL> >& T)
{
	vector< LL > ret(101,0);
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			ret[i] = (ret[i] + F[j]*T[j][i])%MOD;

	return ret;
}



void mult2(vector< vector<LL> >&A,vector< vector<LL> >&B)
{
	vector< vector<LL> > ret(101,vector<LL>(101,0));
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			for(int k=0;k<101;k++)
				ret[i][j] = (ret[i][j] + A[i][k]*B[k][j])%MOD;
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			A[i][j]=ret[i][j];

}


vector< vector<LL> > pow(vector< vector<LL> >T,LL p)
{
	vector< vector<LL> > ret(101,vector<LL>(101,0));
	for(int i=0;i<101;i++)
		ret[i][i]=1;
	
	while(p)
	{
		if(p&1)
			mult2(ret,T);
		p>>=1;
		mult2(T,T);
	}
	return ret;
}





int main()
{
	int n,x;
	int cnt[101]={0};
	si(n);si(x);
	for(int i=0;i<n;i++)
	{
		int in;
		si(in);
		cnt[in]++;
	}
	LL dp[101];
	dp[0]=1;
	LL ans=dp[0];
	for(int i=1;i<=100;i++)
	{
		dp[i]=0;
		for(int j=1;i-j>=0;j++)
			dp[i] =(dp[i] + cnt[j]*dp[i-j])%MOD;
		dp[i]%=MOD;
		ans = (ans + dp[i])%MOD;
	}

	if(x<=100)
	{
		LL sum=0;
		for(int i=0;i<=x;i++)
			sum+=dp[i];
		sum%=MOD;
		lldout(sum);
		return 0;
	}

	//Build F0
	vector<LL> F(101);
	for(int i=0;i<100;i++)
		F[i]=dp[i+1];
	F[100]=ans;

	//Build Transformation Matrix
	vector< vector<LL> >T(101,vector<LL>(101,0));
	for(int i=1;i<=99;i++)
		T[i][i-1]=1;

	for(int i=0;i<=99;i++)
		T[i][99]=T[i][100]=cnt[100-i];
	T[100][100]=1;

	//Find that answer such that ans = (F*(T^x-100))[100]
	//We have already made sure that x>100 :)
	

	T = pow(T,x-100);
	lldout(mult(F,T)[100]);
		
	return 0;
}