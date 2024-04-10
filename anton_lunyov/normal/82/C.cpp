#include <stdio.h>
#include <time.h>
#include <assert.h>
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

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 5050
int n;
vector<PII> a[N];
PII b[N][N];
int len[N];
char mark[N];
int ans[N];
int p[N];
int c[N];

void dfs0(int u)
{
	mark[u]=1;
	for(int i=a[u].sz;i--;)
	{
		int v=a[u][i].X;
		if(!mark[v])
		{
			p[v]=u;
			c[v]=a[u][i].Y;
			dfs0(v);
		}
	}
}

void dfs(int u)
{
	if(u)
	{
		int v=p[u];
		int i,j=0;
		for(i=len[u]-1;i>=0 && j<c[u];j++,i--)
			b[v][len[v]++]=b[u][i];
		len[u]=i+1;
	}
	for(int i=a[u].sz;i--;)
	{
		int v=a[u][i].X;
		if(v!=p[u]) dfs(v);
	}
}

int main()
{
#ifdef MY_DEBUG
	freopen("c.in","r",stdin);
#endif
	while(scanf("%d",&n)>0)
	{
		fill(len,0);
		int i;
		for(i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			b[i][len[i]++]=mp(x,i);
			a[i].cl;
		}
		for(i=1;i<n;i++)
		{
			int u,v,x;
			scanf("%d%d%d",&u,&v,&x);
			u--;v--;
			a[u].pb(mp(v,x));
			a[v].pb(mp(u,x));
		}
		p[0]=0;
		fill(mark,0);
		dfs0(0);
		int num=0;
		for(int it=0;;it++)
		{
			for(i=0;i<len[0];i++)
				ans[b[0][i].Y]=it;
			num+=len[0];
			if(num==n) break;
			len[0]=0;
			dfs(0);
			for(i=0;i<n;i++)
				if(len[i])
				{
					sort(b[i],b[i]+len[i]);
					reverse(b[i],b[i]+len[i]);
				}
		}
		for(i=0;i<n;i++)
			printf("%d%c",ans[i],i<n-1?' ':'\n');
	}
	return 0;
}