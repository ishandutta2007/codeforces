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
template<class T> void checkmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void checkmax(T &a,const T &b) { if (b>a) a=b; } 

double solve(int64 a,int64 b)
{
	double ret=1e100;
	int64 d=a-b;
	if (d==0) checkmin(ret,(double)b);
	if (d>0)
	{
		int64 w=d/b;
		if (w&1) w--;
		if (w>0) checkmin(ret,(double)d/(double)w);
	}
	int64 e=a+b;
	int64 z=e/b;
	if (z&1) z--;
	if (z>0) checkmin(ret,(double)e/(double)z);
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	int64 a,b;
	while (cin>>a>>b)
	{
		double ret=solve(a,b);
		if (ret>1e99) ret=-1;
		printf("%.18lf\n",ret);
	}
	return 0;
}