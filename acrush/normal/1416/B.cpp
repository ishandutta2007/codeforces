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
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;

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
		vector<int64> a(n);
		REP(i,n) cin>>a[i];
		int64 s=0;
		REP(i,n) s+=a[i];
		if (s%n!=0)
		{
			printf("-1\n");
			continue;
		}		
		vector<VI> ret;
		auto op=[&](int i,int j,int x) {
			ret.push_back({i+1,j+1,x});
			int64 d=(int64)(i+1)*x;
			a[i]-=d;
			a[j]+=d;
		};
		int64 avg=s/n;
		FOR(i,1,n) 
		{
			if (a[i]%(i+1)!=0) op(0,i,(i+1)-a[i]%(i+1));
			op(i,0,a[i]/(i+1));
		}
		FOR(i,1,n) op(0,i,avg);
		REP(i,n) assert(a[i]==avg);
		printf("%d\n",SIZE(ret));
		for (const auto& x:ret) printf("%d %d %d\n",x[0],x[1],x[2]);
	}
	return 0;
}