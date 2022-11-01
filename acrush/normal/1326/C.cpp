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

#define MOD (998244353)

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
	int n,k;
	while (cin>>n>>k)
	{
		VI p(n);
		REP(i,n) cin>>p[i];
		int64 r1=0;
		REP(i,k) r1+=(n-i);
		VI a;
		REP(i,n) if (p[i]>n-k) a.push_back(i);
		int r2=1;
		REP(i,SIZE(a)-1) r2=MUL(r2,a[i+1]-a[i]);
		cout<<r1<<" "<<r2<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}