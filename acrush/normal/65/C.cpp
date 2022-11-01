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
const double eps=1e-9;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=10000+5;

int n;
long double x[maxn],y[maxn],z[maxn];
long double v1,v2,sx,sy,sz;

double nextDouble()
{
	double d;
	scanf("%lf",&d);
	return d;
}
long double distance(long double x1,long double y1,long double z1,long double x2,long double y2,long double z2)
{
	return sqrt(sqr(x1-x2)+sqr(y1-y2)+sqr(z1-z2));
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
	{
		x[i]=nextDouble();
		y[i]=nextDouble();
		z[i]=nextDouble();
	}
	v1=nextDouble();
	v2=nextDouble();
	sx=nextDouble();
	sy=nextDouble();
	sz=nextDouble();
	long double length=0;
	for (int i=0;i<n;i++) length+=distance(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1]);
	if (length/v2<distance(sx,sy,sz,x[n],y[n],z[n])/v1-eps)
		printf("NO\n");
	else
	{
		printf("YES\n");
		long double H=0,T=length/v2;
		for (int step=0;step<1000;step++)
		{
			long double M=(H+T)/2;
			long double pos=M*v2;
			long double x0,y0,z0;
			for (int i=0;i<n;i++)
			{
				long double L=distance(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1]);
				if (L>=pos)
				{
					x0=x[i]+pos/L*(x[i+1]-x[i]);
					y0=y[i]+pos/L*(y[i+1]-y[i]);
					z0=z[i]+pos/L*(z[i+1]-z[i]);
					break;
				}
				pos-=L;
			}
			if (distance(sx,sy,sz,x0,y0,z0)/v1<=M+1e-13)
				T=M;
			else
				H=M;
			if (step==1000-1)
				printf("%.12lf\n%.12lf %.12lf %.12lf\n",(double)M,(double)x0,(double)y0,(double)z0);
		}
	}
	return 0;
}