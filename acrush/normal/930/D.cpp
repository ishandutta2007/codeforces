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

const int maxn=1000000+16;

int n;
int x[maxn],y[maxn];
multiset<int> m1,m2;

int64 solve(int odd)
{
	m1.clear();
	m2.clear();
	vector<ipair> a;
	REP(i,n) if (abs(x[i]+y[i])%2==odd) a.emplace_back((x[i]+y[i]+odd)/2,(x[i]-y[i]+odd)/2);
	sort(ALL(a));
	if (SIZE(a)==0) return 0;
	int p1=0,p2=0;
	REP(i,SIZE(a)) m2.insert(a[i].second);
	int64 ret=0;
	for (int x0=a.front().first;x0<a.back().first;++x0)
	{
		for (;p1<SIZE(a) && a[p1].first<=x0;++p1) m1.insert(a[p1].second);
		for (;p2<SIZE(a) && a[p2].first<=x0;++p2) m2.erase(m2.find(a[p2].second));
		if (m1.empty() || m2.empty()) continue;
		int s1=*m1.begin();
		int t1=*(--m1.end())-1;
		int s2=*m2.begin();
		int t2=*(--m2.end())-1;
		if (s1<=t2 && s2<=t1) 
		{
			int s=max(s1,s2);
			int t=min(t1,t2);
			ret+=t-s+1;
		}
	}
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n)
	{
		REP(i,n) cin>>x[i]>>y[i];
		int64 ret=solve(0)+solve(1);
		cout<<ret<<endl;
	}
	return 0;
}