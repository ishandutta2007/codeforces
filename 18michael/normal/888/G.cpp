#include<cstdio>
#define Mx 29
#define LL long long
#define inf 0x7f7f7f7f
int n,to_t=0;
LL ans=0;
int siz[6000002],dep[6000002];
int to[6000002][2];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline int dfs1(int x,int y)
{
	int res=((to[x][0] || to[x][1])? inf:0);
	if(to[x][0])
	{
		if(to[y][0])res=min(res,dfs1(to[x][0],to[y][0]));
		else res=min(res,dfs1(to[x][0],to[y][1])+(1<<dep[x]));
	}
	if(to[x][1])
	{
		if(to[y][1])res=min(res,dfs1(to[x][1],to[y][1]));
		else res=min(res,dfs1(to[x][1],to[y][0])+(1<<dep[x]));
	}
	return res;
}
inline void dfs(int x)
{
	siz[x]=1;
	if(to[x][0])dfs(to[x][0]),siz[x]+=siz[to[x][0]];
	if(to[x][1])dfs(to[x][1]),siz[x]+=siz[to[x][1]];
	if(to[x][0] && to[x][1])
	{
		ans+=(1<<dep[x]);
		if(siz[to[x][0]]<=siz[to[x][1]])ans+=dfs1(to[x][0],to[x][1]);
		else ans+=dfs1(to[x][1],to[x][0]);
	}
}
int main()
{
	scanf("%d",&n),dep[0]=Mx;
	for(int i=1,x,now;i<=n;++i)
	{
		scanf("%d",&x),now=0;
		for(int j=Mx;~j;--j)
		{
			if(!to[now][(x>>j)&1])dep[to[now][(x>>j)&1]=(++to_t)]=j-1;
			now=to[now][(x>>j)&1];
		}
	}
	dfs(0);
	return 0&printf("%lld",ans);
}