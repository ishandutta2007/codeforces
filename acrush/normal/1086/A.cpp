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
	int sx[3],sy[3];
	while (cin>>sx[0]>>sy[0]>>sx[1]>>sy[1]>>sx[2]>>sy[2])
	{
		int px[3],py[3];
		REP(i,3) px[i]=sx[i],py[i]=sy[i];
		sort(px,px+3);
		sort(py,py+3);
		int x0=px[1],y0=py[1];
		set<ipair> ret;
		REP(i,3)
		{
			int x=sx[i],y=sy[i];
			for (;x<x0;x++) ret.insert(MP(x,y));
			for (;x>x0;x--) ret.insert(MP(x,y));
			for (;y<y0;y++) ret.insert(MP(x,y));
			for (;y>y0;y--) ret.insert(MP(x,y));
		}
		ret.insert(MP(x0,y0));
		printf("%d\n",SIZE(ret));
		for (auto w:ret) printf("%d %d\n",w.first,w.second);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}