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

const int maxsize=2048;

int n,m;
int d[maxsize][maxsize];
vector<ipair> q;
int sx,sy;
int c1,c2;
char a[maxsize][maxsize];

void add(int x,int y,int e1,int e2)
{
	if (x<0 || x>=n || y<0 || y>=m) return;
	if (d[x][y]>=0) return;
	if (e1>c1 || e2>c2) return;
	if (a[x][y]!='.') return;
	d[x][y]=e1;
	q.push_back(MP(x,y));
}

void expand(int x,int y,int state)
{
	int e1=d[x][y];
	int e2=y-(sy-e1);
	if (state==0)
	{
		add(x-1,y,e1,e2);
		add(x+1,y,e1,e2);
		add(x,y+1,e1,e2+1);
	}
	else
	{
		add(x,y-1,e1+1,e2);
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n>>m)
	{
		cin>>sx>>sy>>c1>>c2;
		--sx; --sy;
		REP(i,n) cin>>a[i];
		q.clear();
		memset(d,255,sizeof(d));
		add(sx,sy,0,0);
		for (int cl=0;cl<SIZE(q);)
		{
			int saved_cl=cl;
			for (;cl<SIZE(q);cl++) expand(q[cl].first,q[cl].second,0);
			int saved_sizeq=SIZE(q);
			for (cl=saved_cl;cl<saved_sizeq;cl++) expand(q[cl].first,q[cl].second,1);
		}
		printf("%d\n",SIZE(q));
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}