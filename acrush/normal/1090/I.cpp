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

int64 solve(const vector<int64>& a)
{
	int n=SIZE(a);
	int64 ret=numeric_limits<int64>::max();
	int64 w=a[0];
	FOR(i,1,n)
	{
		if (w<a[i]) ckmin(ret,w*a[i]);
		ckmin(w,a[i]);
	}
	w=a[n-1];
	for (int i=n-2;i>=0;i--)
	{
		if (a[i]<w) ckmin(ret,w*a[i]);
		ckmax(w,a[i]);
	}
	return ret;
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
		int n;
		int64 l,r,x,y,z,b1,b2;
		cin>>n>>l>>r>>x>>y>>z>>b1>>b2;
		vector<uint64> b(n+2);
		b[0]=b1;
		b[1]=b2;
		const uint64 MOD=(uint64{1}<<32);
		FOR(i,2,n) b[i]=(b[i-2]*x%MOD+b[i-1]*y%MOD+z)%MOD;
		vector<int64> a(n);
		REP(i,n) a[i]=b[i]%(r-l+1)+l;
		bool ok=false;
		REP(i,n-1) if (a[i]<a[i+1]) { ok=true; break; }
		if (!ok)
			cout<<"IMPOSSIBLE"<<endl;
		else
		{
			int64 r=solve(a);
			cout<<r<<endl;
		}
	}
	return 0;
}