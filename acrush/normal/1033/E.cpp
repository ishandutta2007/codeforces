#ifdef _MSC_VER
//#define LOCAL
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

const int maxn=1024;

int n;

#ifdef LOCAL
int _g[maxn][maxn];
int nq=0;
void generate(int seed=1028)
{
	srand(seed);
	int density=rand()%10+1;
	REP(i,n) REP(j,n) _g[i][j]=0;
	int m=0;
	REP(i,n) FOR(j,i+1,n) if (rand()%density==0) ++m,_g[i][j]=_g[j][i]=1;
	if (n<=10) REP(i,n) 
	{
		REP(j,n) printf("%d",_g[i][j]);
		printf("\n");
	}
	printf("n = %d m = %d\n",n,m);
	nq=0;
}
int do_query(vector<int> s)
{
	++nq;
	int ret=0;
	REP(i,SIZE(s)) FOR(j,i+1,SIZE(s)) if (_g[s[i]][s[j]]) ++ret;
	return ret;
}
#endif

map<vector<int>,int> cache;

int query(vector<int> s)
{
	sort(ALL(s));
	if (SIZE(s)<=1) return 0;
	auto it=cache.find(s);
	if (it!=cache.end()) return cache[s];
#ifdef LOCAL
	printf("? %d\n",SIZE(s));
	REP(i,SIZE(s)) { if (i>0) printf(" "); printf("%d",s[i]+1); } printf("\n");
	fflush(stdout);
	return cache[s]=do_query(s);
#else
	printf("? %d\n",SIZE(s));
	REP(i,SIZE(s)) { if (i>0) printf(" "); printf("%d",s[i]+1); } printf("\n");
	fflush(stdout);
	int cnt;
	scanf("%d",&cnt);
	return cache[s]=cnt;
#endif
}

int c[maxn],f[maxn];
vector<int> g[maxn];

int getf(int p)
{
	if (f[p]<0) return p;
	int r=getf(f[p]);
	c[p]^=c[f[p]];
	return f[p]=r;
}

void output_no(vector<int> points)
{
#ifdef LOCAL
	if (SIZE(points)%2==0)
	{
		printf("Bad1\n");
		exit(0);
	}
	REP(i,SIZE(points)) if (!_g[points[i]][points[(i+1)%SIZE(points)]])
	{
		printf("Bad2\n");
		exit(0);
	}
	printf("Passed  NQ = %d\n",nq);
#endif
	printf("N %d\n",SIZE(points));
	REP(i,SIZE(points))
	{
		if (i>0) printf(" ");
		printf("%d",points[i]+1);
	}
	printf("\n");
	fflush(stdout);
	exit(0);
}

void output_yes(vector<int> points)
{
	vector<int> c(n);
	for (int p:points) c[p]=1;
#ifdef LOCAL
	REP(i,n) REP(j,n) if (c[i]==c[j] && _g[i][j])
	{
		printf("BadEdge %d %d\n",i,j);
		exit(0);
	}
	printf("Passed  NQ = %d\n",nq);
#endif
	printf("Y %d\n",SIZE(points));
	REP(i,SIZE(points))
	{
		if (i>0) printf(" ");
		printf("%d",points[i]+1);
	}
	printf("\n");
	fflush(stdout);
	exit(0);
}

void dfs(int x,int y,vector<bool>& v,vector<int>& p)
{
	if (x==y) 
	{
		p.push_back(x);
		output_no(p);
	}
	if (v[x]) return;
	v[x]=true;
	p.push_back(x);
	for (int z:g[x]) dfs(z,y,v,p);
	p.pop_back();
}

void add_edge(int x,int y)
{
	int d=1;
	int px=getf(x);
	int py=getf(y);
	if (px==py)
	{
		if ((c[x]^c[y])==d) return;
		vector<bool> v(n);
		vector<int> p;
		dfs(x,y,v,p);
		exit(0);
	}
	f[px]=py;
	c[px]=(c[x]^c[y]^d);
	g[x].push_back(y);
	g[y].push_back(x);
}

void solve2(int key,int s,int t)
{
	vector<int> pts;
	for (int i=s;i<=t;i++) if (getf(key)!=getf(i)) pts.push_back(i);
	if (SIZE(pts)==0) return;
	int c0=query(pts);
	pts.push_back(key);
	int c1=query(pts);
	pts.pop_back();
	if (c0==c1) return;
	if (SIZE(pts)==1)
	{
		add_edge(key,pts[0]);
	}
	else
	{
		int m=(s+t)/2;
		solve2(key,s,m);
		solve2(key,m+1,t);
	}
}
void solve(int s,int t)
{
	if (s>=t) return;
	int m=(s+t)/2;
	solve(s,m);
	solve(m+1,t);
	for (int k=m+1;k<=t;k++) solve2(k,s,m);
}
void find_edge(vector<int> p)
{
	while (1)
	{
		int c0=query(p);
		int key=p.back();
		p.pop_back();
		int c1=query(p);
		if (c0==c1) continue;
		for (int x:p) if (query({key,x})) add_edge(key,x);
	}
}

int main()
{
#ifdef LOCAL
	n=600;
	generate();
#else
	cin>>n;
#endif
	REP(i,n) f[i]=-1,c[i]=0;
	REP(i,n) g[i].clear();
	solve(0,n-1);
	REP(i,n) getf(i);
	vector<int> p1,p2;
	REP(i,n) 
		if (c[i]) p1.push_back(i);
		else p2.push_back(i);
	if (query(p1)>0) find_edge(p1);
	if (query(p2)>0) find_edge(p2);
	output_yes(p1);
	return 0;
}