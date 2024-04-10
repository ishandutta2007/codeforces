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
char a[maxn];
int f[maxn][2][3];

int main()
{
#ifdef _MSC_VER
	freopen("a.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>a)
	{
		memset(f,255,sizeof(f));
		f[0][0][0]=0;
		f[0][1][0]=0;
		REP(i,n) REP(p,2) REP(c,3) if (f[i][p][c]>=0)
		{
			int t=f[i][p][c];
			ckmax(f[i+1][p][c],t);
			if (c+1<3) ckmax(f[i][p][c+1],t);
			if (a[i]-'0'!=(p^((int)(c==1)))) ckmax(f[i+1][1-p][c],t+1);
		}
		int ret=0;
		REP(p,2) REP(c,3) ckmax(ret,f[n][p][c]);
		printf("%d\n",ret);
	}
	return 0;
}