#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=255;
const int MAX=1<<28;
int n,m,q,p;
char ss[N][N];
int A[N][N];
struct qq
{
	int x,y,z;
};int vis[N][N],cnt;
void dfs (int x,int y,int z)
{
	cnt++;
	queue<qq> q;
	q.push(qq{x,y,z});vis[x][y]=cnt;
	while (!q.empty())
	{
		qq a=q.front();q.pop();
		int xx=a.x,yy=a.y,zz=a.z;
		A[xx][yy]+=zz;
		if (zz==1) continue;
		zz>>=1;
		if (xx+1<=n&&vis[xx+1][yy]<cnt)
		{
			vis[xx+1][yy]=cnt;
			q.push(qq{xx+1,yy,zz});
		}
		if (yy+1<=m&&vis[xx][yy+1]<cnt)
		{
			vis[xx][yy+1]=cnt;
			q.push(qq{xx,yy+1,zz});
		}
		if (xx-1>=1&&vis[xx-1][yy]<cnt)
		{
			vis[xx-1][yy]=cnt;
			q.push(qq{xx-1,yy,zz});
		}
		if (yy-1>=1&&vis[xx][yy-1]<cnt)
		{
			vis[xx][yy-1]=cnt;
			q.push(qq{xx,yy-1,zz});
		}
	}
	return ;
}
int main()
{
	memset(vis,0,sizeof(vis));cnt=0;
	scanf("%d%d%d%d",&n,&m,&q,&p);
	for (int u=1;u<=n;u++)
		scanf("%s",ss[u]+1);
	for (int u=1;u<=n;u++)
		for (int i=1;i<=m;i++)
			if (ss[u][i]=='*')
				vis[u][i]=MAX;
	for (int u=1;u<=n;u++)
		for (int i=1;i<=m;i++)
			if (ss[u][i]>='A'&&ss[u][i]<='Z')
			{
				dfs(u,i,(ss[u][i]-'A'+1)*q);
			}
	int ans=0;
	for (int u=1;u<=n;u++)
		for (int i=1;i<=m;i++)
			if (A[u][i]>p)
				ans++;
	printf("%d\n",ans);
	return 0;
}