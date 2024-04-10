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

unordered_map<int,int> w;

int query(int x)
{
	if (w.count(x)) return w[x];
	printf("? %d\n",x); fflush(stdout);
	int v; cin>>v;
	return w[x]=v;
}

int main()
{
	int n;
	cin>>n;
	int s=0;
	int t=n+1;
	while (t-s>2)
	{
		int m1=(s+t)/2;
		int m2=m1+1;
		int v1=query(m1);
		int v2=query(m2);
		if (v1>v2)
			s=m1;
		else
			t=m2;
	}
	printf("! %d\n",s+1); fflush(stdout);
	return 0;
}