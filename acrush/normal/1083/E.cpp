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

vector<int64> x,y,a,f;

inline int64 eval(int j,int i) { return f[j]+a[i]-y[i]*x[j]; }

void solve2(int s1,int t1,int s2,int t2)
{
	assert(s1<=t1);
	if (s2>t2) return;
	int m=(s2+t2)/2;
	int p=s1;
	int64 w=-1;
	for (int k=s1;k<=t1;k++)
	{
		int64 z=eval(k,m);
		if (z>w) w=z,p=k;
	}
	ckmax(f[m],w);
	solve2(s1,p,s2,m-1);
	solve2(p,t1,m+1,t2);
}
void solve(int s,int t)
{
	if (s>=t) return;
	int m=(s+t)/2;
	solve(s,m);
	solve2(s,m,m+1,t);
	solve(m+1,t);
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
		vector<pair<pair<int64,int64>,int64>> s(n);
		REP(i,n) 
		{
			int x1,x2;
			char s3[128];
			cin>>x1>>x2>>s3;
			int64 x3=atoll(s3);
			s[i]=MP(MP((int64)x1,(int64)x2),x3);
		}
		sort(ALL(s));
		x.resize(n);
		y.resize(n);
		a.resize(n);
		REP(i,n) x[i]=s[i].first.first,y[i]=s[i].first.second,a[i]=s[i].second;
		REP(i,n) a[i]=x[i]*y[i]-a[i];
		f.resize(n);
		REP(i,n) f[i]=a[i];
		solve(0,n-1);
		int64 ret=0;
		REP(i,n) ckmax(ret,f[i]);
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}