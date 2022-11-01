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

struct BipartiMatch
{
	BipartiMatch(int n, int m) : n(n), m(m)
	{
		g.resize(n);
		for (int i = 0; i < n; ++i) g[i].clear();
		reset();
	}

	void reset()
	{
		p1 = vector<int>(n, -1);
		p2 = vector<int>(m, -1);
	}

	void add(int x, int y)
	{
		assert(x >= 0 && x < n && y >= 0 && y < m);
		if (edges.count(make_pair(x, y))) return;
		edges.insert(make_pair(x, y));
		g[x].push_back(y);
	}

	int expand()
	{
		int ret = 0;
		for (int i = 0; i < n; ++i) if (p1[i] < 0)
			for (int j : g[i]) if (p2[j] < 0)
			{
				++ret;
				p1[i] = j;
				p2[j] = i;
				break;
			}
		visited.resize(m);
		for (int i = 0; i < n; ++i) if (p1[i] < 0)
		{
			fill(visited.begin(), visited.end(), 0);
			if (dfs(i)) ++ret;
		}
		return ret;
	}

	int solve()
	{
		reset();
		return expand();
	}

	bool dfs(int p)
	{
		for (int k : g[p]) if (!visited[k])
		{
			visited[k] = true;
			if (p2[k] < 0 || dfs(p2[k]))
			{
				p1[p] = k;
				p2[k] = p;
				return true;
			}
		}
		return false;
	}

	int n;
	int m;
	set<pair<int, int>> edges;
	vector<vector<int>> g;
	vector<int> p1;
	vector<int> p2;
	vector<int> visited;
};

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		vector<string> a(n);
		REP(i,n) cin>>a[i];
		int cnt=0;
		REP(i,n) REP(j,m) if (a[i][j]=='#') ++cnt;
		VI v1(n*m);
		VI v2(n*m);
		auto ID=[&](int x,int y) { return x*m+y; };
		BipartiMatch match(n*m,n*m);
		REP(x,n) REP(y,m)
		{
			if (x+1<n && a[x][y]=='#' && a[x+1][y]=='#') v1[ID(x,y)]=1;
			if (y+1<m && a[x][y]=='#' && a[x][y+1]=='#') v2[ID(x,y)]=1;
		}
		REP(x,n) REP(y,m) if (x+1<n && a[x][y]=='#' && a[x+1][y]=='#')
		{
			if (y-1>=0 && a[x][y-1]=='#') match.add(ID(x,y),ID(x,y-1));
			if (y+1<m && a[x][y+1]=='#') match.add(ID(x,y),ID(x,y));
			if (y-1>=0 && a[x+1][y-1]=='#') match.add(ID(x,y),ID(x+1,y-1));
			if (y+1<m && a[x+1][y+1]=='#') match.add(ID(x,y),ID(x+1,y));
		}
		int c1=accumulate(ALL(v1),0);
		int c2=accumulate(ALL(v2),0);
		int r=match.solve();
		printf("%d\n",cnt-(c1+c2-r));		
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}