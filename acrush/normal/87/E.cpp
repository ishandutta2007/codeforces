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
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=1000000+5;

struct Point
{
	int64 x,y;
};
bool operator<(const Point &a,const Point &b)
{
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

class Convex
{
public:
	int n;
	Point p[maxn];
	void readin()
	{
		scanf("%d",&n);
		int x,y;
		for (int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			p[i].x=x;
			p[i].y=y;
		}
	}
};
Convex p1,p2,p3;
int pk[maxn];
int m,size;
Point pts[maxn];
pair<pair<int64,int64>,int> q[maxn];
bool R[maxn];

Point add(Point a,Point b)
{
	Point c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	return c;
}
void add_points(Convex &a,Convex &b)
{
	int k=0;
	for (int i=0;i<a.n;i++)
	{
		Point src=a.p[i];
		Point dest=a.p[(i+1)%a.n];
		int64 gx=src.y-dest.y;
		int64 gy=-(src.x-dest.x);
		if (i==0)
		{
			int64 best=-1;
			int bestk=-1;
			for (int k=0;k<b.n;k++)
			{
				int64 current=gx*b.p[k].x+gy*b.p[k].y;
				if (k==0 || current<best) best=current,bestk=k;
			}
			k=bestk;
		}
		while (1)
		{
			int64 current=gx*b.p[k].x+gy*b.p[k].y;
			int k2=(k+1)%b.n;
			int64 next=gx*b.p[k2].x+gy*b.p[k2].y;
			if (next<current) k=k2;
			else break;
		}
		pk[i]=k;
	}
	for (int i=0;i<a.n;i++)
	{
		int src=pk[(i+a.n-1)%a.n];
		int dest=pk[i];
		pts[size++]=add(a.p[i],b.p[(src+b.n-1)%b.n]);
		pts[size++]=add(a.p[i],b.p[(dest+1)%b.n]);
		for (int k=src;k!=dest;k=(k+1)%b.n)
			pts[size++]=add(a.p[i],b.p[k]);
		pts[size++]=add(a.p[i],b.p[dest]);
	}
}
int64 cross(Point a,Point b,Point c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
void merge_convex(Convex &a,Convex &b,Convex &c)
{
	size=0;
	add_points(a,b);
	add_points(b,a);
	sort(pts,pts+size);
	c.n=0;
	for (int i=0;i<size;i++)
	{
		for (;c.n>=2 && cross(c.p[c.n-2],c.p[c.n-1],pts[i])<=0;c.n--);
		c.p[c.n++]=pts[i];
	}
	int tm=c.n;
	for (int i=size-1;i>=0;i--)
	{
		for (;c.n>=tm+1 && cross(c.p[c.n-2],c.p[c.n-1],pts[i])<=0;c.n--);
		c.p[c.n++]=pts[i];
	}
	c.n--;
}
int main()
{
#ifdef _MSC_VER
	freopen("E.in","r",stdin);
#endif
	p1.readin();
	p2.readin();
	merge_convex(p1,p2,p3);
	p2.readin();
	merge_convex(p2,p3,p1);
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		q[i]=MP(MP((int64)x*3,(int64)y*3),i);
	}
	sort(q,q+m);
	int k_min=0,k_max=0;
	for (int i=0;i<p1.n;i++) 
	{
		if (p1.p[i].x<p1.p[k_min].x) k_min=i;
		if (p1.p[i].x>p1.p[k_max].x) k_max=i;
	}
	for (int i=0;i<m;i++) R[i]=false;
	int k1=k_min,k2=k_min;
	int64 min_x=p1.p[k_min].x;
	int64 max_x=p1.p[k_max].x;
	for (;p1.p[(k2+p1.n-1)%p1.n].x==min_x;k2=(k2+p1.n-1)%p1.n);
	for (int i=0;i<m;i++)
		if (q[i].first.first==min_x)
			R[q[i].second]=(q[i].first.second>=p1.p[k1].y && q[i].first.second<=p1.p[k2].y);
		else if (q[i].first.first>min_x && q[i].first.first<max_x)
		{
			for (;p1.p[(k2+p1.n-1)%p1.n].x<=q[i].first.first;k2=(k2+p1.n-1)%p1.n);
			for (;p1.p[(k1+1)%p1.n].x<=q[i].first.first;k1=(k1+1)%p1.n);
			Point key;
			key.x=q[i].first.first;
			key.y=q[i].first.second;
			R[q[i].second]=cross(p1.p[k2],p1.p[(k2+p1.n-1)%p1.n],key)<=0 && cross(p1.p[k1],p1.p[(k1+1)%p1.n],key)>=0;
		}
		else if (q[i].first.first==max_x)
		{
			for (;p1.p[k2].x!=max_x;k2=(k2+p1.n-1)%p1.n);
			for (;p1.p[k1].x!=max_x;k1=(k1+1)%p1.n);
			R[q[i].second]=(q[i].first.second>=p1.p[k1].y && q[i].first.second<=p1.p[k2].y);
		}
	for (int i=0;i<m;i++) 
		if (R[i])
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}