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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	if (n%2==0)
	{
		printf("First\n"); fflush(stdout);
		REP(k,2) REP(i,n) printf("%d ",i+1);
		printf("\n");
		fflush(stdout);
	}
	else
	{
		printf("Second\n"); fflush(stdout);
		VI f(n+n);
		vector<VI> g(n);
		FOR(i,1,n+n+1) { int d; scanf("%d",&d); --d; f[i%(n+n)]=d; g[d].push_back(i%(n+n)); }
		VI visited(n);
		using path=vector<ipair>;
		vector<pair<path,path>> selected;
		auto eval=[&](const path& p) {
			int s=0;
			for (const auto& w:p) s=(s+g[w.first][w.second])%(n+n);
			return s;
		};
		REP(i,n) if (!visited[i])
		{
			int src=g[i][0];
			int dst=g[i][1];
			path p1,p2;
			for (int p=src;;)
			{
				visited[f[p]]=1;
				int w=((g[f[p]][0]==p)?0:1);
				p1.push_back(MP(f[p],w));
				p2.push_back(MP(f[p],1-w));
				if ((p-dst)%n==0) break;
				int other=(p+n)%(n+n);
				int at=f[other];
				p=g[at][0]+g[at][1]-other;
			}
			selected.push_back(MP(p1,p2));
		}
		while (1)
		{
			int current=0;
			REP(i,SIZE(selected))
			{
				if (rand()&1) selected[i].first.swap(selected[i].second);
				current=(current+eval(selected[i].first))%(n+n);
			}
			if (current==0) break;
		}
		path ret;
		REP(i,SIZE(selected)) ret.insert(ret.end(),ALL(selected[i].first));
		for (const auto& w:ret) 
		{
			int x=g[w.first][w.second];
			if (x==0) x=n+n;
			printf("%d ",x);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}