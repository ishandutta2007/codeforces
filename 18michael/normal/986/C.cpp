#include<cstdio>
int n,m,Mx,ans=0;
bool u[4200002]={},vis[8400002]={};
inline void dfs(int x)
{
	if(vis[x] || (x<Mx && !u[x]))return ;
	vis[x]=1;
	if(x<Mx)dfs(Mx+((Mx-1)^x));
	else
	{
		dfs(x-Mx);
		for(int i=0;i<n;++i)if((x>>i)&1)dfs(x^(1<<i));
	}
}
int main()
{
	scanf("%d%d",&n,&m),Mx=(1<<n);
	for(int i=1,x;i<=m;++i)scanf("%d",&x),u[x]=1;
	for(int i=0;i<Mx;++i)if(u[i] && !vis[i])dfs(i),++ans;
	return 0&printf("%d",ans);
}