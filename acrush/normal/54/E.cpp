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

const int maxn=40000+5;
#define next(x) (((x)==n-1)?(0):((x)+1))
#define prev(x) (((x)==0)?(n-1):((x)-1))

int n;
int64 x[maxn],y[maxn];

int64 cross(int64 x0,int64 y0,int64 x1,int64 y1,int64 x2,int64 y2)
{
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
int64 cross(int a,int b,int c)
{
	return cross(x[a],y[a],x[b],y[b],x[c],y[c]);
}
double ppDistance(double x1,double y1,double x2,double y2)
{
	double dx=x1-x2;
	double dy=y1-y2;
	return sqrt(dx*dx+dy*dy);
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int x0,y0;
		scanf("%d%d",&x0,&y0);
		x[i]=x0;
		y[i]=y0;
	}
	int64 area=0;
	for (int i=2;i<n;i++)
		area+=cross(0,i-1,i);
	if (area<0)
		for (int i=0;i<n-1-i;i++)
		{
			swap(x[i],x[n-1-i]);
			swap(y[i],y[n-1-i]);
		}
	double R=1e100;
	for (int step=0;step<2;step++)
	{
		int64 S=0;
		int key=1;
		for (int i=0;i<n;i++)
		{
			if (i>0) S-=cross(prev(i),i,key);
			int64 dx=x[next(i)]-x[i];
			int64 dy=y[next(i)]-y[i];
			for (;x[next(key)]*dx+y[next(key)]*dy>x[key]*dx+y[key]*dy;key=next(key))
				S+=cross(i,key,next(key));
			double a1=+(y[i]-y[next(i)]);
			double b1=-(x[i]-x[next(i)]);
			double c1=x[i]*y[next(i)]-x[next(i)]*y[i];
			double a2=dx;
			double b2=dy;
			double c2=-(a2*x[key]+b2*y[key]);
			double t=a1*b2-a2*b1;
			double x0=+(b1*c2-b2*c1)/t;
			double y0=-(a1*c2-a2*c1)/t;
			checkmin(R,ppDistance(x0,y0,x[key],y[key])*ppDistance(x0,y0,x[i],y[i])/2.0-(double)S/2.0);
		}
		for (int i=0;i<n;i++) x[i]=-x[i];
		for (int i=0;i<n-1-i;i++)
		{
			swap(x[i],x[n-1-i]);
			swap(y[i],y[n-1-i]);
		}
	}
	printf("%.18lf\n",R);
	return 0;
}