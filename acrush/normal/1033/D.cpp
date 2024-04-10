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

const int64 MOD=998244353;

int64 gcd(int64 a,int64 b)
{
	return (b==0)?a:gcd(b,a%b);
}

int64 calc(int64 p,int e,int64 m)
{
	int64 r=1;
	REP(i,e)
	{
		if (r>m/p) return m+1;
		r*=p;
	}
	return r;
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
		vector<int64> a(n);
		unordered_map<int64,int> c;
		REP(i,n) cin>>a[i];
		unordered_map<int64,int> z;
		REP(i,n)
		{
			int64 m=a[i];
			bool ok=false;
			for (int e=4;e>=2;e--)
			{
				int64 low=0,high=m+1;
				for (;low+1<high;)
				{
					int64 mid=(low+high)/2;
					if (calc(mid,e,m)<=m)
						low=mid;
					else
						high=mid;
				}
				int64 p=low;
				if (calc(p,e,m)==m)
				{
					c[p]+=e;
					ok=true;
					break;
				}
			}
			if (!ok)
			{
				int64 f=-1;
				REP(j,SIZE(a))
				{
					int64 d=gcd(m,a[j]);
					if (d>1 && d<m && m%d==0)
					{
						f=d;
						break;
					}
				}
				if (f<0)
				{
					++z[m];
				}
				else
				{
					++c[f];
					++c[m/f];
				}
			}
		}
		int64 r=1;
		for (auto w:z) 
		{
			r=(r*(w.second+1))%MOD;
			r=(r*(w.second+1))%MOD;
		}
		for (auto w:c) 
			r=(r*(w.second+1))%MOD;
		cout<<r<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}