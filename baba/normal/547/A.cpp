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
int vis[N];
void validate(int x)
{
	if(x==-1)
	{
		dout(-1);
		exit(0);
	}
}
int main()
{
	LL m,h1,a1,h2,a2,x1,y1,x2,y2;
	cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
	//trace4(x1,y1,x2,y2);
	LL t1=-1,r1=0;//time to reach a1 and time to repeat
	LL s2,t2=-1,r2=0;//time to reach a2 from s2 and time to repeat (at a2)
	
	//find t1 and r1
	LL h = h1;
	for(int i=1;i<N;i++)
	{
		int next = ((LL)h*(LL)x1 + y1)%m;
	//	trace1(next);
		if(next == a1)
		{
			t1 = i;
			break;
		}
		h = next;
	}
	validate(t1);
	h = a1;
	for(int i=1;i<N;i++)
	{
		int next = ((LL)h*(LL)x1 + y1)%m;	
		if(next == a1)
		{
			r1 = i;
			break;
		}
		h = next;
	}
	//validate(r1);
	//find s2,t2,r2
	h = h2;
	for(int i=1;i<=t1;i++)
	{
		s2 = ((LL)h*(LL)x2 + y2)%m;
		//trace3(h,s2,i);
		h = s2;
	}
	if(s2==a2)
	{
		lldout(t1);
		return 0;
	}
	h = s2;
	for(int i=1;i<N;i++)
	{
		int next = ((LL)h*(LL)x2 + y2)%m;
		if(next == a2)
		{
			t2 = i;
			break;
		}
		h = next;
	}
	validate(t2);

	h = a2;
	for(int i=1;i<N;i++)
	{
		int next = ((LL)h*(LL)x2 + y2)%m;	
		if(next == a2)
		{
			r2 = i;
			break;
		}
		h = next;
	}
	//validate(r2);
	LL ans = -1;
	for(int i = 0;i<10*N;i++)
		if(r1!=0 && (t2 + i*r2)%r1 == 0)
		{
			ans = t2 + i*r2;
			break;
		}
	if(ans!=-1)
		ans+=t1;
	lldout(ans);
	return 0;
}