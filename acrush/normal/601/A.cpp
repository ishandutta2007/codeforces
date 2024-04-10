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

const int maxn=400;

int n,m;
int g[maxn][maxn];
int d[maxn][maxn][2];
int sizeq;
int q[maxn*maxn*2];
int f[2][maxn][maxn];

void add(int x,int y,int p,int w)
{
	if (d[x][y][p]>=0) return;
	d[x][y][p]=w;
	q[sizeq++]=x*n*2+y*2+p;
}
int solve()
{
	REP(p,2) 
	{
		REP(i,n) REP(j,n) f[p][i][j]=100000000;
		REP(i,n) f[p][i][i]=0;
		REP(i,n) REP(j,n) if (i!=j && g[i][j]==p) f[p][i][j]=1;
		REP(k,n) REP(i,n) REP(j,n) ckmin(f[p][i][j],f[p][i][k]+f[p][k][j]);
	}
	sizeq=0;
	memset(d,255,sizeof(d));
	add(0,0,0,0);
	int ret=100000000;
	REP(cl,sizeq) 
	{
		int x=q[cl]/n/2,y=q[cl]/2%n,p=q[cl]%2;
		REP(i,n)
		{
			if (p && (y==i || g[y][i]==0)) continue;
			if (!p && (x==i || g[x][i]==1)) continue;
			if (p==1 && x==i)
			{
				if (x==n-1) ckmin(ret,(d[x][y][p]+1)/2);
				continue;
			}
			if (p==1)
				if (x==n-1) ckmin(ret,(d[x][y][p]+1)/2+f[1][i][n-1]);
				else if (i==n-1) ckmin(ret,(d[x][y][p]+1)/2+f[0][x][n-1]);
			if (p) add(x,i,0,d[x][y][p]+1);
			else add(i,y,1,d[x][y][p]+1);
		}
	}
	if (ret>=100000000) ret=-1;
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("a.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		memset(g,0,sizeof(g));
		REP(i,m) { int x,y; cin>>x>>y; --x; --y; g[x][y]=g[y][x]=1; }
		int ret=solve();
		cout<<ret<<endl;
	}
	return 0;
}