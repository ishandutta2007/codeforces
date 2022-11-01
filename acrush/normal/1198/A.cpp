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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int length,m;
	while (cin>>length>>m)
	{
		map<int,int> c;
		REP(i,length) { int p; cin>>p; ++c[p]; }
		VI a;
		for (auto w:c) a.push_back(w.first);
		int n=SIZE(a);
		int d=(1<<min(30,m*8/length));
		VI sc;
		int s=0;
		for (auto w:c) { sc.push_back(s); s+=w.second; }
		sc.push_back(s);
		int ret=length;
		REP(i,n) 
		{
			ckmin(ret,sc[i]+sc[n]-sc[min(n,i+d)]);
		}
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}