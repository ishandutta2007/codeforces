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
using VI=vector<int64>;

int64 get_area(int a,int b,int c)
{
	printf("1 %d %d %d\n",a+1,b+1,c+1);
	fflush(stdout);
	int64 r;
	cin>>r;
	return r;
}
int get_sign(int a,int b,int c)
{
	printf("2 %d %d %d\n",a+1,b+1,c+1);
	fflush(stdout);
	int r;
	cin>>r;
	return r;
}

int main()
{
	int n;
	cin>>n;
	int p1=1;
	FOR(i,2,n) if (get_sign(0,p1,i)<0) p1=i;
	VI s(n);
	FOR(i,1,n) if (i!=p1) s[i]=get_area(0,p1,i);
	int p2=0;
	REP(i,n) if (s[i]>s[p2]) p2=i;
	vector<pair<int64,int>> q1,q2;
	FOR(i,1,n) if (i!=p1 && i!=p2)
		if (get_sign(0,p2,i)>0)
			q2.push_back(MP(-s[i],i));
		else
			q1.push_back(MP(s[i],i));
	sort(ALL(q1));
	sort(ALL(q2));
	VI ret;
	ret.push_back(0);
	ret.push_back(p1);
	for (auto x:q1) ret.push_back(x.second);
	ret.push_back(p2);
	for (auto x:q2) ret.push_back(x.second);

	printf("0");
	REP(i,n) printf(" %d",ret[i]+1);
	printf("\n");
	fflush(stdout);
	return 0;
}