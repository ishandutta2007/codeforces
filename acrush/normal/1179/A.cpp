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
	int n,m;
	while (cin>>n>>m)
	{
		VI a(n);
		REP(i,n) cin>>a[i];
		vector<pair<int64,int>> q(m);
		vector<ipair> r(m);
		REP(i,m) { cin>>q[i].first; q[i].second=i; }
		sort(ALL(q));
		int at=0;
		int w=*max_element(ALL(a));
		deque<int> b;
		REP(i,n) b.push_back(a[i]);
		int t=0;
		while (b.front()!=w)
		{
			++t;
			int x=b.front();
			b.pop_front();
			int y=b.front();
			b.pop_front();
			for (;at<m && q[at].first==t;++at)
				r[q[at].second]=MP(x,y);
			if (x<y) swap(x,y);
			b.push_front(x);
			b.push_back(y);
		}
		a.clear();
		while (!b.empty()) { a.push_back(b.front()); b.pop_front(); }
		for (;at<m;at++)
		{
			int p=1+(q[at].first-t-1)%(n-1);
			r[q[at].second]=MP(a[0],a[p]);
		}
		REP(i,m) printf("%d %d\n",r[i].first,r[i].second);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}