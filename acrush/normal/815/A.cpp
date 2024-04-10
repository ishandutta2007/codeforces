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

const int maxsize=256;

int n,m;
int a[maxsize][maxsize];
int c1[maxsize],c2[maxsize];
int bestc;
int r1[maxsize],r2[maxsize];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	REP(i,n) REP(j,m) cin>>a[i][j];
	bestc=1000000000;
	for (c1[0]=0;c1[0]<=a[0][0];c1[0]++)
	{
		REP(i,m) c2[i]=a[0][i]-c1[0];
		FOR(i,1,n) c1[i]=a[i][0]-c2[0];
		bool ok=true;
		REP(i,n) if (c1[i]<0) ok=false;
		REP(i,m) if (c2[i]<0) ok=false;
		REP(i,n) REP(j,m) if (a[i][j]!=c1[i]+c2[j]) ok=false;
		if (!ok) continue;
		int sc=0;
		REP(i,n) sc+=c1[i];
		REP(i,m) sc+=c2[i];
		if (sc>=bestc) continue;
		bestc=sc;
		REP(i,n) r1[i]=c1[i];
		REP(i,m) r2[i]=c2[i];
	}
	if (bestc==1000000000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n",bestc);
		REP(i,n) REP(k,r1[i]) printf("row %d\n",i+1);
		REP(i,m) REP(k,r2[i]) printf("col %d\n",i+1);
	}
	return 0;
}