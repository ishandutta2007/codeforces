#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-7;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=2000+5;

double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}
template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2){return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);}
int compare(double a,double b){return(fabs(a-b)<=eps)?0:((a<b)?-1:1);}

struct Point
{
	double x,y;
	Point(double _x=0,double _y=0)
	{
		x=_x;
		y=_y;
	}
	int compareTo(const Point &other) const
	{
		int c=compare(x,other.x);
		if (c!=0) return c;
		return compare(y,other.y);
	}
};
struct Line
{
	double a,b,c;
	Line(double _a=0,double _b=0,double _c=0)
	{
		a=_a;
		b=_b;
		c=_c;
		double d=sqrt(sqr(a)+sqr(b));
		a/=d;
		b/=d;
		c/=d;
		if (a<-eps || a<=eps && b<0) a=-a,b=-b,c=-c;
	}
	int compareTo(const Line &other) const
	{
		int c1=compare(a,other.a);
		if (c1!=0) return c1;
		int c2=compare(b,other.b);
		if (c2!=0) return c2;
		return compare(c,other.c);
	}
};

int n;
double h,f;
double L[maxn],R[maxn];
pair<double,double> S1[maxn],S2[maxn];
Line L1[maxn],L2[maxn];

Line getLineByTwoPoints(const Point &p1,const Point &p2)
{
	double a=+(p1.y-p2.y);
	double b=-(p1.x-p2.x);
	double c=p1.x*p2.y-p2.x*p1.y;
	return Line(a,b,c);
}
double ppDistance(const Point &a,const Point &b)
{
	return dist(a.x,a.y,b.x,b.y);
}
double plDistance(const Point &p,const Line &l)
{
	return fabs(l.a*p.x+l.b*p.y+l.c)/sqrt(sqr(l.a)+sqr(l.b));
}
double cross(const Point &a,const Point &b,const Point &c)
{
	return cross(a.x,a.y,b.x,b.y,c.x,c.y);
}
int crossop(const Point &a,const Point &b,const Point &c)
{
	return compare(cross(a,b,c),0);
}
bool isMiddle(double a,double m,double b)
{
	return fabs(a-m)<=eps || fabs(b-m)<=eps || (a<m)!=(b<m);
}
bool isMiddle(const Point &a,const Point &m,const Point &b)
{
	return crossop(a,m,b)==0 && isMiddle(a.x,m.x,b.x) && isMiddle(a.y,m.y,b.y);
}
bool isTouchIntersect(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return isMiddle(a,c,d) || isMiddle(a,d,b) || isMiddle(c,a,d) || isMiddle(c,b,d);
}
bool isCrossIntersect(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return (crossop(a,b,c)*crossop(a,b,d)<0 && crossop(c,d,a)*crossop(c,d,b)<0);
}
bool isIntersect(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return isCrossIntersect(a,b,c,d) || isTouchIntersect(a,b,c,d);
}
double psDistance(const Point &p,const Point &a,const Point &b)
{
	double sab=sqr(a.x-b.x)+sqr(a.y-b.y);
	double spa=sqr(p.x-a.x)+sqr(p.y-a.y);
	double spb=sqr(p.x-b.x)+sqr(p.y-b.y);
	if (fabs(spa-spb)<=sab)
		return fabs(cross(p,a,b))/sqrt(sab);
	else
		return sqrt(min(spa,spb));
}
int getIntersect(const Line &A,const Line &B,Point &P)
{
	double a1=A.a;
	double b1=A.b;
	double c1=A.c;
	double a2=B.a;
	double b2=B.b;
	double c2=B.c;
	double t=a1*b2-a2*b1;
	if (fabs(t)<=eps) return 0;
	double X0=+(b1*c2-b2*c1)/t;
	double Y0=-(a1*c2-a2*c1)/t;
	P.x=X0;
	P.y=Y0;
	return 1;
}

double getArea(int n,Point P[])
{
	double R=0;
	for (int i=1;i<n;i++) R+=cross(P[0],P[i-1],P[i]);
	return fabs(R)/2.0;
}


int main()
{
#ifdef _MSC_VER
	if (0)
	{
		freopen("large.txt","w",stdout);
		printf("%d %d %d\n",500,10,11);
		for (int i=499;i>=0;i--)
			printf("%d %d\n",i+i,i+i+1);
		return 0;
	}
	//freopen("input.txt","r",stdin);
	freopen("large.txt","r",stdin);
#endif
	scanf("%d%lf%lf",&n,&h,&f);
	for (int i=0;i<n;i++) scanf("%lf%lf",&L[i],&R[i]);
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (L[j]<L[i])
			{
				swap(L[i],L[j]);
				swap(R[i],R[j]);
			}
	vector<double> g;
	g.push_back(0);
	g.push_back(h);
	for (int i=0;i<n+n;i++) 
	{
		L1[i]=getLineByTwoPoints(Point(0,f),Point((i&1)?R[i/2]:L[i/2],h));
		L2[i]=getLineByTwoPoints(Point(0,-f),Point((i&1)?R[i/2]:L[i/2],-h));
	}
	for (int i=0;i<n+n;i++) for (int j=0;j<n+n;j++)
	{
		Point p;
		if (getIntersect(L1[i],L2[j],p) && p.y>=0 && p.y<=h)
			g.push_back(p.y);
	}
	double result=0;
	sort(g.begin(),g.end());
	for (int d=0;d+1<SIZE(g);d++)
	{
		double y1=g[d];
		double y2=g[d+1];
		double key=(y1+y2)/2;
		if (y2-y1<=1e-13)
			continue;
		for (int i=0;i<n;i++)
		{
			S1[i].first=L[i]*(double)(key-f)/(double)(h-f);
			S1[i].second=R[i]*(double)(key-f)/(double)(h-f);
			S2[i].first=L[i]*(double)(key+f)/(double)(f-h);
			S2[i].second=R[i]*(double)(key+f)/(double)(f-h);
		}		
		double last=-1e100;
		double total=0;
		for (int i=0,j=0;i<n || j<n;)
			if (j>=n || i<n && S1[i].first<S2[j].first)
			{
				if (S1[i].second>last)
				{
					total+=S1[i].second-max(last,S1[i].first);
					last=S1[i].second;
				}
				i++;
			}
			else
			{
				if (S2[j].second>last)
				{
					total+=S2[j].second-max(last,S2[j].first);
					last=S2[j].second;
				}
				j++;
			}
		result+=total*(y2-y1);
	}
	printf("%.18lf\n",result*2);
	return 0;
}