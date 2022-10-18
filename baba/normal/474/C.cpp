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
class point{
	public:
	int x,y;
	point(int _x,int _y):x(_x),y(_y){}
	point(){x=0;y=0;}
};
bool cmp(point a,point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
double dist(point a,point b)
{
	return hypot(b.x-a.x , b.y-a.y);
}
const double EPS = double(1e-9);
bool ok(vector<point> A)
{
	sort(A.begin(),A.end(),cmp);
	double d[6];
	d[0] = dist(A[0],A[1]);
	d[1] = dist(A[1],A[2]);
	d[2] = dist(A[2],A[3]);
	d[3] = dist(A[3],A[0]);
	d[4] = dist(A[0],A[2]);
	d[5] = dist(A[1],A[3]);
	bool ret = true;
	sort(d,d+6);
	for(int i=1;i<4;i++)
		if(fabs(d[i]-d[0])>EPS)
			ret = false;
	if(fabs(d[4]-d[5])>EPS)
		ret = false;
	if(fabs(d[4]-d[3])<EPS)
		ret = false;
	return ret;
}
point rotate(point x,point a)
{
	point ret;
	ret.x = x.x - a.x;
	ret.y = x.y - a.y;
	swap(ret.x,ret.y);
	ret.x = -ret.x;
	ret.x += a.x;
	ret.y += a.y;
	return ret;
}
int solve(point x[4],point a[4])
{
	point n[4][4];
	for(int i=0;i<4;i++)
		n[i][0] = x[i];
	for(int i=1;i<4;i++)
		for(int j=0;j<4;j++)
			n[j][i] = rotate(n[j][i-1],a[j]);
	int ret = 123456;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				for(int l=0;l<4;l++)
				{
					vector<point> A;
					A = {n[0][i],n[1][j],n[2][k],n[3][l]};
					if(ok(A))
						ret = min(ret,i+j+k+l);
				}
	if(ret==123456)
		ret = -1;
	return ret;
}
int main()
{
	int n;
	si(n);
	point x[4];
	point a[4];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
			scanf("%d %d %d %d",&x[j].x,&x[j].y,&a[j].x,&a[j].y);
		dout(solve(x,a));
	}

	return 0;
}