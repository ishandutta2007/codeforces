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
	int n;
	int64 cost,delta;
	while (cin>>n>>cost>>delta)
	{
		vector<int64> a(n+1);
		vector<int> bit(n);
		REP(i,n)
		{
			int x;
			string y;
			cin>>x>>y;
			a[i]=x;
			bit[i]=(int)(y[0]=='W');
		}
		cin>>a[n];
		vector<int64> cnt[2];
		vector<int64> sa[2];
		REP(b,2) 
		{
			cnt[b]=vector<int64>(n+1);
			REP(i,n) cnt[b][i+1]=cnt[b][i]+(int)(bit[i]==b);
			sa[b]=vector<int64>(n+1);
			REP(i,n) sa[b][i+1]=sa[b][i]+(bit[i]==b?a[i]:0);
		}
		vector<int64> f(n+1);
		vector<int64> g1[2];
		vector<int64> g2[2];
		REP(b,2)
		{
			g1[b]=vector<int64>(n);
			g2[b]=vector<int64>(n);
		}
		int64 min_g1[2]={1LL<<60,1LL<<60};
		int p=0;
		list<int> que[2];
		list<int> que2[2];
		REP(i,n+1)
		{
			f[i]=delta*i;
			for (;(a[i]-a[p])*cost>delta;++p) REP(b,2) if (bit[p]!=b) ckmin(min_g1[b],g1[b][p]);
			REP(b1,2) if (i==n || bit[i]==b1)
			{
				int b2=(b1^1);
				int64 base_cost1=a[i]*cost+cnt[b1][i]*delta+cnt[b2][p]*delta+a[i]*cost*(cnt[b2][i]-cnt[b2][p])-cost*(sa[b2][i]-sa[b2][p]);
				ckmin(f[i],base_cost1+min_g1[b1]);
				int64 base_cost2=a[i]*cost+cnt[b1][i]*delta+a[i]*cost*cnt[b2][i]-cost*sa[b2][i];
				auto& q=que[b1];
				auto eval=[&](int j) { return base_cost2+g2[b1][j]-a[i]*cost*cnt[b2][j+1]; };
				while (SIZE(q)>=2)
				{
					int64 t1=eval(q.front());
					auto it=q.begin();
					++it;
					int64 t2=eval(*it);
					if (t1<t2) break;
					q.pop_front();
				}
				if (SIZE(q)>0) ckmin(f[i],eval(q.front()));
			}
			if (i<n)
			{
				REP(b1,2)
				{
					int b2=(b1^1);
					g1[b1][i]=f[i]-a[i]*cost-cnt[b1][i+1]*delta-cnt[b2][i+1]*delta;
					g2[b1][i]=f[i]-a[i]*cost-cnt[b1][i+1]*delta+cost*sa[b2][i+1];
				}
				REP(b1,2) if (b1!=bit[i]) 
				{
					int b2=(b1^1);
					auto slope=[&](int i,int j) { return (double)(g2[b1][j]-g2[b1][i])/(double)(cnt[b2][j+1]-cnt[b2][i+1]); };
					auto& q=que[b1];
					while (SIZE(q)>=2)
					{
						int last=q.back();
						auto it=q.end();
						--it; --it;
						int prev=*it;
						if (slope(prev,last)<slope(prev,i)) break;
						q.pop_back();
					}
					q.push_back(i);
					que2[b1].push_back(i);
				}
			}
		}
		cout<<f[n]<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}