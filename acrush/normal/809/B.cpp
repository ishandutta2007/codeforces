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

int n,k;

char query(int a,int b)
{
	printf("1 %d %d\n",a,b);
	fflush(stdout);
	char str[20];
	scanf("%s",str);
	return str[0];
}
int find(int low,int high)
{
	while (low<high)
	{
		int mid=(low+high)/2;
		if (query(mid,mid+1)=='T')
			high=mid;
		else
			low=mid+1;
	}
	return low;
}
int main()
{
#ifdef _MSC_VER
	//freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n>>k;
	int p1=find(1,n);
	if (p1>1)
	{
		int p2=find(1,p1-1);
		if (query(p1,p2)=='T' && query(p2,p1)=='T')
		{
			printf("2 %d %d\n",p1,p2);
			return 0;
		}
	}
	if (p1<n)
	{
		int p2=find(p1+1,n);
		if (query(p1,p2)=='T' && query(p2,p1)=='T')
		{
			printf("2 %d %d\n",p1,p2);
			return 0;
		}
	}
	return 0;
}