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

bool solve(int64 m,int64 n,int64 a,int64 b,int64 k)
{
	int64 ca=(n+1)/2;
	int64 cb=n-ca;
	if (a>b) { swap(a,b); swap(ca,cb); }
	if (m<=a) return ca+cb>=k;
	if (m<=b) return a*ca/m+cb>=k;
	return (a*ca+b*cb)/m>=k;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int64 t,n,a,b,k;
	while (cin>>t>>n>>a>>b>>k)
	{
		int64 low=0,high=t+1;
		for (;low+1<high;)
		{
			int64 mid=(low+high)/2;
			if (solve(mid,n,a,b,k))
				low=mid;
			else
				high=mid;
		}
		cout<<low<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}