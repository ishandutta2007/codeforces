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

void up(ipair& ret,int d)
{
	if (ret.first<0) 
		ret=MP(d,d);
	else
	{
		ckmin(ret.first,d);
		ckmax(ret.second,d);
	}
}
ipair get_range(set<int>& p,int key,int s,int t,int b)
{
	if (b==key)
	{
		ipair ret=MP(s,t);
		if (!p.empty())
		{
			up(ret,*p.begin());
			up(ret,*(--p.end()));
		}
		return ret;
	}
	ipair ret=MP(-1,-1);
	if (!p.empty())
	{
		VI vals;
		vals.push_back(*p.begin());
		vals.push_back(*(--p.end()));
		auto it=p.upper_bound(t);
		if (it!=p.end()) vals.push_back(*it);
		it=p.lower_bound(s);
		if (it!=p.begin()) { --it; vals.push_back(*it); }
		for (int v:vals) if (v<s || v>t) up(ret,v);
	}
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		string s;
		cin>>s;
		set<int> p[2];
		REP(i,n) p[s[i]-'0'].insert(i);
		int win=0;
		int lose=1;
		REP(i,n-m+1) REP(b,2)
		{
			ipair r[2];
			REP(k,2) r[k]=get_range(p[k],k,i,i+m-1,b);
			if (r[0].first<0 || r[1].first<0) win=1;
			else if (r[0].second-r[0].first>=m && r[1].second-r[1].first>=m) lose=0;
		}
		if (win)
			printf("tokitsukaze\n");
		else if (lose)
			printf("quailty\n");
		else
			printf("once again\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}