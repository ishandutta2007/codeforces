#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int64,int64>;
using VI=vector<int64>;
using VD=vector<double>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		vector<ipair> a;
		REP(i,n)
		{
			int64 d;
			cin>>d;
			while (1)
			{
				if (a.empty()) { a.push_back({d,d}); break; }
				int64 s=a.back().first;
				int64 t=a.back().second;
				if (d<=t) { a.push_back({d,d}); break; }
				if (d==t+1) { a.back().second++; break; }
				int64 c=t-s+1;
				int64 x=(d-t-1)/(c+1);
				if (x>0 && (SIZE(a)==1 || a[SIZE(a)-2].second>=s+x))
				{
					a.back().first+=x;
					a.back().second+=x;
					d-=x*c;
					continue;
				}
				if (x>0)
				{
					assert(SIZE(a)>=2);
					x=a[SIZE(a)-2].second+1-s;
					d-=x*c;
					a[SIZE(a)-2].second=t+x;
					a.pop_back();
					continue;
				}
				int64 c1=d-(t+1);
				int64 c2=c-c1;
				assert(c1>0);
				a.back().first++;
				int64 t1=a.back().first+c1-1;
				a.back().second=t1;
				if (SIZE(a)>=2 && a[SIZE(a)-2].second+1==a.back().first)
				{
					a[SIZE(a)-2].second=a.back().second;
					a.pop_back();
				}
				a.push_back({t1,t1+c2});
				break;
			}
		}
		for (ipair w:a) for (int64 x=w.first;x<=w.second;++x) printf("%lld ",x);
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}