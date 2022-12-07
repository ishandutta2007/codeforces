#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=605;
const int MAX=2e9;
struct qt
{
	int x,y,c,last;
}e[N*N];int num,last[N];
void init (int x,int y,int c)
{
	e[++num].x=x;e[num].y=y;e[num].c=c;
	e[num].last=last[x];last[x]=num;
}
int f[N];
bool vis[N];
int n,m;
void solve (int xx)
{
	for (int i=0;i<n;i++) vis[i]=false;
	for (int i=0;i<=n;i++) f[i]=MAX;
	for (int i=last[xx];i!=-1;i=e[i].last)
	{
		int y=e[i].y;
		f[y]=min(f[y],e[i].c);
	}
	for (int T=2;T<=n;T++)
	{
		int x=n;
		for (int i=0;i<n;i++) if (vis[i]==false&&f[i]<f[x]) x=i;
		//printf("YES:%d %d %d\n",xx,x,f[x]);
		vis[x]=true;
		for (int i=last[x];i!=-1;i=e[i].last)
		{
			int y=(e[i].y+f[x])%n;
			f[y]=min(f[y],f[x]+e[i].c);
		}
		f[(x+1)%n]=min(f[(x+1)%n],f[x]+1);
		//printf("f1:%d\n",f[1]);
		//printf("check:%d %d %d\n",(x+1)%n,f[x]+1,f[(x+1)%n]);
	}
	f[xx]=0;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		init(x,y,c);
	}
	for (int u=0;u<n;u++)
	{
		solve(u);
		for (int i=0;i<n;i++) printf("%d ",f[i]);
		printf("\n");
	}
	return 0;
}