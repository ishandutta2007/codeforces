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
	int testcase;
	for (scanf("%d",&testcase);testcase>0;testcase--)
	{
		int n;
		scanf("%d",&n);
		int ret=0;
		REP(k,10)
		{
			vector<int> a,b;
			REP(i,n) if (contain(i,k)) a.push_back(i); else b.push_back(i);
			if (SIZE(a)==0 || SIZE(b)==0) continue;
			printf("%d %d",SIZE(a),SIZE(b));
			for (int x:a) printf(" %d",x+1);
			for (int x:b) printf(" %d",x+1);
			printf("\n");
			fflush(stdout);
			int d;
			scanf("%d",&d);
			ckmax(ret,d);
		}
		printf("-1 %d\n",ret);
		fflush(stdout);
	}
	return 0;
}