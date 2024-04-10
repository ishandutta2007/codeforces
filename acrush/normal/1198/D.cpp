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

int a[64][64];
int f[64][64][64][64];

int solve(int x1,int y1,int x2,int y2)
{
	int& ret=f[x1][y1][x2][y2];
	if (ret>=0) return ret;
	if (x1==x2 && y1==y2) return ret=a[x1][y1];
	ret=max(x2-x1+1,y2-y1+1);
	FOR(x0,x1,x2) ckmin(ret,solve(x1,y1,x0,y2)+solve(x0+1,y1,x2,y2));
	FOR(y0,y1,y2) ckmin(ret,solve(x1,y1,x2,y0)+solve(x1,y0+1,x2,y2));
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		REP(i,n)
		{
			string s;
			cin>>s;
			REP(j,n) a[i][j]=(int)(s[j]=='#');
		}
		memset(f,255,sizeof(f));
		int ret=solve(0,0,n-1,n-1);
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}