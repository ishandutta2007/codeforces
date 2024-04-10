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

const int maxsize=(1<<20);

int n;
vector<int> g[maxsize];
int a[maxsize],p[maxsize];
int dfn[maxsize],cnt[maxsize];
int counter;
int father[maxsize],depth[maxsize];
int f[maxsize][20];
ipair tree[maxsize];

void dfs(int p)
{
	dfn[p]=(counter++);
	cnt[p]=1;
	for (int z:g[p])
	{
		father[z]=p;
		depth[z]=depth[p]+1;
		f[z][0]=p;
		for (int k=1;two(k)<=depth[z];k++) f[z][k]=f[f[z][k-1]][k-1];
		dfs(z);
		cnt[p]+=cnt[z];
	}
}
int getf(int p,int l)
{
	REP(d,20) if (l&(1<<d)) p=f[p][d];
	return p;
}
int lca(int x,int y)
{
	if (depth[x]>depth[y]) swap(x,y);
	y=getf(y,depth[y]-depth[x]);
	if (x==y) return x;
	int w=depth[x];
	for (int d=19;d>=0;d--) if (w>(1<<d))
	{
		int px=f[x][d],py=f[y][d];
		if (px==py) { w=(1<<d); continue; }
		w-=(1<<d);
		x=px;
		y=py;
	}
	return f[x][0];
}

int get_dist(int a,int b)
{
	int c=lca(a,b);
	return depth[a]+depth[b]-depth[c]*2;
}
ipair merge_path2(ipair p1,int c)
{
	if (p1.first<0 || c<0) return MP(-1,-1);
	int a=p1.first;
	int b=p1.second;
	int dab=get_dist(a,b);
	int dbc=get_dist(b,c);
	int dca=get_dist(c,a);
	if (dab+dbc==dca) return MP(a,c);
	if (dab+dca==dbc) return MP(b,c);
	if (dbc+dca==dab) return MP(a,b);
	return MP(-1,-1);
}
ipair merge_path(ipair p1,ipair p2)
{
	if (p1.first<0 || p2.first<0) return MP(-1,-1);
	ipair x=merge_path2(p1,p2.first);
	if (x.first<0) return MP(-1,-1);
	return merge_path2(x,p2.second);
}
void update(int id)
{
	tree[id]=merge_path(tree[id*2+1],tree[id*2+2]);
}
void init_tree(int id,int s,int t)
{
	if (s==t)
	{
		tree[id]=MP(p[s],p[s]);
		return;
	}
	int m=(s+t)/2;
	init_tree(id*2+1,s,m);
	init_tree(id*2+2,m+1,t);
	update(id);
}
void update(int id,int s,int t,int key)
{
	if (s==t)
	{
		tree[id]=MP(p[s],p[s]);
		return;
	}
	int m=(s+t)/2;
	if (key<=m)
		update(id*2+1,s,m,key);
	else
		update(id*2+2,m+1,t,key);
	update(id);
}
int calc(int id,int s,int t,ipair& prev_path)
{
	if (tree[id].first>=0)
	{
		if (prev_path.first<0) { prev_path=tree[id]; return t+1; }
		ipair x=merge_path(tree[id],prev_path);
		if (x.first>=0) { prev_path=x; return t+1; }
	}
	if (s==t) return s;
	int m=(s+t)/2;
	int ret=calc(id*2+1,s,m,prev_path);
	if (ret<=m) return ret;
	return calc(id*2+2,m+1,t,prev_path);
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n)
	{
		REP(i,n) cin>>a[i];
		REP(i,n) g[i].clear();
		REP(i,n) p[a[i]]=i;
		REP(i,n-1)
		{
			int p;
			cin>>p;
			--p;
			g[p].push_back(i+1);
		}
		counter=0;
		depth[0]=0;
		father[0]=-1;
		dfs(0);
		init_tree(0,0,n-1);
		int nq;
		for (cin>>nq;nq>0;nq--)
		{
			int tp;
			cin>>tp;
			if (tp==1)
			{
				int x,y;
				cin>>x>>y;
				--x; --y;
				swap(a[x],a[y]);
				p[a[x]]=x;
				p[a[y]]=y;
				update(0,0,n-1,a[x]);
				update(0,0,n-1,a[y]);
			}
			else
			{
				ipair path=MP(-1,-1);
				int ret=calc(0,0,n-1,path);
				printf("%d\n",ret);
			}
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}