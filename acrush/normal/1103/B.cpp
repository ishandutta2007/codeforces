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

string query(int x,int y)
{
	string rep;
	printf("? %d %d\n",x,y); fflush(stdout);
	cin>>rep;
	return rep;
}
int solve()
{
	int s=1;
	int t=1000000000;
	while (s<t)
	{
		if (s+1==t) return (query(0,s)=="x")?s:t;
		int m=min(s,(s+t)/4);
		string rep=query(m,m*2);
		if (rep=="x")
			ckmin(t,m*2);
		else
			ckmax(s,m*2+1);
	}
	return s;
}
int main()
{
	string s;
	while (cin>>s)
	{
		if (s=="start")
		{
			int t=solve();
			printf("! %d\n",t); fflush(stdout);
		}
		else if (s=="end") 
			break;
	}
	return 0;
}