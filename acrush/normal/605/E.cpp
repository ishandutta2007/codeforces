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

const int maxn=1024;

int n;
double p[maxn][maxn];
double f[maxn],s[maxn];
bool v[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	REP(i,n) REP(j,n) { int d; cin>>d; p[i][j]=(double)(d)/100.0; }
	REP(i,n) s[i]=1;
	REP(i,n) f[i]=0;
	REP(i,n) v[i]=false;
	f[n-1]=0;
	int key=n-1;
	while (1)
	{
		if (key!=n-1) f[key]=(1+f[key])/(1-s[key]);
		if (key==0) break;
		v[key]=true;
		REP(i,n) if (!v[i] && p[i][key]>eps)
		{
			f[i]+=s[i]*p[i][key]*f[key];
			s[i]*=(1-p[i][key]);
		}
		double minf=1e100;
		REP(i,n) if (!v[i] && s[i]<1-eps)
		{
			double d=(1+f[i])/(1-s[i]);
			if (d<minf) minf=d,key=i;
		}
	}
	printf("%.18lf\n",max(0.0,f[0]));
	return 0;
}