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
	int n,m;
	while (cin>>n>>m)
	{
		vector<int> f(n);
		vector<int> a(n);
		vector<int> p(n);
		REP(i,n) { cin>>a[i]; --a[i]; }
		REP(i,n) p[a[i]]=i;
		REP(i,n) f[a[i]]=n-p[a[i]];
		REP(step,m-1)
		{
			vector<int> b(n);
			vector<int> l(n);
			REP(i,n) { cin>>b[i]; --b[i]; }
			for (int i=n-1;i>=0;i--)
			{
				int j=p[b[i]];
				if (i+1<n && j+1<n && b[i+1]==a[j+1]) 
					l[b[i]]=1+l[b[i+1]];
				else
					l[b[i]]=1;
			}
			REP(i,n) ckmin(f[i],l[i]);
		}
		int64 ret=0;
		REP(i,n) ret+=f[i];
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}