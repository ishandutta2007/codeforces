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

const int maxsize=(1<<20);

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int64 S1(int64 n)
{
	return n*(n+1)/2;
}
int64 solve(int64 n,int64 m)
{
	if (n<m) return 0;
	return S1(n/m-1)*m+(n%m+1)*(n/m);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int m,a,b;
	while (cin>>m>>a>>b)
	{
		int64 ret=1;
		int sizeq=0;
		vector<int> q;
		vector<int> f(maxsize);
		q.push_back(0);
		f[0]=1;
		for (int size=1;size<=m;size++)
		{
			if (size==maxsize)
			{
				int d=gcd(a,b);
				ret+=solve(m,d)-solve(size-1,d)+(m-size+1);
				break;
			}
			if (size-a>=0 && f[size-a])
			{
				f[size]=1;
				q.push_back(size);
				FOR(cl,SIZE(q)-1,SIZE(q))
				{
					int x=q[cl];
					if (x>=b && !f[x-b]) f[x-b]=1,q.push_back(x-b);
					if (x+a<=size && !f[x+a]) f[x+a]=1,q.push_back(x+a);
				}
			}
			ret+=SIZE(q);
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}