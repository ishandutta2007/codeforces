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

const int maxsize=(1<<20);

int n,m;
char a[maxsize];
int c;
int p[maxsize];

int solve(int s,int t)
{
	int ret=1000000000;
	int low=s,high=t;
	for (;low+1<high;)
	{
		int m=(low+high)/2;
		if (p[m]-p[s]<p[t]-p[m]) low=m;
		else high=m;
	}
	for (int d=-2;d<=2;d++)
	{
		int m=(low+high)/2+d;
		if (m<s || m>t) continue;
		ckmin(ret,max(p[m]-p[s],p[t]-p[m]));
	}
	return ret;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m>>a;
	m++;
	c=0;
	REP(i,n) if (a[i]=='0') p[c++]=i;
	int ret=1000000000;
	REP(i,c-m+1) ckmin(ret,solve(i,i+m-1));
	printf("%d\n",ret);
	return 0;
}