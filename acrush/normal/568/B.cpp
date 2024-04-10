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

const int maxn=4096;
const int64 MOD=1000000007;

int n;
int64 f[maxn];
int64 c[maxn][maxn];

int main()
{
	std::ios_base::sync_with_stdio(false);
	memset(c,0,sizeof(c));
	REP(i,maxn) REP(j,i+1) c[i][j]=((j==0)?1:(c[i-1][j-1]+c[i-1][j])%MOD);
	cin>>n;
	memset(f,0,sizeof(f));
	f[0]=1;
	REP(m,n) REP(k,m) f[m]=(f[m]+f[m-1-k]*c[m-1][k])%MOD;
	int64 ret=0;
	REP(m,n) ret=(ret+f[m]*c[n][m])%MOD;
	printf("%d\n",(int)ret);
	return 0;
}