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
using VI=vector<int>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		vector<VI> a(n);
		REP(i,n) a[i]=VI(m);
		REP(i,n) REP(j,m) cin>>a[i][j];
		vector<ipair> b;
		vector<VI> s1=a,s2=a;
		VI e1(n),e2(m);
		REP(i,n) 
		{
			b.clear();
			REP(j,m) b.emplace_back(a[i][j],j);
			sort(ALL(b));
			int c=0;
			REP(j,m)
			{
				s1[i][b[j].second]=c;
				if (j+1<m && b[j].first<b[j+1].first) ++c;
			}
			e1[i]=c;
		}
		REP(j,m)
		{
			b.clear();
			REP(i,n) b.emplace_back(a[i][j],i);
			sort(ALL(b));
			int c=0;
			REP(i,n)
			{
				s2[b[i].second][j]=c;
				if (i+1<n && b[i].first<b[i+1].first) ++c;
			}
			e2[j]=c;
		}
		REP(i,n)
		{
			REP(j,m)
			{
				if (j>0) printf(" ");
				int r=max(s1[i][j],s2[i][j])+max(e1[i]-s1[i][j],e2[j]-s2[i][j])+1;
				printf("%d",r);
			}
			printf("\n");
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}