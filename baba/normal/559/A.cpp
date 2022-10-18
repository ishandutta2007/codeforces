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

const double EPS = 1e-9;
const double PI = 3.141592653589793238460;
double dtr(double theta)
{
	return ((theta*PI)/180.0);
}
//***************** Point ******************
class point{
	public:
		double x,y;
		point(){x=0;y=0;}
		point(double _x,double _y) : x(_x),y(_y){}
		bool operator < (point other) const
		{
			if(fabs(x - other.x)>EPS)
				return x<other.x;
			return y<other.y;
		}
		bool operator == (point other) const
		{
			return ((fabs(x - other.x)<EPS )&& (fabs(y - other.y)<EPS));
		}
};
point A[7];
double area(int n) {
	double a=0, b=0;
	for(int i=0; i<n-1; ++i) {
		a += A[i].x * A[i+1].y;
		b += A[i].y * A[i+1].x;
	}
	return fabs(a - b)/2;
}
int main()
{
	double a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	A[0].x = 0;
	A[0].y = 0;
	A[1].x = 0;
	A[1].y = a1;
	A[2].x = A[1].x + a2*cos(dtr(30.0));
	A[2].y = A[1].y + a2*sin(dtr(30.0));
	A[3].x = A[2].x + a3*cos(dtr(30.0));
	A[3].y = A[2].y - a3*sin(dtr(30.0));
	A[4].x = A[3].x;
	A[4].y = A[3].y - a4;
	A[5].x = A[4].x - a5*cos(dtr(30.0));
	A[5].y = A[4].y - a5*sin(dtr(30.0));
	A[6].x = A[5].x - a6*cos(dtr(30.0));
	A[6].y = A[5].y + a6*sin(dtr(30.0));
	double parea = area(7);
	double tarea = sqrt(3)/4.0;
	int n = int(parea/tarea + 0.5);
	cout<<n<<endl;
	return 0;
}