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

string solve(int n)
{
	FOR(cd,1,n) FOR(d1,1,10) FOR(d2,1,10) if (d1!=d2)
	{
		int m1=0,m2=0;
		REP(i,n)
		{
			int t=((i<cd)?d1:d2);
			m1=(m1*10+t)%d1;
			m2=(m2*10+t)%d2;
		}
		if (m1!=0 && m2!=0) return string(cd,'0'+d1)+string(n-cd,'0'+d2);
	}
	return "-1";
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int n;
		cin>>n;
		if (n==1)
			printf("-1\n");
		else
			printf("%s\n",solve(n).c_str());
	}
	return 0;
}