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

const int maxn=(1<<20);

int n;
int a[maxn];
int s[maxn];
int c[maxn];

int countbit(int64 n)
{
	int r=0;
	for (;n;n&=(n-1)) ++r;
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
		REP(i,n)
		{
			int64 s;
			cin>>s;
			a[i]=countbit(s);
		}
		s[0]=0;
		c[0]=0;
		REP(i,n) s[i+1]=s[i]+a[i],c[i+1]=c[i]+s[i]%2;
		int64 ret=0;
		REP(i,n)
		{
			int k=i,m=0;
			for (;k>=0 && i-k<=150;--k)
			{
				m=max(m,a[k]);
				int w=s[i+1]-s[k];
				if (w%2==0 && m*2<=w) ++ret;
			}
			if (k>=0) ret+=((s[i+1]%2==1)?c[k+1]:(k+1)-c[k+1]);
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}