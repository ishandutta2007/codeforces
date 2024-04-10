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

int n;
vector<int> c;
vector<vector<ipair>> g;
int64 ret;

int64 dfs(int p,int prev)
{
	int64 m1=0,m2=0;
	for (ipair w:g[p]) 
	{
		int z=w.first;
		if (z==prev) continue;
		int64 t=dfs(z,p);
		t=max(0LL,t-w.second);
		if (t>m1) m2=m1,m1=t;
		else if (t>m2) m2=t;
	}
	ckmax(ret,m1+m2+c[p]);
	return m1+c[p];
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n)
	{
		c.clear();
		c.resize(n);
		g.clear();
		g.resize(n);
		REP(i,n) cin>>c[i];
		REP(i,n-1)
		{
			int a,b,w;
			cin>>a>>b>>w;
			--a; --b;
			g[a].emplace_back(b,w);
			g[b].emplace_back(a,w);
		}
		ret=0;
		dfs(0,-1);
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}