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
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int n;
		cin>>n;
		vector<VI> g(n);
		REP(i,n-1)
		{
			int a,b;
			cin>>a>>b; --a; --b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		VI q;
		VI r(n);
		r[0]=1;
		q.push_back(0);
		REP(cl,n)
		{
			int cur=q[cl];
			for (int next:g[cur]) if (r[next]==0) r[next]=-r[cur],q.push_back(next);
		}
		REP(i,n) printf("%d ",r[i]*SIZE(g[i]));
		printf("\n");
	}
	return 0;
}