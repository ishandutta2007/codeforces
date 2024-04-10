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

const int maxn=2048;

int n;
double x[maxn],y[maxn];
double p[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("d.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n)
	{
		int m=0,w=0;
		REP(i,n)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if (c==0) { w++; continue; }
			int d=a*a+b*b;
			x[m]=(double)(a*c)/d;
			y[m++]=(double)(b*c)/d;
		}
		n=m;
		int ret=(w*(w-1)/2)*n;
		REP(k,n)
		{
			REP(i,k) 
			{
				double d=atan2(y[i]-y[k],x[i]-x[k]);
				for (;d<-eps;d+=pi);
				for (;d>=pi-eps;d-=pi);
				p[i]=d;
			}
			sort(p,p+k);
			REP(i,k)
			{
				int c=1;
				FOR(j,i+1,k) 
					if (p[j]-p[i]<=eps) c++;
					else break;
				ret+=c*(c-1)/2;
				i+=(c-1);
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}