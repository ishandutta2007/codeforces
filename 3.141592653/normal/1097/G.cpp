#include<bits/stdc++.h>
const int mod=1e9+7;
int n,k,ans;
int f[111111][2][202],s[202][202],fac[202];
std::vector<int>v[111111];
void init()
{
	s[0][0]=1;
	for(register int i=fac[0]=1,ii;i<=k;fac[i]=fac[i-1]*1ll*i%mod,i++)
		for(ii=1;ii<=i;ii++)
			s[i][ii]=(s[i-1][ii-1]+s[i-1][ii]*1ll*ii)%mod;
}
int tmp[111111],ts[111111];
int min(int x,int y){return x<y?x:y;}
void mul(int*x,int*y,int lx,int ly)
{
	register int i,ii;
	for(i=0;i<=lx;i++)
		for(ii=0;ii<=ly;ii++)
			if(i+ii<=k)tmp[i+ii]=(tmp[i+ii]+x[i]*1ll*y[ii])%mod;
	for(i=0;i<=lx+ly&&i<=k;i++)x[i]=tmp[i],tmp[i]=0;
}
int sz[111111];
void dfs(int p=1,int fff=0)
{
	sz[p]=1,f[p][0][0]=1;
	int z[202];z[0]=1,z[1]=0;
	register int i;
	for(int t:v[p])if(t^fff)
	{
		dfs(t,p);
		for(i=min(k,sz[t]);i;i--)
			(f[t][0][i]+=f[t][0][i-1])%=mod,(f[t][1][i]+=f[t][1][i-1])%=mod;
		for(i=0;i<=k&&i<=sz[t];i++)
			ts[i]=(f[t][0][i]+2ll*f[t][1][i])%mod,f[p][1][i]=(f[p][1][i]+ts[i])%mod;
		ts[0]++;
		mul(z,ts,min(k,sz[p]),min(k,sz[t])),sz[p]+=sz[t];
	}for(i=0;i<=sz[p]&&i<=k;i++)f[p][0][i]=(z[i]+mod-f[p][1][i])*2ll%mod;
	f[p][0][0]--;
	for(i=0;i<=sz[p]&&i<=k;i++)
		ans=(ans+fac[i]*1ll*s[k][i]%mod*(f[p][0][i]+f[p][1][i]))%mod;
}

int main()
{
	scanf("%d%d",&n,&k);
	register int i;
	init();
	for(i=1;i<n;i++)
	{int x,y;scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);}
	dfs(),printf("%d\n",ans);
}
/*
Please don't let me down.
*/