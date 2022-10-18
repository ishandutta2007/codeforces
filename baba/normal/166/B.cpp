//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;
typedef vector< vi > 	vvi;
#define lli long long int
#define ulli unsigned long long int

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
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; din(t); while(t--)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define INF 1000000000  //1 billion (10^9) 

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
#define EPS 1e-9


class point{
	public:
		int x,y;
		point(){x=0;y=0;}
		point(int _x,int _y) : x(_x),y(_y){}
	 	point(const point &a){x=a.x;y=a.y;}

		bool operator < (point other) const
		{
			if(x!=other.x)
				return x<other.x;
			else
				return y<other.y;
		}

		
		~point(){}
};


class vect{
	public:
		int x,y;
		vect(int _x,int _y) : x(_x),y(_y) {}
		vect(point a,point b) : x(b.x-a.x),y(b.y-a.y) {}
};


lli cross(vect a,vect b)
{
	return (lli)a.x*b.y - (lli)a.y*b.x;
}

//returns true if point r is on right side of p-q
bool ccw(point p,point q,point r)
{
	
	//trace1(cross(vect(p,q),vect(p,r)));
	return cross(vect(p,q),vect(p,r))<0;
}


bool cmpDown(point a,point b)
{
	return a.x<b.x;
}


int main()
{
	int n;
	din(n);
	vector< point > A(n),temp(n);
	map<point,int> index;
	int mnx=0,mxx=0;
	int smnx=-1,smxx=-1;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		A[i].x=x;
		A[i].y=y;
		temp[i]=A[i];
		index[A[i]]=i;
	}

	sort(ALL(temp));

	mnx = index[temp[0]];
	if(temp[0].x==temp[1].x)
		smnx = index[temp[1]];
	else
		smnx = mnx;

	mxx = index[temp[n-1]];
	if(temp[n-1].x==temp[n-2].x)
		smxx = index[temp[n-2]];
	else
		smxx = mxx;
 
	//trace4(mnx,mxx,smnx,smxx);

	//dividing polygon A into two halves.. Lower and Upper.
	//Upper will go from secondMin to MAX
	//Lower will go from secondMAx to MIN
	
	vector<point> lowA,highA;

	for(int i=smnx;i!=mxx;i = (i+1)%n)
		highA.PB(A[i]);
	highA.PB(A[mxx]);
	
	for(int i=smxx;i!=mnx;i = (i+1)%n)
		lowA.PB(A[i]);
	lowA.PB(A[mnx]);

	sort(ALL(lowA));
	sort(ALL(highA));
	//DIVIDED
	

	/*
	cerr<<"LOWER HALF : \n";
	for(int i=0;i<SZ(lowA);i++)
		trace2(lowA[i].x,lowA[i].y);
	
	cerr<<"UPPER HALF : \n";
	for(int i=0;i<SZ(highA);i++)
		trace2(highA[i].x,highA[i].y);
	*/

	int m;
	din(m);
	vector< point >B(m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		B[i].x=x;
		B[i].y=y;
	}


	for(int i=0;i<m;i++)
	{
		vector<point>::iterator up,down;
		up = lower_bound(ALL(highA),B[i]);
		down = lower_bound(ALL(lowA),B[i]);

		//trace2(B[i].x,B[i].y);

		if(up==highA.end() || down == lowA.end())
		{
			printf("NO\n");
			return 0;
		}
		//trace4(B[i].x,B[i].y,up->x,up->y);
		//trace4(B[i].x,B[i].y,down->x,down->y);

		int low = index[*down];
		int high = index[*up];
	
		//trace2(low,high);

		if(!(ccw(A[low],A[(low+1)%n],B[i]) && ccw(A[(high == 0 ? n-1 : high-1)],A[high],B[i]) && ccw(A[high],A[(high+1)%n],B[i]) && ccw(A[ (low == 0 ? n-1 : low-1)],A[low],B[i])))
		{
			printf("NO\n");
			return 0;
		}
	}


	printf("YES\n");
	

	return 0;
}