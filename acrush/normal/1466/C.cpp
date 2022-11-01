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
		string a;
		cin>>a;
		int n=SIZE(a);
		int f[2][2];
		REP(x,2) REP(y,2) f[x][y]=1000000000;
		f[0][0]=0;
		REP(k,n)
		{
			int g[2][2];
			REP(x,2) REP(y,2) g[x][y]=1000000000;
			REP(x,2) REP(y,2) REP(z,2)
			{
				if (k-2>=0 && x==0 && z==0 && a[k]==a[k-2]) continue;
				if (k-1>=0 && y==0 && z==0 && a[k]==a[k-1]) continue;
				ckmin(g[y][z],f[x][y]+z);
			}
			REP(x,2) REP(y,2) f[x][y]=g[x][y];
		}
		int ret=1000000000;
		REP(x,2) REP(y,2) ckmin(ret,f[x][y]);
		printf("%d\n",ret);
	}
	return 0;
}