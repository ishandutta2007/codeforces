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

const int maxn=400000+16;

int n;
int a[maxn];
vector<ipair> g[maxn];
int r[maxn];
int sksize;
int64 length[maxn];
int pts[maxn];
int delta[maxn];
int sum[maxn];
int ret[maxn];

void dfs(int p)
{
	sum[p]=0;
	for (auto e:g[p])
	{
		int x=e.first;
		int d=e.second;
		length[sksize+1]=length[sksize]+d; pts[++sksize]=x;
		dfs(x);
		sum[p]+=sum[x];
		--sksize;
	}
	int low=-1,high=sksize;
	for (;low+1<high;)
	{
		int mid=(low+high)/2;
		if (length[sksize]-length[mid]>a[p]) 
			low=mid;
		else
			high=mid;
	}
	++delta[p];
	if (low>=0) --delta[pts[low]];
	sum[p]+=delta[p];
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	REP(i,n) cin>>a[i];
	FOR(i,1,n)
	{
		int p,d;
		cin>>p>>d;
		--p;
		g[p].emplace_back(i,d);
	}
	sksize=0;
	length[0]=0;
	pts[0]=0;
	memset(delta,0,sizeof(delta));
	dfs(0);
	REP(i,n) 
	{
		if (i>0) printf(" ");
		printf("%d",sum[i]-1);
	}
	printf("\n");
	return 0;
}