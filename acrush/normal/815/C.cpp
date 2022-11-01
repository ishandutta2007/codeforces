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

const int maxn=6000+16;

int n,w;
vector<int> g[maxn];
int c[maxn],d[maxn];
int p[maxn];
int f[maxn][maxn];
vector<int> h[maxn];
int t[maxn];

int solve(int current)
{
	vector<ipair> e;
	auto& h0=h[current];
	h0.clear();
	for (int other:g[current]) 
	{
		int t=solve(other);
		e.push_back(MP(t,other));
		for (int e:h[other]) h0.push_back(e);
	}
	sort(ALL(e));
	reverse(ALL(e));
	int* f0=f[current];
	f0[0]=0;
	FOR(i,1,n+1) f0[i]=w+1;
	ckmin(f0[1],d[current]);
	for (ipair state:e)
	{
		int* g0=f[state.second];
		int c0=state.first;
		REP(i,n+1) t[i]=f0[i];
		FOR(i,1,n+1) if (f0[i]<=w) for (int k=1;k<=c0;++k)
		{
			int e=f0[i]+g0[k];
			if (e>w) break;
			ckmin(t[i+k],e);
		}
		REP(i,n+1) f0[i]=t[i];
	}

	sort(ALL(h0));
	int ss=0;
	REP(i,SIZE(h0))
	{
		ss+=h0[i];
		if (ss>w) break;
		ckmin(f0[i+1],ss);
	}
	h0.push_back(c[current]);

	int ret=0;
	for (;ret+1<=n && f0[ret+1]<=w;++ret);
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n>>w;
	REP(i,n) g[i].clear();
	REP(i,n) 
	{
		cin>>c[i]>>d[i];
		d[i]=c[i]-d[i];
		if (i==0) continue;
		cin>>p[i];
		--p[i];
		g[p[i]].push_back(i);
	}
	int ret=solve(0);
	printf("%d\n",ret);
	return 0;
}