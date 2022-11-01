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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,c1,c2;
	while (cin>>n>>c1>>c2)
	{
		string s;
		cin>>s;
		vector<vector<int>> f(n+1,vector<int>(n+1));
		for (int i=n-1;i>=0;i--) for (int j=n-1;j>=0;j--)
			if (s[i]==s[j])
				f[i][j]=f[i+1][j+1]+1;
		vector<int> g(n+1,100000000);
		g[0]=0;
		REP(i,n)
		{
			ckmin(g[i+1],g[i]+c1);
			int l=0;
			REP(j,i) ckmax(l,min(i-j,f[j][i]));
			REP(j,l) ckmin(g[i+j+1],g[i]+c2);
		}
		printf("%d\n",g[n]);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}