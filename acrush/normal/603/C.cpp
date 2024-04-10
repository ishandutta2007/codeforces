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

int calc0(int n)
{
	if (n==0) return 0;
	if (n==1) return 1;
	if (n==2) return 2;
	return (n-3)%2;
}
int calc1(int n)
{
	if (n==0) return 0;
	if (n==1) return 1;
	if (n==2) return 0;
	if (n==3) return 1;
	if (n==4) return 2;
	if (n%2==1) return 0;
	int x=calc1(n-1);
	int y=calc1(n/2);
	if (x!=0 && y!=0) return 0;
	if (x!=1 && y!=1) return 1;
	return 2;
}
int main()
{
#ifdef _MSC_VER
	freopen("c.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	int n,k;
	while (cin>>n>>k)
	{
		int ret=0;
		REP(i,n)
		{
			int p;
			cin>>p;
			if (k%2==0) ret^=calc0(p);
			else ret^=calc1(p);
		}
		if (ret)
			printf("Kevin\n");
		else
			printf("Nicky\n");
	}
	return 0;
}