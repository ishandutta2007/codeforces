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

vector<ipair> solve(int n,int m)
{
	int s=0,t=n-1;
	vector<ipair> ret;
	while (s<=t)
	{
		if (s==t)
		{
			int low=0,high=m-1;
			for (int step=0;low<=high;++step)
				if (step%2==0)
					ret.emplace_back(s,low++);
				else
					ret.emplace_back(s,high--);
			break;
		}
		REP(i,m)
		{
			ret.emplace_back(s,i);
			ret.emplace_back(t,m-1-i);
		}
		++s;
		--t;
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
		auto ret=solve(n,m);
		for (auto w:ret) printf("%d %d\n",w.first+1,w.second+1);
#ifdef _MSC_VER
		printf("\n");
#else
		break;
#endif
	}
	return 0;
}