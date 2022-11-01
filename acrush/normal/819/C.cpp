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
	return b==0?a:gcd(b,a%b);
}

int64 n,m,s;
vector<ipair> pn,pm,ps;

void add(int n,map<int,int>& w)
{
	for (int m=2;n>1;)
	{
		if (n%m==0)
		{
			int e=0;
			for (;n%m==0;n/=m) ++e;
			w[m]+=e;
		}
		++m;
		if (m*m>n) m=n;
	}
}
void readin(int64 &n,vector<ipair>& p,int64 base)
{
	int64 v1,v2,v3;
	cin>>v1>>v2>>v3;
	v1*=base;
	n=v1*v2*v3;
	map<int,int> w;
	add(v1,w);
	add(v2,w);
	add(v3,w);
	p.clear();
	for (auto z:w) p.push_back(z);
}

vector<ipair> a;
void add(vector<int64> &e,int64 p,int ex)
{
	int size=SIZE(e);
	e.reserve(size*(ex+1));
	for (;ex>0;ex--)
	{
		int z=SIZE(e)-size;
		REP(i,size) e.push_back(e[z+i]*p);
	}
}
int64 solve(vector<ipair> _a,int64 n)
{
	a=_a;
	sort(ALL(a),[](ipair a,ipair b){return a.second>b.second; });
	vector<int64> e1,e2;
	e1.push_back(1);
	e2.push_back(1);
	for (auto z:a)
	{
		if (SIZE(e1)<SIZE(e2)) add(e1,z.first,z.second);
		else add(e2,z.first,z.second);
	}
	sort(ALL(e1));
	sort(ALL(e2));
	int p2=SIZE(e2)-1;
	int64 ret=0;
	REP(p1,SIZE(e1))
	{
		for (;p2>=0 && e1[p1]*e2[p2]>n;--p2);
		ret+=(p2+1);
	}
	return ret;
	//return dfs(0,n);
}

vector<int64> g;
unordered_map<int64,int64> f[1024];

int64 dfs2(int depth,int64 n)
{
	if (n<=0) return 0;
	if (depth>=SIZE(g)) return n;
	auto it=f[depth].find(n);
	if (it!=f[depth].end()) return it->second;
	int64 ret=dfs2(depth+1,n)-dfs2(depth+1,n/g[depth]);
	f[depth][n]=ret;
	return ret;
}
int64 solve2(vector<int64> _g,int64 n)
{
	g=_g;
	REP(i,SIZE(g)) f[i].clear();
	return dfs2(0,n);
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase=0;
	for (cin>>testcase;testcase>0;testcase--)
	{
		readin(n,pn,1);
		readin(m,pm,1);
		readin(s,ps,2);
		int64 ret=0;
		ret+=solve(ps,n);
		map<int,int> w;
		for (auto z:ps) w[z.first]=z.second;
		vector<int64> g;
		for (auto z:pn)
		{
			if (w[z.first]>=z.second) continue;
			int64 t=1;
			REP(i,w[z.first]+1) t*=z.first;
			g.push_back(t);
		}
		ret+=solve2(g,m);
		//FOR(i,1,n+1) if (s%i==0) ++ret;
		//FOR(i,1,m+1) if (s%gcd(n,i)==0) ++ret;
		cout<<ret<<endl;
	}
	return 0;
}