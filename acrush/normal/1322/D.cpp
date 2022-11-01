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

const int SIZE=4096;
const int INF=1000000000;

int n,m;
int f[SIZE][SIZE];
int a[SIZE],cost[SIZE];
int val[SIZE];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		REP(i,n) cin>>a[i];
		REP(i,n) cin>>cost[i];
		REP(i,n+m) cin>>val[i+1];
		REP(i,SIZE) REP(j,SIZE) f[i][j]=-INF;
		REP(i,SIZE) f[i][0]=0;
		for (int i=n-1;i>=0;i--)
		{
			int w0=a[i];
			for (int c0=n;c0>=0;c0--) if (f[w0][c0]!=-INF)
			{
				int t=f[w0][c0]-cost[i];
				for (int w=w0,c=c0+1;;c/=2,++w)
				{
					if (t<=f[w][c]) break;
					f[w][c]=t;
					if (c==0) break;
					t+=val[w]*c;
				}
			}
			REP(i,SIZE-1) ckmax(f[i+1][0],f[i][0]);
		}
		printf("%d\n",f[SIZE-1][0]);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}