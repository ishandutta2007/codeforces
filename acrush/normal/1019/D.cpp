#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

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

const int maxn=4096;

int n;
int x[maxn],y[maxn];
int64 target;
vector<int> a[128][128];
vector<int> gw[128][128];

int64 area(int a,int b,int c)
{
	return abs((int64)(x[b]-x[a])*(y[c]-y[a])-(int64)(x[c]-x[a])*(y[b]-y[a]));
}
void output(int a,int b,int c)
{
	assert(area(a,b,c)==target);
	printf("Yes\n");
	printf("%d %d\n",x[a],y[a]);
	printf("%d %d\n",x[b],y[b]);
	printf("%d %d\n",x[c],y[c]);
	exit(0);
}

namespace {
int x1[maxn],y1[maxn];
int x2[maxn],y2[maxn];

void solve3(const vector<int>& a,const vector<int>& b,const vector<int>& c)
{
	int n1=SIZE(b);
	int n2=SIZE(c);
	for (int idx0:a)
	{
		int x0=x[idx0],y0=y[idx0];
		REP(i,n1) x1[i]=x[b[i]]-x0,y1[i]=y[b[i]]-y0;
		REP(i,n2) x2[i]=x[c[i]]-x0,y2[i]=y[c[i]]-y0;
		REP(i,n1) REP(j,n2)
			if ((int64)x1[i]*y2[j]-(int64)x2[j]*y1[i]==target)
			{
				output(idx0,b[i],c[j]);
			}
	}
}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n>>target;
	REP(i,n) cin>>x[i]>>y[i];
	// cin>>n;
	// target=rand();
	// REP(i,n) x[i]=rand()%1000000-500000,y[i]=rand()%1000000-500000;

	target*=2;
	vector<int64> s;
	REP(i,40000)
	{
		int a=rand()%n,b=rand()%n,c=rand()%n;
		while (a==b) b=rand()%n;
		while (a==c || b==c) c=rand()%n;
		s.push_back(area(a,b,c));
	}
	int m=-1;
	int64 best_cost=-1;
	for (int p:{23,25,29,31,35,37,41})
	{
		vector<int> c(p);
		for (int64 z:s) ++c[z%p];
		int64 cost=0;
		for (int z:c) cost+=sqr((int64)z);
		if (best_cost<0 || cost<best_cost) best_cost=cost,m=p;
	}
	REP(i,n) a[(x[i]%m+m)%m][(y[i]%m+m)%m].push_back(i);
	int mod_target=target%m;
	REP(e,m) REP(w,m) REP(i,m) if (i*e%m==w) gw[e][w].push_back(i);
	REP(x1,m) REP(y1,m) if (!a[x1][y1].empty())
		FOR(x2,x1,m) REP(y2,m) if (!a[x2][y2].empty())
		{
			int e=x2-x1;
			FOR(x3,x1,m) 
			{
				int w=((mod_target+(x3-x1)*(y2-y1)+y1*(x2-x1))%m+m)%m;
				for (int y3:gw[e][w]) if (!a[x3][y3].empty())
				{
					solve3(a[x1][y1],a[x2][y2],a[x3][y3]);
				}
			}
		}
	printf("No\n");
	return 0;
}