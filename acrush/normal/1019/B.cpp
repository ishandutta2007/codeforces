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

int n;
int query(int x)
{
	printf("? %d\n",x%n+1);
	fflush(stdout);
	int p;
	scanf("%d",&p);
	return p;
}
void answer(int x)
{
	if (x>=0) x=x%(n/2)+1;
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int main()
{
	scanf("%d",&n);
	if (n/2%2==1) answer(-1);
	int x1=query(0);
	int x2=query(n/2);
	if (x1==x2) answer(0);
	int low=0,high=n/2;
	while (1)
	{
		int mid=(low+high)/2;
		int y1=query(mid);
		int y2=query(mid+n/2);
		if (y1==y2) answer(mid);
		if ((x1<x2)==(y1<y2))
			low=mid;
		else
			high=mid;
	}
	answer(-1);
	return 0;
}