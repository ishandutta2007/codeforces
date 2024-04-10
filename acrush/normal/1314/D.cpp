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
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
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

const int INF=1050000000;

double get_time()
{
	return (double)clock()/CLOCKS_PER_SEC;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		double time_limit=get_time()+2.7;
		vector<VI> g(n,VI(n));
		REP(i,n) REP(j,n) cin>>g[i][j];
		int ret=INF;
		while (get_time()<time_limit)
		{
			VI w[2];
			REP(i,n) w[i==0?0:rand()%2].push_back(i);
			VI f(n,INF);
			f[0]=0;
			REP(step,m)
			{
				VI h(n,INF);
				for (int x:w[0]) for (int y:w[1]) ckmin(h[y],f[x]+g[x][y]);
				w[0].swap(w[1]);
				f.swap(h);
			}
			ckmin(ret,f[0]);
		}
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}