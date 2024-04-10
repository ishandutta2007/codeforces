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

const int maxn=512;

int n;
int64 target;
int64 a[maxn];

int64 solve(int64 s,int64 t)
{
	if (s>t) return 0;
	int64 e=0;
	REP(i,n) e+=(a[i]+s-1)/s;
	if (e>target/s) return 0;
	return min(t,target/e);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n>>target)
	{
		REP(i,n) cin>>a[i];
		REP(i,n) target+=a[i];
		set<int64> w;
		const int D=100000;
		w.insert(D);
		REP(i,n) for (int k=1;;k++) 
		{
			int t=(a[i]+k-1)/k;
			if (t<D) break;
			w.insert(t);
		}
		vector<int64> pts(w.begin(),w.end());
		pts.push_back(1LL<<60);
		int64 ret=0;
		FOR(k,1,D+1) ckmax(ret,solve(k,k));
		REP(i,SIZE(pts)-1) ckmax(ret,solve(pts[i],pts[i+1]-1));
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif

	}
	return 0;
}