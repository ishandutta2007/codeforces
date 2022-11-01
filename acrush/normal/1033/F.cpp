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

const int maxsize=(1<<12);
const int maxsize2=(1<<20);

int n;
int cnt,nq;
int c[maxsize],w[maxsize];
int c3[maxsize2];
int p3[32];
int m;
int a[32];

int dfs(int d,int s)
{
	if (d>=m) return c3[s];
	return dfs(d+1,s)+dfs(d+1,s+a[d]);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n>>cnt>>nq && n>0)
	{
		memset(c,0,sizeof(c));
		REP(i,cnt) { int p; cin>>p; ++c[p]; }
		REP(i,32) p3[i]=(i==0?1:p3[i-1]*3);
		memset(w,0,sizeof(w));
		REP(s,1<<n) REP(i,n) if (s&(1<<i)) w[s]+=p3[i];
		memset(c3,0,sizeof(c3));
		REP(s1,1<<n) REP(s2,1<<n) c3[w[s1]+w[s2]]+=c[s1]*c[s2];
		REP(cl,nq)
		{
			string s;
			cin>>s;	
			int b=0;
			m=0;
			REP(i,n)
			{
				char c=s[n-1-i];
				if (c=='o' || c=='x') b+=p3[i];
				if (c=='a') b+=p3[i]*2;
				if (c=='A' || c=='o') a[m++]=p3[i];
				if (c=='X') a[m++]=p3[i]*2;
			}
			printf("%d\n",dfs(0,b));
		}
#ifndef _MSC_VER
		break;
#else
		printf("\n");
#endif
	}
	return 0;
}