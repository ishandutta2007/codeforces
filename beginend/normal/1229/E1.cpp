#include<bits/stdc++.h>

typedef long long LL;

const int N=10;
const int M=25;
const int S=1048580;
const int MOD=1000000007;

int n,p[N][N],ma[N][N],bin[M],a[N],b[N],f[S],g[S],tot,id[70],pts[M][N],sta[M];
bool vis[N];

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

void init()
{
	bin[0]=1;
	for (int i=1;i<=20;i++) bin[i]=bin[i-1]*2;
	scanf("%d",&n);
	int inv=ksm(100,MOD-2);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&p[i][j]),p[i][j]=(LL)p[i][j]*inv%MOD;
	while (n<6) n++,p[n][n]=1;
}

bool get_match(int x)
{
	if (x>3) return 1;
	for (int i=1;i<=3;i++)
		if (!vis[i]&&ma[a[x]][b[i]])
		{
			vis[i]=1;
			bool flag=get_match(x+1);
			vis[i]=0;
			if (flag) return 1;
		}
	return 0;
}

void dfs2(int x,int y,int pro)
{
	if (x>3)
	{
		int s=0;
		for (int i=1;i<=tot;i++)
		{
			for (int j=1;j<=3;j++) b[j]=pts[i][j];
			if (get_match(1)) s+=bin[i-1];
		}
		(f[s]+=pro)%=MOD;
		return;
	}
	ma[a[x]][y]=0;
	if (y==n) dfs2(x+1,1,(LL)pro*(1-p[a[x]][y])%MOD);
	else dfs2(x,y+1,(LL)pro*(1-p[a[x]][y])%MOD);
	ma[a[x]][y]=1;
	if (y==n) dfs2(x+1,1,(LL)pro*p[a[x]][y]%MOD);
	else dfs2(x,y+1,(LL)pro*p[a[x]][y]%MOD);
}

void dfs1(int x,int y,int s)
{
	if (y==3)
	{
		id[s]=++tot;sta[tot]=s;
		for (int i=1;i<=3;i++) pts[tot][i]=a[i];
		return;
	}
	if (x>n) return;
	dfs1(x+1,y,s);
	a[y+1]=x;
	dfs1(x+1,y+1,s+bin[x-1]);
}

void pre()
{
	for (int i=0;i<tot;i++)
		for (int j=0;j<bin[tot];j++)
			if (j&bin[i]) (g[j]+=g[j^bin[i]])%=MOD;
}

int main()
{
	init();
	dfs1(1,0,0);
	a[1]=1;a[2]=2;a[3]=3;
	dfs2(1,1,1);
	for (int i=0;i<bin[tot];i++)
	{
		int t=0;
		for (int j=1;j<=tot;j++)
		{
			int rev=id[bin[n]-1-sta[j]];
			if (i&bin[j-1]) t+=bin[rev-1];
		}
		g[t]=f[i];f[i]=0;
	}
	a[1]=4;a[2]=5;a[3]=6;
	dfs2(1,1,1);
	pre();
	int ans=0;
	for (int i=0;i<bin[tot];i++)
		(ans+=(LL)f[i]*g[bin[tot]-1-i]%MOD)%=MOD;
	printf("%d\n",(1-ans+MOD)%MOD);
	return 0;
}