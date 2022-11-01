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
	const int maxsize=200000;
	VI is_prime(maxsize,1);
	VI prev(maxsize);
	for (int i=2;i<maxsize;i++) if (is_prime[i])
		for (int j=i;j<maxsize;j+=i)
			is_prime[j]=0,prev[j]=i;
	int n,m;
	while (cin>>n>>m)
	{
		int64 ret=0;
		unordered_map<int64,int> cnt;
		REP(step,n) 
		{
			int v;
			cin>>v;
			int64 w=1,d=1;
			while (v>1)
			{
				int p=prev[v];
				int e=0;
				for (;v%p==0;v/=p) ++e;
				e%=m;
				if (e!=0)
				{
					REP(i,e) d*=p;
					REP(i,m-e) { if (w>100000) break; w*=p; }
				}
			}
			ret+=cnt[w];
			++cnt[d];
		}
		printf("%lld\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}