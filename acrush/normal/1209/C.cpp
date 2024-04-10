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

string solve(string s0)
{
	REP(d,10)
	{
		int n=LENGTH(s0);
		string s=s0;
		string r=string(n,' ');
		int last1=-1;
		REP(i,n)
		{
			if (s[i]-'0'<d) r[i]='1',last1=i;
			else if (s[i]-'0'>d) r[i]='2';
		}
		REP(i,n) if (s[i]-'0'==d) r[i]=(i>last1?'1':'2');
		string g="";
		REP(i,n) if (r[i]=='1') g+=s[i];
		REP(i,n) if (r[i]=='2') g+=s[i];
		int ok=1;
		REP(i,n-1) if (g[i]>g[i+1]) ok=0;
		if (ok) return r;
	}
	return "-";
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
		string s;
		cin>>n>>s;
		string ret=solve(s);
		printf("%s\n",ret.c_str());
	}
	return 0;
}