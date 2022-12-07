#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=100005;
const LL K=205;
LL n,k;
struct qq
{
	LL x,y,last;
}e[N*2];LL num,last[N];
void init (LL x,LL y)
{
	num++;e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL S[K][K];
LL JC[K];
LL h[K];
LL siz[N];
LL f[N][K];
LL g[N];
void dfs (LL x,LL fa)
{
	siz[x]=1;
	f[x][0]=2;
	for (LL xx=last[x];xx!=-1;xx=e[xx].last)
	{
		LL y=e[xx].y;
		if (y==fa) continue;
		dfs(y,x);
		for (LL u=0;u<=min(siz[x]+siz[y]-1,k);u++) g[u]=0;
		for (LL u=0;u<siz[x]&&u<=k;u++)
			for (LL i=0;i<=siz[y]&&(u+i)<=k;i++)
				g[u+i]=(g[u+i]+f[x][u]*f[y][i]%MOD)%MOD;
		siz[x]=siz[x]+siz[y];
		for (LL u=0;u<=min(siz[x]-1,k);u++) f[x][u]=g[u];
	}
	if (x==1)
	{
		for (LL u=0;u<=k;u++) h[u]=h[u]+f[x][u];
	}
	else
	{
		for (LL u=1;u<=k;u++) h[u]=(h[u]-f[x][u-1])%MOD;
		h[1]=(h[1]+1)%MOD;
	}
	for (LL u=k;u>=1;u--) f[x][u]=(f[x][u]+f[x][u-1])%MOD;
	f[x][1]=(f[x][1]-1+MOD)%MOD;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld%lld",&n,&k);
	JC[0]=1;for (LL u=1;u<=k;u++) JC[u]=JC[u-1]*u%MOD;
	S[0][0]=1;
	for (LL u=1;u<=k;u++)
		for (LL i=1;i<=u;i++)
			S[u][i]=(S[u-1][i-1]+S[u-1][i]*i%MOD)%MOD;
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		init(x,y);init(y,x);
	}
	dfs(1,0);
	LL ans=0;
	for (LL u=0;u<=k;u++) ans=(ans+S[k][u]*JC[u]%MOD*h[u]%MOD)%MOD;
	ans=(ans+MOD)%MOD;
	printf("%lld\n",ans);
	return 0;
}