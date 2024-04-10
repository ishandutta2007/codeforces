#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

LL sqr(LL a){return a*a;}

#define N 1111

struct circle
{
	LL x,y,r;
	circle(LL x_=0,LL y_=0,LL r_=0){x=x_;y=y_;r=r_;}
	void read()
	{
		scanf("%I64d %I64d %I64d",&r,&x,&y);
	}
	bool operator<(const circle &c) const
	{
		return r>c.r;
	}
};

circle c[N];

VI a[N];
int mark[N];
int p[N];
int d[N][N];
int cur;

void dfs(int u,int h)
{
	d[cur][u]=h;
	mark[u]=1;
	for(int i=a[u].sz;i--;)
	{
		int v=a[u][i];
		if(!mark[v]) dfs(v,h+1);
	}
}

int main()
{
	//freopen("d.in","r",stdin);
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)>0)
	{
		LL x[N],y[N];
		int i,j;
		for(i=1;i<=n;i++)
			scanf("%I64d %I64d",x+i,y+i);
		c[0]=circle(0,0,2*inf);
		for(i=1;i<=m;i++)
			c[i].read();
		sort(c+1,c+m+1);
		for(i=0;i<=m;i++) a[i].cl;
		for(i=1;i<=m;i++)
		{
			for(j=i-1;j>0;j--)
				if(sqr(c[i].x-c[j].x)+sqr(c[i].y-c[j].y)<=sqr(c[j].r-c[i].r)) break;
			p[i]=j;
			a[i].pb(j);
			a[j].pb(i);
		};
		for(i=0;i<=m;i++)
		{
			fill(mark,0);
			cur=i;
			dfs(i,0);
		}
		int circ[N];
		for(i=1;i<=n;i++)
		{
			for(j=m;j>0;j--)
				if(sqr(x[i]-c[j].x)+sqr(y[i]-c[j].y)<=sqr(c[j].r)) break;
			circ[i]=j;
		};
		while(k--)
		{
			scanf("%d%d",&i,&j);
			i=circ[i];
			j=circ[j];
			printf("%d\n",d[i][j]);
		}
	}
	return 0;
}