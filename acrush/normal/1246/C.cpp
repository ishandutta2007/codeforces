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
using VS=vector<string>;

const int MOD=1000000007;

inline int ADD(int a, int b) { return (a + b >= MOD) ? (a + b - MOD) : (a + b); }
inline void ADDTO(int& a,int b) { a = ((a + b >= MOD) ? (a + b - MOD) : (a + b)); }
inline int SUB(int a, int b) { return (a >= b) ? (a - b) : (a - b + MOD); }
inline void SUBTO(int& a,int b) { a = ((a >= b) ? (a - b) : (a - b + MOD)); }
inline int MUL(int a, int b) { return (int64)a * b % MOD; }


int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int sx,sy;
	while (cin>>sx>>sy)
	{
		VS a(sx);
		REP(x,sx) cin>>a[x];
		vector<VI> d_right(sx,VI(sy));
		vector<VI> d_down(sx,VI(sy));
		for (int x=sx-1;x>=0;x--) for (int y=sy-1;y>=0;y--)
		{
			if (y+1<sy) d_right[x][y]=d_right[x][y+1]+(int)(a[x][y+1]=='.');
			if (x+1<sx) d_down[x][y]=d_down[x+1][y]+(int)(a[x+1][y]=='.');
		}
		vector<VI> f_next_to_right(sx,VI(sy));
		vector<VI> f_next_to_down(sx,VI(sy));
		f_next_to_right[0][0]=f_next_to_down[0][0]=1;
		if (sx>1) SUBTO(f_next_to_right[1][0],1);
		if (sy>1) SUBTO(f_next_to_down[0][1],1);
		REP(x,sx) REP(y,sy)
		{
			if (x>0) ADDTO(f_next_to_right[x][y],f_next_to_right[x-1][y]);
			if (y>0) ADDTO(f_next_to_down[x][y],f_next_to_down[x][y-1]);
			// printf("%d %d %d %d\n",x,y,f_next_to_right[x][y],f_next_to_down[x][y]);
			if (d_right[x][y]>0)
			{
				ADDTO(f_next_to_down[x][y+1],f_next_to_right[x][y]);
				int t=y+d_right[x][y]+1;
				if (t<sy) SUBTO(f_next_to_down[x][t],f_next_to_right[x][y]);
			}
			if (d_down[x][y]>0)
			{
				ADDTO(f_next_to_right[x+1][y],f_next_to_down[x][y]);
				int t=x+d_down[x][y]+1;
				if (t<sx) SUBTO(f_next_to_right[t][y],f_next_to_down[x][y]);
			}
			// FOR(i,1,d_right[x][y]+1) ADDTO(f_next_to_down[x][y+i],f_next_to_right[x][y]);
			// FOR(i,1,d_down[x][y]+1) ADDTO(f_next_to_right[x+i][y],f_next_to_down[x][y]);
		}
		int ret=ADD(f_next_to_right[sx-1][sy-1],f_next_to_down[sx-1][sy-1]);
		if (sx==1 && sy==1) ret=1;
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}