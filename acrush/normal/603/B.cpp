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

const int maxp=(1<<20);
const int64 MOD=1000000007;

int p;
int64 k;
int f[maxp];
int64 w[maxp];
int inv[maxp];

int getf(int x)
{
	if (f[x]<0) return x;
	int t=getf(f[x]);
	if (w[t]>0) w[x]=(w[x]*w[f[x]])%p;
	f[x]=t;
	return t;
}
void add(int x,int y,int64 k)
{
	// k * f[x] = f[y].
	int px=getf(x);
	int py=getf(y);
	if (px==py) { if (w[px]>=0 && k*w[x]%p!=w[y]) w[px]=-1; return; }
	f[px]=py;
	if (w[px]<0 || w[py]<0) w[py]=-1;
	else w[px]=w[y]*inv[w[x]*k%p]%p;
}
int gcd(int a,int b,int &x,int &y)
{
	if (b==0) { x=1; y=0; return a; }
	int d=gcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-(a/b)*y;
	return d;
}
int main()
{
#ifdef _MSC_VER
	freopen("b.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>p>>k)
	{
		if (k==0)
		{
			int64 ret=1;
			REP(i,p-1) ret=(ret*p)%MOD;
			printf("%d\n",(int)ret);
			continue; 
		}
		inv[0]=0;
		FOR(i,1,p) 
		{
			int x,y;
			gcd(p,i,x,y);
			inv[i]=(y%p+p)%p;
		}
		REP(i,p) f[i]=-1,w[i]=1;
		REP(x,p) add(x,(int)(k*x%p),k);
		int64 ret=1;
		REP(i,p) if (f[i]<0 && w[i]>0) ret=(ret*p)%MOD;
		printf("%d\n",(int)ret);
	}
	return 0;
}