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
	int64 length;
	int nq;
	cin>>length>>nq;
	list<pair<int64,int64>> que;
	que.push_back(MP(0,0));
	int64 delta=0;
	int64 slope=0;
	auto f=[](const pair<int64,int64>& a,const pair<int64,int64>& b)
	{
		return (double)(a.second-b.second)/(double)(b.first-a.first);
	};
	REP(i,nq)
	{
		int tp;
		cin>>tp;
		if (tp==1)
		{
			int l;
			cin>>l;
			length+=l;
			que.clear();
			delta=slope=0;
			que.push_front(MP(0,0));
		}
		else if (tp==2)
		{
			int l;
			cin>>l;
			pair<int64,int64> w=MP(length,-(length*slope+delta));
			length+=l;
			while (que.size()>=2)
			{
				auto x=*(++que.rbegin());
				auto y=que.back();
				if (f(x,y)>f(y,w)) break;
				que.pop_back();
			}
			que.push_back(w);
		}
		else
		{
			int b,s;
			cin>>b>>s;
			slope+=s;
			delta+=b;
		}
		while (que.size()>=2)
		{
			auto x=*(++que.rbegin());
			auto y=que.back();
			int64 wx=slope*x.first+x.second;
			int64 wy=slope*y.first+y.second;
			if (wx>wy) break;
			que.pop_back();
		}
		/*
		vector<pair<int64,int64>> ss(ALL(que));
		REP(i,SIZE(ss)) printf("%lld %lld  ",ss[i].first,ss[i].second); printf("\n");
		REP(i,SIZE(ss)-1) printf("%.3lf  ",f(ss[i],ss[i+1])); printf("\n");
		*/
		auto w=que.back();
		printf("%lld %lld\n",w.first+1,slope*w.first+w.second+delta);
	}
	return 0;
}