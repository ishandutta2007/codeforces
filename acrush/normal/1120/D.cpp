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

const int maxn=200000+16;

int n;
int c[maxn];
vector<int> g[maxn];
int s[maxn],t[maxn];
int m;
int f[maxn];

int getf(int p)
{
	return (f[p]<0?p:(f[p]=getf(f[p])));
}
void dfs(int p,int prev)
{
	if (prev>=0 && SIZE(g[p])==1)
	{
		s[p]=m;
		t[p]=m+1;
		m++;
		return;
	}
	s[p]=m;
	for (int x:g[p]) if (x!=prev) dfs(x,p);
	t[p]=m;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n)
	{
		REP(i,n) cin>>c[i];
		REP(i,n) g[i].clear();
		REP(i,n-1)
		{
			int x,y;
			cin>>x>>y; --x; --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		m=0;
		dfs(0,-1);
		vector<ipair> order(n);
		REP(i,n) order[i]=MP(c[i],i);
		sort(ALL(order));
		++m;
		REP(i,m) f[i]=-1;
		int64 ret=0;
		vector<int> ret_set;
		REP(i,n) if (i==0 || order[i].first!=order[i-1].first)
		{
			int k=i;
			for (;k<n && order[i].first==order[k].first;++k);
			FOR(cl,i,k)
			{
				int p=order[cl].second;
				int a=getf(s[p]);
				int b=getf(t[p]);
				if (a!=b) ret_set.push_back(p);
			}
			FOR(cl,i,k)
			{
				int p=order[cl].second;
				int a=getf(s[p]);
				int b=getf(t[p]);
				if (a==b) continue;
				ret+=c[p];
				f[a]=b;
			}
		}
		sort(ALL(ret_set));
		printf("%lld %d\n",ret,SIZE(ret_set));
		for (int x:ret_set) printf("%d ",x+1);
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}