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

const int maxn=100+16;
const int maxm=1000+16;
const int maxsize=maxn*maxm;

int n,m,a[maxn];
double f0[maxsize],f1[maxsize],s[maxsize];

double solve()
{
	if (m==1) return 1;
	memset(f0,0,sizeof(f0));
	f0[0]=1;
	int w=0;
	int size=n*m+1;
	REP(k,n)
	{
		int key=a[k];
		w+=key;
		s[0]=0;
		REP(i,size) s[i+1]=s[i]+f0[i];
		REP(i,size)
		{
			f1[i]=s[i];
			if (i-m>=0) f1[i]-=s[i-m];
			if (i-key>=0) f1[i]-=f0[i-key];
			f1[i]/=(m-1);
		}
		memcpy(f0,f1,sizeof(f0));
	}
	double r=0;
	REP(i,w) r+=f0[i];
	return 1+r*(m-1);
}
int main()
{
#ifdef _MSC_VER
	freopen("b.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		REP(i,n) cin>>a[i];
		double ret=solve();
		if (ret<0) ret=0;
		printf("%.18lf\n",ret);
	}
	return 0;
}