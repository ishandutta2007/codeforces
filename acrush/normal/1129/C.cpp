#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

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

const int MOD=1000000007;

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
	int n;
	while (cin>>n)
	{
		vector<int> a(n);
		REP(i,n) cin>>a[i];
		vector<vector<int>> g(n,vector<int>(4));
		vector<vector<int>> f(n,vector<int>(n));
		REP(i,n) REP(j,4) if (i+j<n)
		{
			string s="";
			REP(k,j+1) s+=(char)(a[i+k]+'0');
			if (s=="0011" || s=="0101" || s=="1110" || s=="1111") continue;
			g[i][j]=1;
		}
		REP(i,n) REP(j,n) if (a[i]==a[j]) f[i][j]=1+(i>0 && j>0?f[i-1][j-1]:0);
		int ret=0;
		REP(k,n)
		{
			int l=0;
			REP(i,k) ckmax(l,f[i][k]);
			vector<int> dp(k+2);
			dp[k+1]=1;
			for (int i=k;i>=0;i--) REP(j,4) if (g[i][j] && i+j<=k) ADDTO(dp[i],dp[i+j+1]);
			REP(i,k+1) if (k-i+1>l) ADDTO(ret,dp[i]);
			printf("%d\n",ret);
		}
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}