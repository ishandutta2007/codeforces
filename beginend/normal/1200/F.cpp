#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1005;
const int mo=2520;

int n,k[N],e[N][15],f[N][mo+5],tim,now[N][mo+5],dep[N][mo+5],m[N],q,stack[N*mo],top;
bool vis[N];

void dfs(int x,int y)
{
	stack[dep[x][y]]=x;
	now[x][y]=tim;
	int to=(y+k[x])%mo,p=e[x][to%m[x]];
	if (p==x&&to==y) {f[x][y]=1;return;}
	if (f[p][to]) f[x][y]=f[p][to];
	else if (now[p][to]==tim)
	{
		int cnt=0;
		for (int i=dep[p][to];i<=dep[x][y];i++) if (!vis[stack[i]]) vis[stack[i]]=1,cnt++;
		for (int i=dep[p][to];i<=dep[x][y];i++) vis[stack[i]]=0;
		f[x][y]=cnt;
	}
	else dep[p][to]=dep[x][y]+1,dfs(p,to),f[x][y]=f[p][to];
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&k[i]),k[i]=(k[i]%mo+mo)%mo;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		for (int j=0;j<m[i];j++) scanf("%d",&e[i][j]);
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<mo;j++)
			if (!f[i][j]) tim++,dep[i][j]=1,top=0,dfs(i,j);
	scanf("%d",&q);
	while (q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		y=(y%mo+mo)%mo;
		printf("%d\n",f[x][y]);
	}
	return 0;
}