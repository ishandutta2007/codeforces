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

const int maxn=10000;

int n;
int a[maxn];

double solve(vector<int> p)
{
	if (SIZE(p)==0) return 0;
	int ret=0;
	REP(i,n)
	{
		int c[26];
		memset(c,0,sizeof(c));
		for (int x:p) ++c[a[(x+i)%n]];
		int m=0;
		REP(j,26) if (c[j]==1) ++m;
		ckmax(ret,m);
	}
	return ret;
}
double solve()
{
	vector<int> g[26];
	REP(i,n) g[a[i]].push_back(i);
	double ret=0;
	REP(k,26) ret+=solve(g[k]);
	ret/=n;
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	string s;
	while (cin>>s)
	{
		n=LENGTH(s);
		REP(i,n) a[i]=s[i]-'a';
		double ret=solve();
		printf("%.12lf\n",max(0.0,ret));
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}