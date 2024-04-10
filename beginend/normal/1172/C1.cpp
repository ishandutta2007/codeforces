#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=55;
const int MOD=998244353;

int n,m,w[N],ny[3005],f[N][N][N];
bool lik[N];

void pre()
{
	ny[0]=ny[1]=1;
	for (int i=2;i<=3000;i++) ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
}

int main()
{
	pre();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&lik[i]);
	int s1=0,s2=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		if (lik[i]) s1+=w[i];
		else s2+=w[i];
	}
	for (int id=1;id<=n;id++)
	{
		memset(f,0,sizeof(f));
		f[0][0][0]=1;
		for (int i=0;i<m;i++)
			for (int j=0;j<=i;j++)
				for (int k=0;k<=i;k++)
				{
					if (!f[i][j][k]) continue;
					int t1=s1+j,t2=s2-(i-j);
					if (!lik[id])
					{
						int wt=w[id]-k;
						(f[i+1][j+1][k]+=(LL)f[i][j][k]*ny[t1+t2]%MOD*t1%MOD)%=MOD;
						(f[i+1][j][k]+=(LL)f[i][j][k]*ny[t1+t2]%MOD*(t2-wt)%MOD)%=MOD;
						(f[i+1][j][k+1]+=(LL)f[i][j][k]*ny[t1+t2]%MOD*wt%MOD)%=MOD;
					}
					else
					{
						int wt=w[id]+k;
						(f[i+1][j][k]+=(LL)f[i][j][k]*ny[t1+t2]%MOD*t2%MOD)%=MOD;
						(f[i+1][j+1][k]+=(LL)f[i][j][k]*ny[t1+t2]%MOD*(t1-wt)%MOD)%=MOD;
						(f[i+1][j+1][k+1]+=(LL)f[i][j][k]*ny[t1+t2]%MOD*wt%MOD)%=MOD;
					}
				}
		int ans=0;
		for (int i=0;i<=m;i++)
		{
			int s=0;
			for (int j=0;j<=m;j++) (s+=f[m][j][i])%=MOD;
			if (!lik[id]) (ans+=(LL)s*(w[id]-i)%MOD)%=MOD;
			else (ans+=(LL)s*(w[id]+i)%MOD)%=MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}