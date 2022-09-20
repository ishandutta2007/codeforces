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
typedef vector<PII> VPII;

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

#define N 101010
int p[N];
int sex[N];
VI a[N];
PII f[N],g[N];
int mark[N];

void dfs(int u)
{
	int i;
	f[u]=mp(0,0);
	g[u]=mp(0,0);
	int sX=0,sY=0;
	for(i=0;i<a[u].sz;i++)
	{
		int v=a[u][i];
		dfs(v);
		sX+=f[v].X;
		sY+=f[v].Y;
	}
	g[u]=mp(sX,sY);
	f[u]=g[u];
	for(i=0;i<a[u].sz;i++)
	{
		int v=a[u][i];
		PII cur=mp(sX-f[v].X+g[v].X+1,sY-f[v].Y+g[v].Y+(sex[u]!=sex[v]));
		MAX(f[u],cur);
	}
}

VPII q;

void dfs_fnd(int u,char c)
{
	int i,j;
	if(c=='g')
	{
		for(i=0;i<a[u].sz;i++)
		{
			int v=a[u][i];
			dfs_fnd(v,'f');
		}
		return;
	}
	int sX=g[u].X;
	int sY=g[u].Y;
	if(f[u]==mp(sX,sY))
	{
		dfs_fnd(u,'g');
		return;
	}
	for(i=0;i<a[u].sz;i++)
	{
		int v=a[u][i];
		PII cur=mp(sX-f[v].X+g[v].X+1,sY-f[v].Y+g[v].Y+(sex[u]!=sex[v]));
		if(f[u]==cur)
		{
			j=i;
			q.pb(mp(u,v));
			break;
		}
	}
	for(i=0;i<a[u].sz;i++)
	{
		int v=a[u][i];
		if(i==j) dfs_fnd(v,'g'); else dfs_fnd(v,'f');
	}
}

void del(VI &a,int x)
{
	int i;
	VI tmp;
	for(i=0;i<a.sz;i++)
		if(a[i]!=x) tmp.pb(a[i]);
	a=tmp;
}

int main()
{
#ifdef MY_DEBUG
	freopen("e.in","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)>0)
	{
		int i,j;
		for(i=0;i<n;i++)
			a[i].cl;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",p+i,sex+i);
			p[i]--;
			a[p[i]].pb(i);
		}
		PII res(0,0);
		VPII ans;
		int cnt=0;
		int w;
		fill(mark,0);
		for(w=0;w<n;w++)
			if(!mark[w])
			{
				cnt++;
				for(j=w;!mark[j];j=p[j])
					mark[j]=cnt;
				if(mark[j]==cnt)
				{
					int u=p[j];
					del(a[u],j);

					dfs(j);
					PII res1=f[j];
					q.cl;
					dfs_fnd(j,'f');
					VPII ans1=q;

					del(a[p[u]],u);

					PII res2=mp(1,sex[u]!=sex[j]);
					VPII ans2;
					ans2.pb(mp(u,j));

					dfs(j);
					res2.X+=g[j].X;
					res2.Y+=g[j].Y;
					q.cl;
					dfs_fnd(j,'g');
					for(int k=0;k<q.sz;k++)
						ans2.pb(q[k]);

					dfs(u);
					res2.X+=g[u].X;
					res2.Y+=g[u].Y;
					q.cl;
					dfs_fnd(u,'g');
					for(int k=0;k<q.sz;k++)
						ans2.pb(q[k]);

					if(res2<res1) res2=res1,ans2=ans1;
					res.X+=res2.X;
					res.Y+=res2.Y;
					for(int k=0;k<ans2.sz;k++)
						ans.pb(ans2[k]);
				}
			}
		printf("%d %d\n",res.X,res.Y);
		for(i=ans.sz;i--;)
			printf("%d %d\n",ans[i].X+1,ans[i].Y+1);
		printf("\n");
	}
	return 0;
}