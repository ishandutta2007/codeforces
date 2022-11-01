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
	int n;
	while (cin>>n)
	{
		int c0=0;
		unordered_map<int,int> c1,c2;
		REP(i,n)
		{
			string s;
			cin>>s;
			int d=0,m=0;
			for (char c:s)
			{
				d+=(c=='('?1:-1);
				ckmin(m,d);
			}
			if (d==0)
			{
				if (m<0) continue;
				++c0;
			}
			else if (d>0)
			{
				if (m<0) continue;
				++c1[d];
			}
			else
			{
				if (m<d) continue;
				++c2[-d];
			}
		}
		int ret=c0/2;
		for (auto w:c1) ret+=min(w.second,c2[w.first]);
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}