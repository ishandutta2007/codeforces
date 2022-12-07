#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1100;
int m,n;
char ss[N][11];
int d[N];
struct qq
{
	int x,y,last;
}e[N*N];int num,last[N];
void init (int x,int y)
{
	e[++num].x=x;e[num].y=y;e[num].last=last[x];
	last[x]=num;
}
int id[N];
bool cmp (int x,int y)	{return d[x]>d[y];}
int f[N];
bool vis[N];
bool find (int x)
{
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (vis[y]) continue;
		vis[y]=true;
		if (f[y]==0) {f[y]=x;return true;}
		else if (find(f[y])) {f[y]=x;return true;}
	}
	return false;
}
int nxt[N];
void print (int x,int y)
{
	for (int u=1;u<=m;u++) if (ss[x][u]=='1'&&ss[y][u]!='1') printf("%d ",u-1);
}
void solve (int x)
{
	if (x==0) return ;
	print(x,f[x]);
	solve(nxt[x]);
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&m,&n);
	int ans=0;
	for (int u=1;u<=n;u++) 
	{
		scanf("%s",ss[u]+1);
		for (int i=1;i<=m;i++) if (ss[u][i]=='1') d[u]++;
		ans=ans+d[u]+1;
	}
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=n;i++) if (u!=i)
		{
			bool tf=true;
			for (int j=1;j<=m;j++) if (ss[u][j]=='1')
			{
				if (ss[i][j]!='1') {tf=false;break;}
			}
			if (tf) init(u,i);
		}
	}
	for (int u=1;u<=n;u++) id[u]=u;
	sort(id+1,id+1+n,cmp);
	memset(f,0,sizeof(f));
	for (int u=1;u<=n;u++)
	{
		memset(vis,false,sizeof(vis));
		if (find(id[u])) ans=ans-(d[id[u]]+1); 
	}
	printf("%d\n",ans-1);
	for (int u=1;u<=n;u++) if (f[u]!=0) nxt[f[u]]=u;
	bool tf=false;	
	for (int u=1;u<=n;u++) if (f[u]==0)
	{
		if (tf) printf("R ");
		tf=true;
		solve(u);
	}
	return 0;
}