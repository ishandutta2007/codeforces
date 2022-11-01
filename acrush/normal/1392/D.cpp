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

int ok(int a,int b,int c)
{
	if (a==1 && c!=0) return (b==0);
	if (a!=1 && c==0) return (b==1);
	return 1;
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
		int n;
		string s;
		cin>>n>>s;
		VI a(n);
		REP(i,n) a[i]=(s[i]=='L'?0:1);
		int ret=100000000;
		REP(a0,2) REP(a1,2)
		{
			vector<VI> f(2,VI(2,100000000));
			f[a0][a1]=(int)(a0!=a[0])+(int)(a1!=a[1]);
			FOR(i,2,n)
			{
				vector<VI> g(2,VI(2,100000000));
				REP(p0,2) REP(p1,2) REP(p2,2) if (ok(p0,p1,p2)) ckmin(g[p1][p2],f[p0][p1]+(int)(p2!=a[i]));
				f.swap(g);
			}
			REP(p0,2) REP(p1,2) if (ok(p0,p1,a0) && ok(p1,a0,a1)) ckmin(ret,f[p0][p1]);
		}
		printf("%d\n",ret);
	}
	return 0;
}