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
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=200000+5;

int n,m,q;
char a[maxn][10];
int tree[1<<20][10];
int b[maxn][10];

void solveb(int p)
{
	for (int i=0;i<m;i++) b[p][i]=-1;
	for (int i=0;i<m && a[p][i]=='<';i++) b[p][i]=1;
	for (int i=m-1;i>=0 && a[p][i]=='>';i--) b[p][i]=2;
}
void combine(int p)
{
	for (int i=0;i<m;i++) tree[p][i]=(tree[p*2+2][i]<0)?-1:tree[p*2+1][tree[p*2+2][i]];
}
void bruteforce(int p,int s)
{
	for (int i=0;i<m;i++) tree[p][i]=-1;
	for (int i=0;i<m;i++) if (a[s][i]=='^') tree[p][i]=i;
	for (int i=0;i+1<m;i++) if (tree[p][i]>=0 && a[s][i+1]=='<') tree[p][i+1]=tree[p][i];
	for (int i=m-1;i>0;i--) if (tree[p][i]>=0 && a[s][i-1]=='>') tree[p][i-1]=tree[p][i];
}
void init(int p,int s,int t)
{
	if (s==t)
	{
		bruteforce(p,s);
		return;
	}
	int m=(s+t)/2;
	init(p*2+1,s,m);
	init(p*2+2,m+1,t);
	combine(p);
}
void update(int p,int s,int t,int key)
{
	if (s==t)
	{
		bruteforce(p,s);
		return;
	}
	int m=(s+t)/2;
	if (key<=m)
		update(p*2+1,s,m,key);
	else
		update(p*2+2,m+1,t,key);
	combine(p);	
}

void solve(int p,int s,int t,int &x,int &y)
{
	if (x==t && tree[p][y]>=0)
	{
		x=s-1;
		y=tree[p][y];
		return;
	}
	if (s==t) return;
	int m=(s+t)/2;
	if (x>m) solve(p*2+2,m+1,t,x,y);
	if (x<=m) solve(p*2+1,s,m,x,y);
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<n;i++)
	{
		char s[32];
		scanf("%s",s);
		for (int j=0;j<m;j++) a[i][j]=s[j];
	}
	init(0,0,n-1);
	for (int i=0;i<n;i++) solveb(i);
	for (;q>0;q--)
	{
		char s[32];
		scanf("%s",s);
		if (s[0]=='A')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--;
			y--;
			solve(0,0,n-1,x,y);
			if (x>=0)
				if (b[x][y]>0)
					y=((b[x][y]==1)?0:m+1),x++;
				else
					x=y=-1;
			else
				x++,y++;
			printf("%d %d\n",x,y);
		}
		else
		{
			int x,y;
			char d[32];
			scanf("%d%d%s",&x,&y,d);
			x--;
			y--;
			a[x][y]=d[0];
			solveb(x);
			update(0,0,n-1,x);
		}
	}
	return 0;
}