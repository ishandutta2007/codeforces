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

const int oo=1000000000;

int solve3(vector<int> x,vector<int> y)
{
	int n=SIZE(x);
	int r1=-1000000000;
	int r2=-1000000000;
	int r3=-1000000000;
	REP(i,n)
	{
		ckmax(r1,2*x[i]);
		ckmax(r2,-2*x[i]-2*y[i]);
		ckmax(r3,2*y[i]);
	}
	return r1+r2+r3;
}
int solve2(vector<int> x,vector<int> y)
{
	int n=SIZE(x);
	int ret=0;
	REP(bx,2) REP(by,2)
	{
		if (bx) REP(i,n) x[i]=-x[i];
		if (by) REP(i,n) y[i]=-y[i];
		int t=solve3(x,y);
		ckmax(ret,t);
		if (bx) REP(i,n) x[i]=-x[i];
		if (by) REP(i,n) y[i]=-y[i];
	}
	return ret;
}
int solve(vector<int> x,vector<int> y)
{
	return max(solve2(x,y),solve2(y,x));
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		vector<int> x(n),y(n);
		REP(i,n) cin>>x[i]>>y[i];
		int min_x=*min_element(ALL(x));
		int max_x=*max_element(ALL(x));
		int min_y=*min_element(ALL(y));
		int max_y=*max_element(ALL(y));
		int f3=solve(x,y);
		printf("%d",f3);
		int f4=(max_x-min_x+max_y-min_y)*2;
		for (int i=4;i<=n;i++) printf(" %d",f4);
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}