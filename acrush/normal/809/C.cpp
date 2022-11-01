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

const int MOD=1000000007;

map<pair<pair<int64,int64>,int64>,pair<int64,int64>> htable;

inline int64 ck(int64 s) 
{
	s%=MOD;
	if (s<0) s+=MOD;
	return s;
}
int64 calc(int64 x,int64 y)
{
	if (x==0 || y==0) return x+y;
	int64 t=calc(x/2,y/2)*2;
	if ((x&1)!=(y&1)) ++t;
	return t;
}
pair<int64,int64> operator+(pair<int64,int64> a,pair<int64,int64> b)
{
	return MP(ck(a.first+b.first),ck(a.second+b.second));
}
pair<int64,int64> operator*(pair<int64,int64> a,int64 m)
{
	return MP(ck(a.first*m),ck(a.second*m));
}
pair<int64,int64> operator-(pair<int64,int64> a,pair<int64,int64> b)
{
	return MP(ck(a.first-b.first),ck(a.second-b.second));
}
pair<int64,int64> solve(int64 x,int64 y,int64 m)
{
	if (x<=0 || y<=0 || m<=0) return MP(0,0);
	if (x<=1 || y<=1)
	{
		int64 t=min(x*y,m);
		return MP(ck(t*(t-1)/2),t);
	}
	auto state=MP(MP(x,y),m);
	auto it=htable.find(state);
	if (it!=htable.end()) return it->second;
	pair<int64,int64> c1=solve(x/2,y/2,m/2);
	pair<int64,int64> ret=MP(c1.first*4*2+c1.second*2,c1.second*4);
	pair<int64,int64> c2;
	if (m&1)
	{
		c2=solve(x/2,y/2,(m+1)/2);
		int64 t=(c2.second-c1.second)*2;
		ret=ret+MP(ck(t*(m-1)),t);
	}
	if (x&1)
	{
		auto e1=solve((x+1)/2,y/2,m/2)-c1;
		ret=ret+MP(e1.first*2*2+e1.second,e1.second*2);
		if (m&1)
		{
			auto e2=solve((x+1)/2,y/2,(m+1)/2)-c2;
			int64 t=e2.second-e1.second;
			ret=ret+MP(ck(t*(m-1)),t);
		}
	}
	if (y&1)
	{
		auto e1=solve(x/2,(y+1)/2,m/2)-c1;
		ret=ret+MP(e1.first*2*2+e1.second,e1.second*2);
		if (m&1)
		{
			auto e2=solve(x/2,(y+1)/2,(m+1)/2)-c2;
			int64 t=e2.second-e1.second;
			ret=ret+MP(ck(t*(m-1)),t);
		}
	}
	if ((x&1) && (y&1))
	{
		int64 t=calc(x-1,y-1);
		if (t<m) ret=ret+MP(t,1);
	}
	return htable[state]=MP(ck(ret.first),ck(ret.second));
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int x1,y1,x2,y2,k;
		cin>>x1>>y1>>x2>>y2>>k;
		--x1;--y1;
		htable.clear();
		pair<int64,int64> ret=solve(x2,y2,k);
		ret=ret+solve(x1,y1,k);
		ret=ret-solve(x1,y2,k);
		ret=ret-solve(x2,y1,k);
		printf("%d\n",(int)ck(ret.first+ret.second));
	}
	return 0;
}