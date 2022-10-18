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
const int N = int(1e6)+10;
int sqt=300;
LL A[N];
pair<II,II> Q[N];
LL fans[N];
LL freq[N];
bool cmp(pair<II,II> a,pair<II,II> b)
{
	int b1 = a.S.S;
	int b2 = b.S.S;
	if(b1==b2)
		return a.F.S<b.F.S;
	return b1<b2;
}
int main()
{
	int n,q;
	si(n);si(q);
	for(int i=1;i<=n;i++)
		sll(A[i]);
	sqt = sqrt(2*n);
	for(int i=0;i<q;i++)
	{
		si(Q[i].F.F);si(Q[i].F.S);
		Q[i].S.F=i;Q[i].S.S=Q[i].F.F/sqt;
	}
	sort(Q,Q+q,cmp);
	int L = 1,R=1;
	LL ans=A[1];
	freq[A[1]]++;
	LL sub,add;
	int pre=-1;
	for(int i=0;i<q;i++)
	{
		int l=Q[i].F.F;
		int r=Q[i].F.S;
		int pos=Q[i].S.F;
		if(Q[i].S.S!=pre)
		{
			L = R = Q[i].F.F;
			ans = A[L];
			SET(freq,0);
			freq[A[L]]++;
			pre=Q[i].S.S;
		}
		while(L<l)
		{
			sub = freq[A[L]]*freq[A[L]]*A[L];
			freq[A[L]]--;
			add = freq[A[L]]*freq[A[L]]*A[L];
			ans+=add - sub;
			L++;
		}
		while(L>l)
		{
			L--;
			sub = freq[A[L]]*freq[A[L]]*A[L];
			freq[A[L]]++;
			add = freq[A[L]]*freq[A[L]]*A[L];
			ans+=add - sub;
		}
		while(R<r)
		{
			R++;
			sub = freq[A[R]]*freq[A[R]]*A[R];
			freq[A[R]]++;
			add = freq[A[R]]*freq[A[R]]*A[R];
			ans+=add - sub;
		}
		while(R>r)
		{
			sub = freq[A[R]]*freq[A[R]]*A[R];
			freq[A[R]]--;
			add = freq[A[R]]*freq[A[R]]*A[R];
			ans+=add - sub;
			R--;
		}
		fans[pos]=ans;
	}
	for(int i=0;i<q;i++)
		lldout(fans[i]);
	return 0;
}