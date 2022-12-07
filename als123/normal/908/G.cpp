#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=705;
char ss[N];
LL n;
LL a[N];
LL g[N];
LL f[N][N][2][10];
int main()
{
	scanf("%s",ss+1);n=strlen(ss+1);
	for (LL u=1;u<=n;u++) a[u]=ss[u]-'0';
	g[1]=1;for (LL u=2;u<=n;u++) g[u]=(g[u-1]*10+1)%MOD;
	for (LL u=0;u<=9;u++) f[0][0][1][u]=1;
	for (LL u=1;u<=n;u++)
		for(LL i=0;i<=u;i++)//
			for (LL k=0;k<=9;k++)//
			{
				for (LL j=0;j<=9;j++)//
				{
					if (i==0&&j>=k) continue;
					//op=0
					f[u][i][0][k]=(f[u][i][0][k]+f[u-1][i-(j>=k)][0][k])%MOD;
					if (j<a[u]) 
					{
					/*	if (u==1&&i==1&&k==1)
							printf("%lld %lld %lld %lld %lld\n",u-1,i-(j>=k),1,k,f[u-1][i-(j>=k)][1][k]);*/
						f[u][i][0][k]=(f[u][i][0][k]+f[u-1][i-(j>=k)][1][k])%MOD;
					}
					//op=1
					if (j==a[u]) f[u][i][1][k]=(f[u][i][1][k]+f[u-1][i-(j>=k)][1][k])%MOD;
				}
				//printf("%lld %lld %lld %lld %lld\n",u,i,k,f[u][i][0][k],f[u][i][1][k]);
			}
	LL ans=0;
	for (LL u=1;u<=9;u++)
	{
		for (LL i=1;i<=n;i++)
		{
			//printf("%lld %lld %lld %lld\n",u,i,f[n][i][0][u],f[n][i][1][u]);
			ans=ans+g[i]*(f[n][i][0][u]+f[n][i][1][u]%MOD)%MOD;
			ans=ans%MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}