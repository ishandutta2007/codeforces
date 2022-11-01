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

void out(int64 n)
{
	if (n<0)
	{
		printf("-");
		out(-n);
		return;
	}
	if (n>=10) out(n/10);
	printf("%d",(int)(n%10));
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
		vector<ipair> a(n);
		REP(i,n) cin>>a[i].first>>a[i].second;
		vector<ipair> order(n);
		REP(i,n) order[i]=MP(a[i].first-a[i].second,i);
		sort(ALL(order));
		vector<int64> s(n);
		int64 s1=0,s2=0;
		REP(i,n) s2+=a[i].second;
		REP(k,n)
		{
			int key=order[k].second;
			s2-=a[key].second;
			s[key]=s1+(int64)k*a[key].second+s2+(int64)(n-1-k)*a[key].first;			
			s1+=a[key].first;
		}
		REP(i,m)
		{
			int x,y;
			cin>>x>>y;
			--x;
			--y;
			int64 t=min(a[x].first+a[y].second,a[x].second+a[y].first);
			s[x]-=t;
			s[y]-=t;
		}
		REP(i,n) 
		{
			if (i>0) printf(" ");
			out(s[i]);
		}
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}