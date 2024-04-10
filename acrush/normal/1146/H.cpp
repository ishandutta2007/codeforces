#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

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

const int maxn=300+10;

int n;
int x[maxn],y[maxn];
int dir[maxn][maxn][maxn];
int64 f1[maxn][maxn][4];
int64 f2[maxn][maxn][4];

int outer(int a,int b,int c)
{
	int64 t=(int64)(x[b]-x[a])*(y[c]-y[a])-(int64)(x[c]-x[a])*(y[b]-y[a]);
	if (t==0) return 0;
	return (t<0)?-1:1;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n)
	{
		REP(i,n) cin>>x[i]>>y[i];
		REP(i,n) FOR(j,i+1,n) if (x[j]<x[i] || x[j]==x[i] && y[j]<y[i]) { swap(x[i],x[j]); swap(y[i],y[j]); }
		REP(i,n) REP(j,n) REP(k,n) dir[i][j][k]=outer(i,j,k);
		int64 ret=0;
		vector<vector<int>> prev(n);
		vector<vector<int>> next(n);
		REP(i,n) 
		{
			REP(j,i) prev[i].push_back(j);
			FOR(j,i+1,n) next[i].push_back(j);
			sort(ALL(prev[i]),[&](int a,int b) { return dir[i][a][b]>0; });
			sort(ALL(next[i]),[&](int a,int b) { return dir[i][a][b]>0; });
		}
		REP(src,n)
		{
			memset(f1,0,sizeof(f1));
			memset(f2,0,sizeof(f2));
			FOR(i,src+1,n)
			{
				f1[src][i][0]=1;
				f2[src][i][0]=1;
				auto& a=prev[i];
				auto& b=next[i];
				int64 s1[4],s2[4];
				memset(s1,0,sizeof(s1));
				memset(s2,0,sizeof(s2));
				REP(pa,SIZE(a)) REP(c,3) s2[c]+=f2[a[pa]][i][c];
				for (int pb=0,pa=0;pb<SIZE(b);pb++)
				{
					for (;pa<SIZE(a) && dir[a[pa]][i][b[pb]]>0;++pa) 
					{
						REP(c,3) s1[c]+=f1[a[pa]][i][c];
						REP(c,3) s2[c]-=f2[a[pa]][i][c];
					}
					REP(c,3) f1[i][b[pb]][c+1]+=s1[c];
					REP(c,3) f2[i][b[pb]][c+1]+=s2[c];
				}
				memset(s1,0,sizeof(s1));
				memset(s2,0,sizeof(s2));
				FOR(j,src,i) REP(c,4) 
				{
					s1[c]+=f1[j][i][c];
					s2[c]+=f2[j][i][c];
				}
				REP(c1,4) REP(c2,4) if (c1+c2==3) ret+=s1[c1]*s2[c2];
			}
			FOR(i,src+1,n)
			{
				int k=0;
				for (;k<SIZE(prev[i]) && prev[i][k]!=src;++k);
				if (k>=SIZE(prev[i])) continue;
				FOR(j,k,SIZE(prev[i])-1) prev[i][j]=prev[i][j+1];
				prev[i].pop_back();
			}
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}