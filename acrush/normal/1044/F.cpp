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

const int maxn=(2<<20);

int n,nq;
vector<int> g[maxn];
int md[maxn],cnt[maxn],dd[maxn];
int d[maxn];
int f[maxn][20];
int counter;
int low[maxn],high[maxn];

int getf(int p,int l)
{
	REP(i,20) if (contain(l,i)) p=f[p][i];
	return p;
}
void dfs(int p,int prev)
{
	low[p]=(counter++);
	d[p]=(prev<0?0:(d[prev]+1));
	f[p][0]=prev;
	for (int z=1;two(z)<=d[p];z++) f[p][z]=f[f[p][z-1]][z-1];
	for (int z:g[p]) if (z!=prev) dfs(z,p);
	high[p]=counter-1;
}
void init_tree(int id,int s,int t)
{
	md[id]=0;
	dd[id]=0;
	cnt[id]=t-s+1;
	if (s==t) return;
	int m=(s+t)/2;
	init_tree(id*2+1,s,m);
	init_tree(id*2+2,m+1,t);
}
void update_tree(int id,int s,int t,int left,int right,int delta)
{
	if (left>right) return;
	if (right<s || left>t) return;
	if (s>=left && t<=right)
	{
		dd[id]+=delta;
		md[id]+=delta;
		return;
	}
	int m=(s+t)/2;
	update_tree(id*2+1,s,m,left,right,delta);
	update_tree(id*2+2,m+1,t,left,right,delta);
	md[id]=max(md[id*2+1],md[id*2+2]);
	cnt[id]=0;
	if (md[id*2+1]==md[id]) cnt[id]+=cnt[id*2+1];
	if (md[id*2+2]==md[id]) cnt[id]+=cnt[id*2+2];
	md[id]+=dd[id];
}
void update(int x,int y,int delta)
{
	if (d[x]>d[y]) swap(x,y);
	if (getf(y,d[y]-d[x])==x)
	{
		int p=getf(y,d[y]-d[x]-1);
		update_tree(0,0,n-1,0,low[p]-1,delta);
		update_tree(0,0,n-1,high[p]+1,n-1,delta);
		update_tree(0,0,n-1,low[y],high[y],delta);
	}
	else
	{
		update_tree(0,0,n-1,low[x],high[x],delta);
		update_tree(0,0,n-1,low[y],high[y],delta);
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n>>nq)
	{
		REP(i,n) g[i].clear();
		set<ipair> edges;
		REP(i,n-1)
		{
			int x,y;
			cin>>x>>y;
			--x;
			--y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		init_tree(0,0,n-1);
		counter=0;
		dfs(0,-1);
		REP(i,nq)
		{
			int x,y;
			cin>>x>>y;
			--x;
			--y;
			if (x>y) swap(x,y);
			if (edges.count(MP(x,y)))
			{
				edges.erase(MP(x,y));
				update(x,y,-1);
			}
			else
			{
				edges.insert(MP(x,y));
				update(x,y,1);
			}
			int ret=0;
			if (md[0]==SIZE(edges)) ret=cnt[0];
			printf("%d\n",ret);
		}
#ifndef _MSC_VER
		break;
#else
		printf("\n");
#endif
	}
	return 0;
}