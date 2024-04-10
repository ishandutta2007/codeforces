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

int R,C,n;
II A[2010];
const int MOD = int(1e9)+7;
const int N = int(4e5)+10;
LL fact[N],invfact[N];
LL power(LL a, LL p, LL mod)
{
	LL ret = 1;
	while(p)
	{
		if(p&1)ret = (ret*a)%mod;
		a=(a*a)%mod;
		p/=2;
	}
	return ret;
}
LL add(LL l,LL r)
{
	l = (l + r)%MOD;
	return l;
}
LL sub(LL l,LL r)
{
	l = (l - r);
	if(l<0)l+=MOD;
	return l;
}
LL mult(LL l,LL r)
{
	l = (l*r)%MOD;
	return l;
}
LL nCr(int n,int r)
{
	return (((fact[n]*invfact[r])%MOD)*invfact[n-r])%MOD;
}
LL numWays(II one,II two)
{
	int r1=one.F;
	int c1=one.S;
	int r2=two.F;
	int c2=two.S;
	if(r2<r1)return 0;
	if(c2<c1)return 0;
	int u = r2-r1;
	int r = c2-c1;
	return nCr(u+r,min(u,r));
}
void preprocess()
{
	fact[0]=1;
	for(int i=1;i<N;i++)
		fact[i] = (fact[i-1]*i)%MOD;
	invfact[0]=1;
	for(int i=1;i<N;i++)
		invfact[i] = power(fact[i],MOD-2,MOD);
}
LL dist[2010];
int main()
{
	preprocess();
	si(R);si(C);si(n);
	A[0].F=A[0].S=1;
	for(int i=1;i<=n;i++)
	{
		si(A[i].F);
		si(A[i].S);
	}
	A[n+1].F = R;
	A[n+1].S = C;
	n+=2;
	sort(A,A+n);
	II start=A[0],end=A[n-1];
	LL total = numWays(start,end);
	LL minus=0;
	for(int i=1;i<n-1;i++)
	{
		II p =A[i];
		LL num = numWays(start,p);
		for(int j=i-1;j>0;j--)
			num = sub(num,mult(dist[j],numWays(A[j],p)));
		dist[i] = num;
		minus = add(minus,mult(num,numWays(p,end)));
	}
	total=sub(total,minus);
	lldout(total);
	return 0;
}