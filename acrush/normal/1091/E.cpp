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

bool ck(vector<int> a,int key)
{
	a.push_back(key);	
	for (int p=SIZE(a)-1;p>0 && a[p-1]>a[p];--p) swap(a[p],a[p-1]);
	int n=SIZE(a);
	vector<int64> s(n+1);
	s[0]=0;
	REP(i,n) s[i+1]=s[i]+a[i];
	for (int64 p=0,i=n-1;i>=0;i--)
	{
		int64 k=n-i;
		for (;p<i && a[p]<=k;++p);
		ckmin(p,i);
		if ((s[n]-s[i])-(s[p]+(i-p)*k)>k*(k-1)) return false;
	}
	return true;
}

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
		sort(ALL(a));
		vector<int64> s(n+1);
		s[0]=0;
		REP(i,n) s[i+1]=s[i]+a[i];
		int64 last=n;
		for (int p=0,i=n;i>=0;i--)
		{
			int64 k=n-i+1;
			for (;p<i && a[p]<k;++p);
			ckmin(p,i);
			int64 s0=s[p]+(i-p)*k;
			int64 s1=s[n]-s[i];
			ckmin(last,k*(k-1)+s0-s1);
		}
		if ((s[n]+last)%2) --last;
		if (last<0 || !ck(a,last))
			printf("-1\n");
		else
		{
			int low=last%2-2;
			int high=last;
			for (;low+2<high;)
			{
				int mid=(low+high)/2;
				if ((low+mid)%2) ++mid;
				if (ck(a,mid))
					high=mid;
				else
					low=mid;
			}
			for (int i=high;i<=last;i+=2)
				printf("%d ",i);
			printf("\n");
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}