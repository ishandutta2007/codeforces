#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

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

int solve(VI a)
{
	sort(ALL(a));
	int sg=0;
	REP(i,SIZE(a)) sg^=(a[i]-i);
	return sg%2==1;
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
		VI a(n);
		REP(i,n) cin>>a[i];
		unordered_map<int,int> cnt;
		REP(i,n) ++cnt[a[i]];
		int key=-1;
		for (auto w:cnt) if (w.second>1) key=w.first;
		int ret=0;
		if (key<0)
			ret=solve(a);
		else if (key==0)
			ret=0;
		else
		{
			--cnt[key];
			++cnt[key-1];
			int ok=1;
			for (auto w:cnt) if (w.second>1) ok=0;
			if (ok)
			{
				VI b;
				for (auto w:cnt) REP(i,w.second) b.push_back(w.first);
				ret=!solve(b);
			}
			else
				ret=0;
		}
		if (ret)
			printf("sjfnb\n");
		else
			printf("cslnb\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}