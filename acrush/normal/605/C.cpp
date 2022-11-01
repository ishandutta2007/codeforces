#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

const int maxn=200000+16;

int n;
double p,q;
double a[maxn],b[maxn];
double x[maxn],w[maxn];

bool ck2(double r)
{
	bool f1=false,f2=false,f3=false;
	double px1,py1,px2,py2;
	REP(i,n) if (fabs(w[i])>eps)
		if (w[i]>0 && x[i]>=r-eps)
		{
			double x0=max(0.0,x[i]-r);
			double y0=w[i];
			if (!f1) f1=true,px1=x0,py1=y0;
			else if (x0*py1-y0*px1>0) px1=x0,py1=y0;
		}
		else if (w[i]<0)
		{
			if (x[i]>=r) { f3=true; continue; }
			double x0=max(0.0,r-x[i]);
			double y0=-w[i];
			if (!f2) f2=true,px2=x0,py2=y0;
			else if (x0*py2-y0*px2<0) px2=x0,py2=y0;
		}
	if (f1 && f3) return true;
	return f1 && f2 && px1*py2>=px2*py1;
}
bool ck(double r)
{
	REP(i,n) if (fabs(w[i])<=eps && x[i]>=r) return true;
	double u1=sqrt(1.0+sqr(p/q));
	REP(i,n) if (w[i]>=0 && b[i]*u1>=r) return true;
	double u2=sqrt(1.0+sqr(q/p));
	REP(i,n) if (w[i]<=0 && a[i]*u2>=r) return true;
	if (ck2(r)) return true;
	REP(i,n) w[i]=-w[i];
	bool ret=ck2(r);
	REP(i,n) w[i]=-w[i];
	return ret;
}
double solve()
{
	double l=sqrt(sqr(p)+sqr(q));
	p/=l;
	q/=l;
	REP(i,n) x[i]=a[i]*p+b[i]*q;
	REP(i,n) w[i]=a[i]*q-b[i]*p;
	double mx=0;
	REP(i,n) ckmax(mx,x[i]);
	double low=0,high=mx;
	for (int step=0;step<30;step++)
	{
		double r=(low+high)/2.0;
		if (ck(r))
			low=r;
		else
			high=r;
	}
	return l/high;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n)
	{
		cin>>p>>q;
		REP(i,n) cin>>a[i]>>b[i];
		double ret=solve();
		if (ret<0) ret=0;
		printf("%.18lf\n",ret);
	}
	return 0;
}