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
	int n,nq;
	while (cin>>n>>nq)
	{
		unordered_map<int,set<int>> p;
		REP(i,n)
		{
			int v;
			cin>>v;
			p[v].insert(i);
		}
		struct Data
		{
			int s,t,c;
		};
		vector<Data> a;
		for (const auto& w:p) a.push_back({*w.second.begin(),*(--w.second.end()),SIZE(w.second)});
		sort(ALL(a),[](const Data& x,const Data& y) { return x.s<y.s; });
		vector<Data> b;
		for (auto w:a)
			if (SIZE(b)==0 || w.s>b.back().t)
				b.push_back(w);
			else
			{
				auto& z=b.back();
				ckmax(z.t,w.t);
				ckmax(z.c,w.c);
			}
		int ret=n;
		for (auto w:b) ret-=w.c;
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}