#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

const int INF=100000000;

void solve(const VI& a,int src,int count,int r[2][2])
{
	REP(w,2) REP(l,2) r[w][l]=-INF;
	if (count==2)
	{
		int p1=a[src],p2=a[src+1];
		r[p1][p2]=r[p2][p1]=(p1|p2);
		return;
	}
	int r1[2][2],r2[2][2];
	solve(a,src,count/2,r1);
	solve(a,src+count/2,count/2,r2);
	REP(p1,2) REP(p2,2) REP(p3,2) REP(p4,2) REP(w13,2) REP(w24,2) REP(wl,2)
	{
		int cnt=r1[p1][p2]+r2[p3][p4];
		int p5=(w13?p1:p3);
		int p7=(w13?p3:p1);
		cnt+=(p1|p3);
		int p6=(w24?p2:p4);
		cnt+=(p2|p4);
		int p8=(wl?p6:p7);
		cnt+=(p6|p7);
		ckmax(r[p5][p8],cnt);
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		VI a(two(n));
		REP(i,m) { int p; cin>>p; --p; a[p]=1; }
		int r[2][2];
		solve(a,0,two(n),r);
		int ret=0;
		REP(x,2) REP(y,2) ckmax(ret,r[x][y]+(x|y));
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}