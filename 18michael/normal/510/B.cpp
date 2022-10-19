#include<cstdio>
int n,m,t=0,t1,ok=0;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
char s[52][52];
int vis[52][52];
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void dfs(int x,int y,int z)
{
	t=max(t,z);
	if(vis[x][y]>t1)
	{
		if(z+1-vis[x][y]>=4)ok=1;
		return ;
	}
	vis[x][y]=(++z);
	for(int i=0,nx,ny;i<4;++i)
	{
		nx=x+dx[i],ny=y+dy[i];
		if(nx>0 && nx<=n && ny>0 && ny<=m && s[nx][ny]==s[x][y])
		{
			dfs(nx,ny,z);
			if(ok)return ;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!vis[i][j])
			{
				t1=t,dfs(i,j,t);
				if(ok)break;
			}
	puts(ok? "Yes":"No");
	return 0;
}