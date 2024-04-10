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
using VVI=vector<VI>;

struct Edge
{
	int u;
	int v;
	int c;

	int anti(int x) const { return u^v^x; }
};
int n;
vector<Edge> e;
VVI g;
VVI w;

int dfs(int cur,int prev)
{
	for (int eid:g[cur]) 
	{
		int next=e[eid].anti(cur);
		if (next==prev) continue;
		if (!dfs(next,cur)) return 0;
		int e0=SIZE(g[next])/2;
		int e1=SIZE(g[next])-e0;
		if (w[next][0]>e0 || w[next][1]>e1) return 0;
		e[eid].c=(w[next][0]<e0?0:1);
		++w[cur][e[eid].c];
		++w[next][e[eid].c];
	}
	return 1;
}

void process()
{
	cin>>n;
	e=vector<Edge>(n-1);
	for (auto& f:e) { cin>>f.u>>f.v; --f.u; --f.v; }
	g=VVI(n);
	REP(i,n-1) g[e[i].u].push_back(i);
	REP(i,n-1) g[e[i].v].push_back(i);
	w=VVI(n,VI(2));
	if (!dfs(0,-1)) { printf("NO\n"); return; }
	REP(i,n) if (w[i][0]!=SIZE(g[i])/2) { printf("NO\n"); return; }
	printf("YES\n");
	VI d(n);
	REP(i,n) d[i]=SIZE(g[i]);
	VI r(n-1);

	auto ck=[&](int i) -> int
	{
		return !r[i] && d[e[i].u]%2==e[i].c && d[e[i].v]%2==e[i].c;
	};
	VI q;
	REP(i,n-1) if (ck(i)) q.push_back(i);

	auto touch=[&](int cur) 
	{
		REP(i,SIZE(g[cur]))
		{
			int eid=g[cur][i];
			if (r[eid]) 
			{
				swap(g[cur][i],g[cur].back());
				g[cur].pop_back();
				--i;
				continue;
			}
			if (ck(eid)) 
			{
				q.push_back(eid);
				break;
			}
		}
	};

	REP(cl,SIZE(q))
	{
		int key=q[cl];
		if (!ck(key)) continue;
		r[key]=1;
		--d[e[key].u];
		--d[e[key].v];
		printf("%d %d\n",e[key].u+1,e[key].v+1);
		touch(e[key].u);
		touch(e[key].v);
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin>>t;t>0;t--) process();
	return 0;
}