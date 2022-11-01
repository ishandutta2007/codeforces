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
using VI=vector<int64>;
using VD=vector<double>;
using VVI=vector<VI>;

int main()
{
	VVI choose(128,VI(128));
	REP(i,128) REP(j,i+1) choose[i][j]=(j==0?1:choose[i-1][j-1]+choose[i-1][j]);
	int n;
	cin>>n;
	VVI a(n,VI(n));
	VVI w(n,VI(n));
	REP(s,n+n-2)
	{
		int64 last=0;
		REP(x,n)
		{
			int y=s-x;
			if (y<0 || y>=n) continue;
			assert(w[x][y]<=last);
			a[x][y]=last-w[x][y];
			w[x][y]=last;
			last+=choose[x+y][y];
		}
		REP(x,n)
		{
			int y=s+1-x;
			if (y<0 || y>=n) continue;
			assert(w[x][y]<=last);
			w[x][y]=(x>0?w[x-1][y]:w[x][y-1]);
		}
	}
	REP(x,n)
	{
		REP(y,n) printf("%lld ",a[x][y]);
		printf("\n");
	}
	fflush(stdout);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int64 s;
		cin>>s;
		int64 original_s=s;
		vector<ipair> path;
		for (int x0=n-1,y0=n-1;;)
		{
			path.push_back({x0,y0});
			if (x0+y0==0) break;
			int64 t=choose[x0-1+y0][y0];
			if (x0-1>=0 && s<t)
				--x0;
			else
				s-=t,--y0;
		}
		int64 w=0;
		REP(i,SIZE(path)) w+=a[path[i].first][path[i].second];
		assert(w==original_s);
		reverse(ALL(path));
		REP(i,SIZE(path)) printf("%d %d\n",path[i].first+1,path[i].second+1);
		fflush(stdout);
	}
	return 0;
}