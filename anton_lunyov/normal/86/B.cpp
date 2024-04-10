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

#define N 1010

int n,m;
char s[N][N];
int mark[N][N];
int a[N*N][4];
int len[N*N];
int cnt;
int ans[N*N];
int vis[N*N];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int i,int j)
{
	cnt++;
	int u=m*i+j;
	mark[i][j]=1;
	for(int k=0;k<4;k++)
	{
		int x=i+dx[k];
		int y=j+dy[k];
		if(0<=x && x<n && 0<=y && y<m && !mark[x][y] && s[x][y]=='.')
		{
			int v=m*x+y;
			a[u][len[u]++]=v;
			a[v][len[v]++]=u;
			dfs(x,y);
		}
	}
}

int NUM(int u)
{
	int num=0;
	for(int i=0;i<len[u];i++)
		if(!vis[a[u][i]]) num++;
	return num;
}

int ADJ(int u)
{
	for(int i=0;;i++)
		if(!vis[a[u][i]])
			return a[u][i];
}

void del(int u,int v)
{
	int i;
	for(i=0;i<len[u] && a[u][i]!=v;i++);
	for(i++;i<len[u];i++) a[u][i-1]=a[u][i];
	len[u]--;
}

void DEL(int u,int v)
{
	del(u,v);
	del(v,u);
}

int col;
void dfs1(int u)
{
	int i;
	if(NUM(u)==1)
	{
		int v=ADJ(u);
		if(NUM(v)==1)
		{
			col++;
			vis[u]=vis[v]=1;
			ans[u]=ans[v]=col;
			return;
		}
		u=v;
	}
	int son[4];
	int num=0;
	for(i=0;i<len[u];i++)
		if(!vis[a[u][i]]) son[num++]=a[u][i];
	int leaf=0;
	for(i=0;i<num;i++)
		if(NUM(son[i])==1)
			leaf++;
	if(leaf==0)
	{
		for(i=1;i<num;i++)
		{
			DEL(u,son[i]);
			dfs1(son[i]);
		}
		dfs1(son[0]);
		return;
	}
	vis[u]=1;
	ans[u]=++col;
	for(i=0;i<num;i++)
	{
		int v=son[i];
		if(NUM(v)==0)
		{
			vis[v]=1;
			ans[v]=col;
		}
	}
	for(i=0;i<num;i++)
	{
		int v=son[i];
		if(NUM(v)>0)
			dfs1(v);
	}
}

int b[N][N];
int cols[10];

void dfs2(int i,int j)
{
	mark[i][j]=1;
	for(int k=0;k<4;k++)
	{
		int x=i+dx[k];
		int y=j+dy[k];
		if(0<=x && x<n && 0<=y && y<m && s[x][y]=='.')
		{
			if(b[x][y]==b[i][j])
			{
				if(!mark[x][y])
					dfs2(x,y);
			}
			else
				if(b[x][y]<10) cols[b[x][y]]=1;
		}
	}
}

void dfs3(int i,int j,int col)
{
	int old=b[i][j];
	b[i][j]=col;
	for(int k=0;k<4;k++)
	{
		int x=i+dx[k];
		int y=j+dy[k];
		if(0<=x && x<n && 0<=y && y<m && s[x][y]=='.' && b[x][y]==old)
			dfs3(x,y,col);
	}
}

int main()
{
#ifdef XDEBUG
	freopen("b.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)>0)
	{
		int i,j,k;
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		fill(len,0);
		bool bad=false;
		fill(mark,0);
		fill(vis,0);
		fill(ans,0);
		col=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(s[i][j]=='.' && !mark[i][j])
				{
					cnt=0;
					dfs(i,j);
					if(cnt==1)
						bad=true;
					else
						dfs1(m*i+j);
				}
		if(bad){puts("-1");continue;}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(s[i][j]=='#') b[i][j]=-1;
				else b[i][j]=ans[m*i+j]+1e6;
		fill(mark,0);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(b[i][j]>1e6)
				{
					fill(cols,0);
					dfs2(i,j);
					for(k=0;k<10 && cols[k];k++);
					dfs3(i,j,k);
				}
		for(i=0;i<n;i++,printf("\n"))
			for(j=0;j<m;j++)
				if(s[i][j]=='#')
					putchar('#');
				else
					printf("%d",b[i][j]);
	}
	return 0;
}