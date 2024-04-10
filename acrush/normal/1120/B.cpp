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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		const int SIZE=100000;
		string a,b;
		cin>>a>>b;
		int64 ret=0;
		vector<ipair> p;
		int k=-1;
		REP(i,n)
		{
			ckmax(k,i+1);
			while (a[i]<b[i])
			{
				for (;k<n && a[k]==((k-i)%2?'9':'0');++k);
				if (k>=n) { ret=-1; break; }
				ret+=k-i;
				++a[i];
				a[k]+=((k-i)%2?1:-1);
				if (SIZE(p)<SIZE) for (int j=k-1;j>=i;j--) p.emplace_back(j,(j-i)%2?-1:1);
			}
			if (ret<0) break;
			while (a[i]>b[i])
			{
				for (;k<n && a[k]==((k-i)%2?'0':'9');++k);
				if (k>=n) { ret=-1; break; }
				ret+=k-i;
				--a[i];
				a[k]+=((k-i)%2?-1:1);
				if (SIZE(p)<SIZE) for (int j=k-1;j>=i;j--) p.emplace_back(j,(j-i)%2?1:-1);
			}
			if (ret<0) break;
		}
		printf("%lld\n",ret);
		if (ret>=0)
		{
			if (SIZE(p)>SIZE) p.resize(SIZE);
			for (ipair x:p) printf("%d %d\n",x.first+1,x.second);
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}