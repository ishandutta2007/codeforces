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

const int maxn=400;

int n,m;
int a[maxn][maxn];
double r[maxn];

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
void reduce(int &a,int &b)
{
	int d=gcd(abs(a),abs(b));
	a/=d;
	b/=d;
	if (a<0) a=-a,b=-b;
}
void solve(int L[],int R[])
{
	bool g[maxn];
	memset(g,true,sizeof(g));
	for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (L[i]==L[j] && R[i]==R[j]) g[j]=false;
	int c=2;
	double x[maxn],y[maxn],x0[maxn],y0[maxn];
	int op[maxn];
	x[0]=0; y[0]=0;
	x[1]=1; y[1]=0;
	double last=0;
	for (int i=0;i<n;i++) if (g[i])
	{
		double a1=R[i]-L[i];
		double b1=-1;
		double c1=L[i];
		for (int k=0;k<c;k++)
		{
			x0[k]=x[k];
			y0[k]=y[k];
			double t=-(a1*x[k]+b1*y[k]+c1);
			if (fabs(t)<=1e-9) op[k]=0;
			else op[k]=(t<0)?-1:1;
		}
		int newc=0;
		for (int k=0;k<c;k++)
		{
			if (op[k]<0)
			{
				if (k==0) x[newc]=0,y[newc++]=L[i];
				else if (k==c-1) x[newc]=1,y[newc++]=R[i];
			}
			else if (op[k]>=0)
				x[newc]=x0[k],y[newc++]=y0[k];
			if (k+1<c && op[k]*op[k+1]<0)
			{
				double a2=y0[k]-y0[k+1];
				double b2=-(x0[k]-x0[k+1]);
				double c2=x0[k]*y0[k+1]-x0[k+1]*y0[k];
				double t=a1*b2-a2*b1;
				x[newc]=+(b1*c2-b2*c1)/t;
				y[newc]=-(a1*c2-a2*c1)/t;
				newc++;
			}
		}
		c=newc;
		double current=0;
		for (int k=0;k<c-1;k++) current+=(y[k]+y[k+1])/2*(x[k+1]-x[k]);
		r[i]+=current-last;
		last=current;
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) for (int j=0;j<=m;j++) scanf("%d",&a[j][i]);
	memset(r,0,sizeof(r));
	for (int k=0;k<m;k++) solve(a[k],a[k+1]);
	for (int i=0;i<n;i++) printf("%.18lf\n",r[i]);
	return 0;
}