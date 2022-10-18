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

const double EPS = 1e-9;


class point{
	public:
		int x,y;
		point(int _x=0,int _y=0):x(_x),y(_y){}
};


class line{
	public:
		double a,b,c;
		line(){a=b=c=0;}
		line(point p1,point p2)
		{
			if(fabs(p1.x-p2.x)<EPS)
			{
				a = 1.0;
				b = 0.0;
				c = -p1.x;
			}
			else
			{
				a = -(double)(p1.y-p2.y)/(p1.x-p2.x);
				b = 1.0;
				c = -(double)(a*p1.x) - p1.y;
			}
		}
};


bool areParallel(line l1,line l2)
{
	return (fabs(l1.a-l2.a)<EPS) && (fabs(l1.b-l2.b)<EPS);
}


bool areSame(line l1,line l2)
{
	return areParallel(l1,l2) && (fabs(l1.c-l2.c)<EPS);
}


int main()
{
	int n;
	si(n);
	point p0;
	si(p0.x);si(p0.y);
	vector<line> A(n);
	for(int i=0;i<n;i++)
	{
		point in;
		si(in.x);si(in.y);
		A[i] = line(p0,in);
	}

	VI visited(n,0);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			for(int j=i+1;j<n;j++)
				if(areSame(A[i],A[j]))
					visited[j]=1;
			visited[i]=1;
			ans++;
		}
	}

	dout(ans);



	return 0;
}