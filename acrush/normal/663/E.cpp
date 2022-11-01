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

const int maxn=20;
const int maxm=100000+16;

int n,m;
int a[maxm];
int f[maxn+1][1<<maxn];
char s[maxm];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	REP(i,n)
	{
		cin>>s;
		REP(j,m) if (s[j]=='1') a[j]^=(1<<i);
	}
	memset(f,0,sizeof(f));
	REP(i,m) f[0][a[i]]++;
	FOR(k,1,n+1) REP(set,1<<n)
	{
		int& s=f[k][set];
		REP(i,n) s+=f[k-1][set^(1<<i)];
		if (k>=2) s-=f[k-2][set]*(n-k+2);
		s/=k;
	}
	int ret=n*m;
	REP(set,1<<n)
	{
		int s=0;
		REP(k,n+1) s+=min(k,n-k)*f[k][set];
		ckmin(ret,s);
	}
	printf("%d\n",ret);
	return 0;
}