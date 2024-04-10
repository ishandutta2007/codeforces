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

int64 solve(vector<int64> a,vector<int64> b)
{
	int n=SIZE(a);
	int m=SIZE(b);
	sort(ALL(a));
	sort(ALL(b));
	if (a[n-1]>b[0]) return -1;
	int64 ret=0;
	if (a[n-1]==b[0])
	{
		REP(i,n-1) ret+=a[i]*m;
		REP(i,m) ret+=b[i];
		return ret;
	}
	REP(i,n-2) ret+=a[i]*m;
	ret+=(m-1)*a[n-2];
	ret+=a[n-1];
	REP(i,m) ret+=b[i];
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
		vector<int64> a(n);
		vector<int64> b(m);
		REP(i,n) cin>>a[i];
		REP(i,m) cin>>b[i];
		int64 ret=solve(a,b);
		cout<<ret<<endl;
	}
	return 0;
}