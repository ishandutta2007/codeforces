#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

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
using VI=vector<int>;

int main()
{
	int n;
	scanf("%d",&n);
	vector<VI> g(n);
	REP(i,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	auto remove_edge=[&](int a,int b)
	{
		REP(i,SIZE(g[a])) if (g[a][i]==b) { g[a][i]=g[a].back(); g[a].pop_back(); break; }
		REP(i,SIZE(g[b])) if (g[b][i]==a) { g[b][i]=g[b].back(); g[b].pop_back(); break; }
	};
	int key=0;
	while (1)
	{
		VI visited(n);
		VI pts;
		std::function<void(int)> dfs=[&](int p) 
		{
			if (visited[p]) return;
			visited[p]=1;
			pts.push_back(p);
			for (int x:g[p]) dfs(x);
		};
		dfs(key);
		if (SIZE(pts)==1)
		{
			printf("! %d\n",pts[0]+1);
			fflush(stdout);
			break;
		}
		VI z;
		for (int x:pts) if (SIZE(g[x])==1) z.push_back(x);
		int p1=z[0],p2=z[1];
		printf("? %d %d\n",p1+1,p2+1);
		fflush(stdout);
		scanf("%d",&key);
		--key;
		if (key==p1 || key==p2)
		{
			printf("! %d\n",key+1);
			fflush(stdout);
			break;
		}
		VI path;
		visited=VI(n);
		std::function<int(int)> find_path=[&](int p) -> int
		{
			if (visited[p]) return 0;
			visited[p]=1;
			path.push_back(p);
			if (p==p2) return 1;
			for (int x:g[p]) if (find_path(x)) return 1;
			path.pop_back();
		};
		find_path(p1);
		REP(i,SIZE(path)-1) remove_edge(path[i],path[i+1]);
	}
	return 0;
}