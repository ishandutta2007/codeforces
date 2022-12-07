#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
struct qq
{
	LL x,y,last;
}e[N];LL num,last[N];
LL n,l,s;
LL w[N];
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL sum[N];
LL fa[N][21];
LL dep[N];
LL top[N];
void dfs (LL x)
{
	for (LL u=1;u<=20;u++) fa[x][u]=fa[fa[x][u-1]][u-1];
	LL now=x;
	for (LL u=20;u>=0;u--)
	{
		if (fa[now][u]!=0)
		{
			LL xx=fa[fa[now][u]][0];
			if (sum[x]-sum[xx]<=s&&dep[x]-dep[xx]<=l)
				now=fa[now][u];
		}
	}
	top[x]=now;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		dep[y]=dep[x]+1;
		sum[y]=sum[x]+w[y];
		fa[y][0]=x;
		dfs(y);
	}
}
LL ans=0;
void solve (LL x)
{
	LL up=-1;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		solve(y);
		if (top[y]==y) continue;
		if (up==-1||top[y]<up)	up=top[y];
	}
	if (up==-1)
	{
		up=top[x];
		ans++;
	}
	top[x]=up;
	return ;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld%lld%lld",&n,&l,&s);
	for (LL u=1;u<=n;u++)	
	{
		scanf("%lld",&w[u]);
		if (w[u]>s)
		{
			printf("-1\n");
			return 0;
		}
	}
	for (LL u=2;u<=n;u++)
	{
		LL x;
		scanf("%lld",&x);
		init(x,u);
	}
	sum[1]=w[1];dep[1]=1;dfs(1);
	//for (int u=1;u<=n;u++) printf("%lld ",sum[u]);
	//printf("\n");
	solve(1);
	printf("%lld\n",ans);
	return 0;
}