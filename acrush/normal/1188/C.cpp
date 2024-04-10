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

const int MOD=998244353;

inline int ADD(int a, int b) { return (a + b >= MOD) ? (a + b - MOD) : (a + b); }
inline void ADDTO(int& a,int b) { a = ((a + b >= MOD) ? (a + b - MOD) : (a + b)); }
inline int SUB(int a, int b) { return (a >= b) ? (a - b) : (a - b + MOD); }
inline void SUBTO(int& a,int b) { a = ((a >= b) ? (a - b) : (a - b + MOD)); }
inline int MUL(int a, int b) { return (int64)a * b % MOD; }


int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		VI a(n);
		REP(i,n) cin>>a[i];
		sort(ALL(a));
		vector<VI> f(n+1,VI(m+1));
		int w=a[n-1]-a[0];
		VI p(n);
		REP(i,n) p[i]=i-1;
		VI r;
		for (int s=0;s*(m-1)<=w;s++)
		{
			REP(i,n) for (;p[i]>=0 && a[i]-a[p[i]]<=s;--p[i]);
			REP(j,m+1) f[0][j]=0;
			f[0][0]=1;
			FOR(i,1,n+1)
			{
				auto& d=f[i];
				auto& d2=f[i-1];
				for (int j=0;j<=m;j++) d[j]=d2[j];
				int w=p[i-1]+1;
				auto& d3=f[w];
				for (int j=1;j<=m;j++) ADDTO(d[j],d3[j-1]);
			}
			int cnt=f[n][m];
			r.push_back(cnt);
		}
		r.push_back(0);
		int ret=0;
		for (int i=SIZE(r)-2;i>=0;i--) ADDTO(ret,MUL(i+1,SUB(r[i],r[i+1])));
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}