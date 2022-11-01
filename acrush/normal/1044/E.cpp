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

const int maxsize=1024;

int n,m;
int a[maxsize][maxsize];
int saved_a[maxsize][maxsize];
vector<vector<int>> ret;
int x[maxsize],y[maxsize];
bool c[maxsize][maxsize];

void show()
{
	REP(i,n) REP(j,m)
	{
		printf("%3d ",a[i][j]);
		if (j==m-1) printf("\n");
	}
	printf("\n");
}
int ID(int x,int y) 
{
	return x*m+y;
}
int get_dist(int id1,int id2)
{
	return abs(id1/m-id2/m)+abs(id1%m-id2%m);
}
void apply(vector<int> p);
void solve(int x0,int y0)
{
	int idx=ID(x0,y0);
	int src=-1;
	REP(x,n) REP(y,m) if (a[x][y]==idx) src=ID(x,y);
	assert(src>=0);
	int current_dist=get_dist(idx,src);
	for (int dx=-1;dx<=0;dx++) for (int dy=-1;dy<=0;dy++) REP(b,2)
	{
		int x=src/m+dx;
		int y=src%m+dy;
		if (x<0 || x>=n-1 || y<0 || y>=m-1) continue;
		vector<int> p;
		p.push_back(ID(x,y));
		p.push_back(ID(x,y+1));
		p.push_back(ID(x+1,y+1));
		p.push_back(ID(x+1,y));
		if (b) reverse(ALL(p));
		bool ok=true;
		for (int x:p) if (c[x/m][x%m]) ok=false;
		if (!ok) continue;
		int next=-1;
		REP(i,SIZE(p)) if (p[i]==src) next=p[(i+1)%SIZE(p)];
		if (next<0) continue;
		if (get_dist(idx,next)<current_dist)
		{
			REP(i,SIZE(p)) p[i]=a[p[i]/m][p[i]%m];
			apply(p);
			return;
		}
	}
	int sx=src/m,sy=src%m;
	if (sy==m-1)
	{
		//show();
		apply({a[sx][sy],a[sx+1][sy],a[sx+1][sy-1],a[sx][sy-1]});
		//show();
		REP(i,2) apply({a[sx-1][sy],a[sx][sy],a[sx+1][sy],a[sx+1][sy-1],a[sx][sy-1],a[sx-1][sy-1]});		
		//show();
		REP(i,2) apply({a[sx-1][sy-1],a[sx-1][sy],a[sx][sy],a[sx][sy-1]});
		//show();
		return;
	}
	if (sx==n-1)
	{
		//show();
		apply({a[sx][sy],a[sx][sy+1],a[sx-1][sy+1],a[sx-1][sy]});
		//show();
		REP(i,2) apply({a[sx][sy-1],a[sx][sy],a[sx][sy+1],a[sx-1][sy+1],a[sx-1][sy],a[sx-1][sy-1]});		
		//show();
		REP(i,2) apply({a[sx-1][sy-1],a[sx-1][sy],a[sx][sy],a[sx][sy-1]});
		//show();
		return;
	}
	printf("idx = %d   %d %d\n",idx,idx/m,idx%m);
	show();
	printf("dist = %d\n",current_dist);
	assert(0);
}
bool solve()
{
	REP(x,n-2) REP(y,m) if (!c[x][y])
	{
		if (a[x][y]!=ID(x,y)) solve(x,y);
		if (a[x][y]==ID(x,y)) c[x][y]=true;
		return true;
	}
	REP(y,m) REP(x,n) if (!c[x][y])
	{
		if (x>=n-2 && y>=m-2 && (x==n-1 || y==m-1)) return false;
		if (a[x][y]!=ID(x,y)) solve(x,y);
		if (a[x][y]==ID(x,y)) c[x][y]=true;
		return true;
	}
	return false;
}
void apply(vector<int> p)
{
	ret.push_back(p);
	REP(i,n) REP(j,m) x[a[i][j]]=i,y[a[i][j]]=j;
	int c=SIZE(p);
	REP(i,c) assert(abs(x[p[i]]-x[p[(i+1)%c]])+abs(y[p[i]]-y[p[(i+1)%c]])==1);
	REP(i,c) a[x[p[(i+1)%c]]][y[p[(i+1)%c]]]=p[i];
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n>>m)
	// REP(seed,1000000)
	{
		REP(i,n) REP(j,m) { cin>>a[i][j]; --a[i][j]; }
		/*
		n=3;//rand()%10+3;
		m=3;//rand()%10+3;
		printf("seed = %d   n = %d  m = %d\n",seed,n,m);
		REP(i,n) REP(j,m) a[i][j]=ID(i,j);
		REP(i,n*m) { int j=rand()%(n*m-i)+i; swap(a[i/m][i%m],a[j/m][j%m]); }
		// show();
		*/
		REP(i,n) REP(j,m) saved_a[i][j]=a[i][j];
		while (1)
		{
			REP(i,n) REP(j,m) a[i][j]=saved_a[i][j];
			REP(i,n) REP(j,m) c[i][j]=false;
			ret.clear();
			REP(i,1000)
			{
				int x=rand()%(n-1);
				int y=rand()%(m-1);
				vector<int> p;
				p.push_back(a[x][y]);
				p.push_back(a[x][y+1]);
				p.push_back(a[x+1][y+1]);
				p.push_back(a[x+1][y]);
				apply(p);
			}
			while (1)
			{
				// show();
				if (!solve()) break;
			}
			bool ok=true;
			REP(i,n) REP(j,m) if (a[i][j]!=ID(i,j)) ok=false;
			if (!ok) continue;

			// show();
			//int length=0;
			//for (auto& a:ret) length+=SIZE(a);
			//printf("%d -> %d\n",SIZE(ret),length);
			printf("%d\n",SIZE(ret));
			for (vector<int> a:ret)
			{
				printf("%d",SIZE(a));
				for (int p:a) printf(" %d",p+1);
				printf("\n");
			}
			break;
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}