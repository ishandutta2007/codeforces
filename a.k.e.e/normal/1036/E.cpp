#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ldb;
#define double ldb
const int MAXN=1005;
const double eps=1e-8;

int n;
int gcd(int a,int b)
	{return b?gcd(b,a%b):a;}
ll ans=0;
inline int dcmp(double x)
{
	if(x>eps)return 1;
	return x<-eps?-1:0;
}
struct Point
{
	double x,y;
	inline bool isinc()const
		{return !dcmp(x-floor(x+eps)) && !dcmp(y-floor(y+eps));}
	Point(){}
	Point(double x,double y):x(x),y(y){}
	inline bool operator <(const Point b)const
	{
		int t=dcmp(x-b.x);
		if(t)return t<0;
		return dcmp(y-b.y)<0;
	}
};
struct Segment
{
	Point s,t;
	Segment(){}
	Segment(Point xs,Point xt)
	{
		if(dcmp(xs.x-xt.x)>0)swap(xs,xt);
		else if(!dcmp(xs.x-xt.x) && dcmp(xs.y-xt.y)>0)swap(xs,xt);
		s=xs;t=xt;
	}
	inline double k()const
		{return (t.y-s.y)/(t.x-s.x);}
	inline double b()const
		{return s.y-k()*s.x;}
	inline bool infk()const
		{return !dcmp(s.x-t.x);}
	inline double gety(double x)const
		{return k()*x+b();}
	inline bool have(Point a)const
	{
		if(dcmp(a.x-s.x)<0 || dcmp(a.x-t.x)>0)return 0;
		if(infk())return !dcmp(s.x-a.x) && dcmp(a.y-s.y)>=0 && dcmp(a.y-t.y)<=0;
		return !dcmp(gety(a.x)-a.y);
	}
}a[MAXN];

Point intersec(Segment a,Segment b,bool &flag)
{
	flag=1;
	if((a.infk() && b.infk()) || !dcmp(a.k()-b.k())){flag=0;return Point(0,0);}
	Point p;
	if(a.infk())p=Point(a.s.x,b.gety(a.s.x));
	else if(b.infk())p=Point(b.s.x,a.gety(b.s.x));
	else
	{
		double x=(b.b()-a.b())/(a.k()-b.k());
		p=Point(x,a.gety(x));
	}
	if(!a.have(p) || !b.have(p)){flag=0;return Point(0,0);}
	return p;
}
map<Point,int> pts;

int main()
{
    scanf("%d",&n);
    int sx,sy,tx,ty;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    	ans+=gcd(abs(tx-sx),abs(ty-sy))+1;
    	a[i]=Segment(Point(sx,sy),Point(tx,ty));
    }
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    	{
    		bool flag;
    		Point t=intersec(a[i],a[j],flag);
    		if(!flag || !t.isinc())continue;
    		if(!pts.count(t))
			{
				--ans;
				pts[t]=i;
			}
			else if(pts[t]==i)--ans;
    	}
    cout<<ans<<endl;
    return 0;
}