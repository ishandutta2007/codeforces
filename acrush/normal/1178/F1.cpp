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
		REP(i,n) { cin>>a[i]; --a[i]; }
		VI p(n);
		REP(i,n) p[a[i]]=i;
		vector<VI> f(n,VI(n));
		vector<VI> g(n,VI(n));
		for (int i=n-1;i>=0;i--)
		{
			int z=i;
			FOR(j,i,n)
			{
				if (a[j]<a[z]) z=j;
				ADDTO(f[i][j],MUL(i==z?1:g[i][z-1],j==z?1:g[z+1][j]));
				for (int k=i-1;k<=j;k++) ADDTO(g[i][j],MUL(i>k?1:f[i][k],k+1>j?1:f[k+1][j]));
			}
		}
		printf("%d\n",f[0][n-1]);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}