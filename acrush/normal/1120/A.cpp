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
	int n,m,k,s0;
	while (cin>>n>>m>>k>>s0)
	{
		const int size=(1<<20);
		vector<int> a(n);
		REP(i,n) cin>>a[i];
		vector<int> c(size);
		REP(i,s0) { int p; cin>>p; ++c[p]; }
		vector<int> d(size);
		int e=0;
		REP(i,size) if (d[i]<c[i]) ++e;
		int cl=0,op=0;
		int ok=0;
		REP(c0,k)
		{
			int s=c0*m;
			int t=n-(k-c0-1)*m;
			for (;op!=t;op++) 
			{
				int p=a[op];
				e-=(int)(d[p]<c[p]);
				++d[p];
				e+=(int)(d[p]<c[p]);
			}
			for (;cl!=s;cl++) 
			{
				int p=a[cl];
				e-=(int)(d[p]<c[p]);
				--d[p];
				e+=(int)(d[p]<c[p]);
			}
			if (e>0) continue;
			ok=1;
			vector<int> r;
			FOR(i,s,t)
				if (c[a[i]]==0)
					r.push_back(i);
				else
					--c[a[i]];
			r.resize(t-s-m);
			printf("%d\n",SIZE(r));
			for (int x:r) printf("%d ",x+1);
			printf("\n");
			break;
		}
		if (!ok) printf("-1\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}