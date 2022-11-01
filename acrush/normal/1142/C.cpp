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

bool ck(ipair p1,ipair p2,ipair p3)
{
	int64 x1=p1.first,y1=p1.second;
	int64 x2=p2.first,y2=p2.second;
	int64 x3=p3.first,y3=p3.second;
	int64 b=(y3-y1)-(sqr(x3)-sqr(x1));
	int64 d=x3-x1;
	int64 c=(y1-sqr(x1))*d-b*x1;
	return d*sqr(x2)+b*x2+c>=d*y2;
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
		vector<ipair> a(n);
		REP(i,n) cin>>a[i].first>>a[i].second;
		sort(ALL(a));
		int m=0;
		REP(i,n) if (m==0 || a[i].first>a[m-1].first) a[m++]=a[i]; else a[m-1]=a[i];
		n=m;
		vector<ipair> q;
		REP(i,n)
		{
			for (;SIZE(q)>=2 && ck(q[SIZE(q)-2],q[SIZE(q)-1],a[i]);q.pop_back());
			q.push_back(a[i]);
		}
		printf("%d\n",SIZE(q)-1);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}