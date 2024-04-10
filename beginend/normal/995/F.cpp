#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=3005;
const int MOD=1000000007;

int n,m,cnt,last[N],f[N][N],ny[N];
struct edge{int to,next;}e[N];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void dp(int x)
{
	for (int i=1;i<=n+1;i++) f[x][i]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		dp(e[i].to);
		int s=0;
		for (int j=1;j<=n+1;j++)
		{
			(s+=f[e[i].to][j])%=MOD;
			f[x][j]=(LL)f[x][j]*s%MOD;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n;i++)
	{
		int x;scanf("%d",&x);
		addedge(x,i);
	}
	dp(1);
	for (int i=2;i<=n+1;i++) (f[1][i]+=f[1][i-1])%=MOD;
	if (m<=n+1) {printf("%d",f[1][m]);return 0;}
	ny[0]=ny[1]=1;
	for (int i=2;i<=n+1;i++) ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	int ans=0;
	for (int i=1;i<=n+1;i++)
	{
		int s=f[1][i];
		for (int j=1;j<=n+1;j++)
		{
			if (i==j) continue;
			s=(LL)s*(m-j)%MOD*(i>j?ny[i-j]:MOD-ny[j-i])%MOD;
		}
		(ans+=s)%=MOD;
	}
	printf("%d",(ans+MOD)%MOD);
	return 0;
}