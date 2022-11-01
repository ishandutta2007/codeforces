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

int64 gcd(int64 a,int64 b)
{
	while (b)
	{
		int64 t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	int64 limit;
	while (cin>>n>>limit)
	{
		char s[32];
		vector<int64> a(n);
		vector<int> e(n);
		REP(i,n)
		{
			cin>>s;
			a[i]=atoll(s);
		}
		REP(i,n) cin>>e[i];
		int64 d=0;
		REP(i,n) d=gcd(d,a[i]);
		vector<int> sorted_by_e(n);
		REP(i,n) sorted_by_e[i]=i;
		sort(ALL(sorted_by_e),[&](int a,int b) { return e[a]<e[b]; });
		vector<int64> c;
		for (int64 m=2;d>1;)
		{
			if (d%m==0)
			{
				c.push_back(m);
				for (;d%m==0;d/=m);
			}
			m++;
			if (m*m>d) m=d;
		}
		REP(i,n) 
		{
			int64 t=a[i];
			for (int64 x:c) for (;t%x==0;t/=x);
			a[i]=a[i]/t;
		}
		int length=SIZE(c);
		unordered_map<int64,int> visited;
		vector<pair<int,int64>> h;
		h.reserve(n);
		REP(cl,n)
		{
			int i=sorted_by_e[cl];
			if (visited[a[i]]>length) continue;
			++visited[a[i]];
			h.emplace_back(e[i],a[i]);
		}
		vector<vector<int64>> f(1<<length);
		REP(set,(1<<length)) f[set].resize(length+1,(1LL<<60));
		f[0][0]=0;
		vector<int64> g0(1<<length);
		vector<int> g1(1<<length);
		FOR(set,1,(1<<length)) REP(i,length) if (set&(1<<i)) g1[set]=i;
		vector<int> vcnt(1<<length);
		for (const auto& w:h)
		{
			vector<int64> z(length);
			REP(i,length) z[i]=1;
			REP(i,length) { int64 t=w.second; for (;t%c[i]==0;t/=c[i]) z[i]*=c[i]; }
			g0[0]=1;
			FOR(set,1,(1<<length)) g0[set]=g0[set^(1<<g1[set])]*z[g1[set]];
			int ok=0;
			FOR(set,1,(1<<length)) if (g0[set]<=limit)
				if (vcnt[set]<length) 
					ok=1,++vcnt[set];
				else
					g0[set]=limit+1;
			if (!ok) continue;
			for (int set=(1<<length)-1;set>0;set--)
				for (int subset=set;subset>0;subset=(subset-1)&set) if (g0[subset]<=limit)
					for (int i=1;i<=length;i++)
					{
						ckmin(f[set][i],f[set^subset][i-1]+w.first);
					}
		}
		int64 ret=(1LL<<60);
		REP(i,length+1)
		{
			int64 t=f[(1<<length)-1][i];
			if (t>=(1LL<<60)) continue;
			ckmin(ret,i*t);
		}
		if (ret>=(1LL<<60)) ret=-1;
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}