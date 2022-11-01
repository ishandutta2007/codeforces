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
	int n;
	while (cin>>n)
	{
		double start_time=(double)clock();
		double time_limit=start_time+2.3*CLOCKS_PER_SEC;
		vector<int64> a(n);
		REP(i,n) cin>>a[i];
		int64 ret=(1LL<<60);

		unordered_set<int64> visited2;
		VI visited1(1<<20);
		auto update=[&](int64 m)
		{
			if (m<=1) return;
			if (m<(1<<20))
			{
				if (visited1[m]) return;
				visited1[m]=1;
			}
			else
			{
				if (visited2.count(m)) return;
				visited2.insert(m);
			}
			int64 s=0;
			for (int64 x:a)
			{
				if (x<=m)
					s+=(m-x);
				else
				{
					int64 t=x%m;
					s+=min(t,m-t);
				}
				if (s>=ret) break;
			}
			ckmin(ret,s);
		};

		for (int k=2;k<=20;k++) update(k);
		REP(i,n) swap(a[i],a[i+rand()%(n-i)]);
		unordered_set<int64> explored;		
		for (int64 y:a)
		{
			if ((double)clock()>time_limit) break;
			for (int delta=-1;delta<=1;delta++)
			{
				if ((double)clock()>time_limit) break;
				int64 x=y+delta;
				if (x<1) continue;
				if (explored.count(x)) continue;
				explored.insert(x);
				for (int64 p=2;x>1;)
				{
					if (x%p==0)
					{
						update(p);
						if ((double)clock()>time_limit) break;
						for (;x%p==0;x/=p);
					}
					++p;
					if (p*p>x) p=x;
				}
			}
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}