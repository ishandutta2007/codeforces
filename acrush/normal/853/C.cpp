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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

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

const int maxn=(1<<20);

int n,nq;
int a[maxn];
vector<int> s[maxn];

void adds(int i,int v)
{
	for (;i<=n;i=(i|(i-1))+1) s[i].push_back(v);
}
int64 C2(int n)
{
	if (n<2) return 0;
	return ((int64)n*(int64)(n-1))/2;
}
int get_s(int i,int m)
{
	if (m>=n) return i;
	if (i>=n) return m;
	int ret=0;
	for (;i>0;i&=(i-1)) ret+=upper_bound(s[i].begin(),s[i].end(),m)-s[i].begin();
	return ret;
}

int64 solve(int x1,int y1,int x2,int y2)
{
	--x1;
	--y1;
	int x[3]={x1,x2,n};
	int y[3]={y1,y2,n};
	int p[3][3];
	REP(i,3) REP(j,3) p[i][j]=get_s(x[i],y[j]);
	int64 ret=C2(p[2][2]);
	ret-=C2(p[2][2]-p[1][2]);
	ret-=C2(p[2][2]-p[2][1]);
	ret-=C2(p[0][2]);
	ret-=C2(p[2][0]);
	ret+=C2(p[2][2]-p[1][2]-p[2][1]+p[1][1]);
	ret+=C2(p[0][2]-p[0][1]);
	ret+=C2(p[2][0]-p[1][0]);
	ret+=C2(p[0][0]);
	return ret;
}
void out(int64 n)
{
	if (n>=10) out(n/10);
	printf("%d",(int)(n%10));
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>nq) 
	{
		FOR(i,1,n+1) cin>>a[i];
		REP(i,n+1) s[i].clear();
		FOR(i,1,n+1) adds(i,a[i]);
		REP(i,n+1) sort(ALL(s[i]));
		REP(i,nq)
		{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			int64 ret=solve(x1,y1,x2,y2);
			out(ret);
			printf("\n");
		}
#ifndef _MSC_VER
		break;
#endif
		printf("\n");
	}
	return 0;
}