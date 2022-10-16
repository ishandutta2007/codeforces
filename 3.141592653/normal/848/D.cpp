#include<bits/stdc++.h>
int n,m;
const int mod=1e9+7,V=55;
int f[65][65],g[65][65],g0[65][65][65],f0[65][65][65];
int min(int x,int y){return x<y?x:y;}
int qpow(int x,int k){int r=1;for(;k;k>>=1,x=x*1ll*x%mod)if(k&1)r=r*1ll*x%mod;return r;}
int inv[1111],fac[1111];
int C(int n,int k)
{
	int ret=1;
	for(register int i=1;i<=k;i++)ret=ret*1ll*(n+i-1)%mod;
	return ret*1ll*inv[k]%mod;
}
void calcf(int x)
{
	register int d,a,b,c,e;
	for(d=0;d<x;d++)
		for(a=0;a<=V;a++)
			for(b=0;b<=V;b++)
			{
				c=min(a,b)+1;
				f[x][c]=(f[x][c]+g[d][a]*1ll*g[x-d-1][b])%mod;
			}
	f0[x][0][0]=1;
	for(e=1;e<=V;e++)
		for(d=V;d;d--)
		{
			for(a=V;a;a--)
			{
				for(c=1;c<=d&&e*c<=a;c++)
				{
					f0[x][d][a]=(f0[x][d][a]+f0[x][d-c][a-c*e]*1ll*C(f[x][e],c))%mod;
				}
			}
		}
}
void calcg(int x)
{
	register int a,b,c,d,e;
	for(a=1;a<=x;a++)
		for(b=0;b<=V;b++)
		{
			for(c=1;x-c*a>=0;c++)
			{
				for(d=0;d<a&&d<=x-c*a;d++)
				{
					for(e=0;e<=b;e++)
					{
						g0[x][a][b]=(g0[x][a][b]+g0[x-c*a][d][b-e]*1ll*f0[a][c][e])%mod;
					}
				}
			}(g[x][b]+=g0[x][a][b])%=mod;
		}
}
void calc()
{
	register int i;
	for(i=fac[0]=1;i<=V;i++)fac[i]=fac[i-1]*1ll*i%mod,inv[i]=qpow(fac[i],mod-2);
	inv[0]=1;
	f[0][0]=1,g[0][0]=1,g0[0][0][0]=1,f0[0][0][0]=1;
	for(i=1;i<=V;i++)calcf(i),calcg(i);
}
int main()
{
	calc();
	scanf("%d%d",&n,&m),printf("%d\n",g[n][m-1]);
}