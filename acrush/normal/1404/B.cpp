#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;

void up(int &m1,int &m2,int t)
{
	if (t>m1) 
		m2=m1,m1=t;
	else
		ckmax(m2,t);
}
int solve()
{
	int n;
	int sa,sb,da,db;
	cin>>n>>sa>>sb>>da>>db;
	--sa; --sb;
	vector<VI> g(n);
	REP(i,n-1)
	{
		int a,b;
		cin>>a>>b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	std::function<int(int,int,int)> getd=[&](int p,int dst,int prev) {
		if (p==dst) return 0;
		for (int x:g[p]) if (x!=prev)
		{
			int t=getd(x,dst,p);
			if (t>=0) return t+1;
		}
		return -1;
	};
	if (getd(sa,sb,-1)<=da) return 1;
	int l=0;
	VI p1(n),p2(n);
	std::function<void(int,int)> dfs=[&](int p,int prev) {
		for (int x:g[p]) if (x!=prev)
		{
			dfs(x,p);
			up(p1[p],p2[p],p1[x]+1);
		}
		ckmax(l,p1[p]+p2[p]);
	};
	dfs(0,-1);
	return 2*da>=min(l,db);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		if (solve())
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}