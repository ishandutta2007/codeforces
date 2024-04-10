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

const int maxn=100000+16;

int n,m;
vector<int> g[maxn][2];
int c[maxn];
int s[2],q[2][maxn];

bool dfs(int p,int w)
{
	if (c[p]>=0) return c[p]==w;
	c[p]=w;
	q[w][s[w]++]=p;
	REP(k,2) for (int x:g[p][k]) if (!dfs(x,w^k)) return false;
	return true;
}
pair<int,vector<int>> solve()
{
	vector<int> ret;
	memset(c,255,sizeof(c));
	REP(i,n) if (c[i]<0)
	{
		s[0]=s[1]=0;
		if (!dfs(i,0)) return MP(1000000000,ret);
		int p=(s[0]<s[1]?0:1);
		REP(j,s[p]) ret.push_back(q[p][j]);
	}
	return MP(SIZE(ret),ret);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	REP(i,m)
	{
		char s[16];
		int a,b;
		cin>>a>>b>>s;
		--a;
		--b;
		g[a][(int)(s[0]=='B')].push_back(b);
		g[b][(int)(s[0]=='B')].push_back(a);
	}
	auto r1=solve();
	REP(i,n) g[i][0].swap(g[i][1]);
	auto r2=solve();
	auto ret=((r1<r2)?r1:r2);
	if (ret.first>=100000000)
		printf("-1\n");
	else
	{
		printf("%d\n",ret.first);
		REP(i,SIZE(ret.second))
		{
			if (i>0) printf(" ");
			printf("%d",ret.second[i]+1);
		}
		printf("\n");
	}
	return 0;
}