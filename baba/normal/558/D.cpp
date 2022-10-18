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

int main()
{
	LL h,q;
	sll(h);sll(q);
	vector<pair<LL,LL>> A;
	LL one = 1;
	LL l = (one<<(h-1));
	LL r = (one<<h) - 1;
	while(q--)
	{
		int i,ans;
		LL L,R;
		scanf("%d %lld %lld %d\n",&i,&L,&R,&ans);
		for(int j=i;j<h;j++)
		{
			L = 2*L;
			R = 2*R + 1;
		}
		if(ans==1)
		{
			l = max(l,L);
			r = min(r,R);
		}
		else
			A.PB(MP(L,R));
	}
	A.PB(MP((one<<(h-1)),l-1));
	A.PB(MP(r+1,(one<<h)-1));
	sort(ALL(A));
	LL maxr = (one<<(h-1))-1;
	LL span=0;
	LL ans=0;
	for(int i=0;i<SZ(A);i++)
	{
		if(A[i].F > maxr + 1)
		{
			span += A[i].F - maxr - 1;
			ans = A[i].F - 1;
		}
		maxr = max(maxr,A[i].S);
	}
	if(span==0)printf("Game cheated!\n");
	else if(span > 1) printf("Data not sufficient!\n");
	else lldout(ans);
	return 0;
}