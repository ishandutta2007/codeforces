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

int n,sx,sy;
int r[128][128];

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>sx>>sy;
	int c1=1,c2=2;
	memset(r,0,sizeof(r));
	REP(x,sx) REP(y,sy)
		if ((x+y)%2==0)
		{
			if (c1<=n) { r[x][y]=c1; c1+=2; }
		}
		else
		{
			if (c2<=n) { r[x][y]=c2; c2+=2; }
		}
	if (c1<=n || c2<=n)
		printf("-1\n");
	else
		REP(x,sx) 
		{
			REP(y,sy) 
			{
				if (y>0) printf(" ");
				printf("%d",r[x][y]);
			}
			printf("\n");
		}
	return 0;
}