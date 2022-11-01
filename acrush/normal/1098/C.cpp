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

int64 calc(int64 n,int64 m,int64 deg)
{
	if (deg==1 && m==1) return n*(n+1)/2;
	assert(deg>1);
	int64 r=0,depth=1;
	while (n>m)
	{
		r+=m*depth;
		n-=m;
		++depth;
		m*=deg;
	}
	r+=n*depth;
	return r;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int64 n,s;
	while (cin>>n>>s)
	{
		if (s<n*2-1 || s>n*(n+1)/2)
		{
			printf("No\n");
			continue;
		}
		bool ok=false;
		for (int deg=1;deg<=n-1;deg++)
			if (calc(n,1,deg)<=s)
			{
				printf("Yes\n");
				int64 m=1;
				int idx=1;
				while (n>0)
				{
					s-=n;
					n-=m;
					if (n<=0) break;
					bool flag=false;
					for (int64 c=1;c<=min(n,m*deg);c++)
						if (calc(n,c,deg)<=s)
						{
							REP(i,c) printf("%d ",idx+i/deg);
							idx+=m;
							m=c;
							flag=true;
							break;
						}
					assert(flag);
				}
				printf("\n");
				ok=true;
				break;
			}
		assert(ok);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}