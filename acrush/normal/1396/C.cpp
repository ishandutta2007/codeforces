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
using VI=vector<int64>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		int64 r1,r2,r3,d;
		cin>>r1>>r2>>r3>>d;
		ckmin(r1,r3);
		VI a(n);
		REP(i,n) cin>>a[i];
		vector<VI> f(n,VI(3,1LL<<60));
		f[0][0]=0;
		int64 ret=(1LL<<60);
		int g[3][3];
		memset(g,0,sizeof(g));
		g[0][0]=g[0][1]=g[0][2]=1;
		g[1][1]=1;
		g[2][0]=g[2][2]=1;
		REP(k,n) 
		{
			int64 c1=r1*a[k]+r3;
			int64 c2=min(c1,min(r1*a[k]+r1*2,r2+min(r1,r2)));
			// printf("%d  %lld %lld %lld\n",k,f[k][0],f[k][1],f[k][2]);
			REP(prev,3) REP(current,3)
			{
				if (!g[prev][current]) continue;
				int64 t1=f[k][prev]+c1;
				if (k==n-1) 
					ckmin(ret,t1);
				else 
					ckmin(f[k+1][current],t1+(current+1)*d);
				int64 t2=f[k][prev]+c2;
				if (k==n-1)
				{
					if (prev==2) ckmin(ret,t2);
				}
				else
				{
					if (current>0 || prev>0) ckmin(f[k+1][current],t2+(current+1)*d);
				}
			}
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}