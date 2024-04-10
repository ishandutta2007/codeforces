#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
cpnst ll mod=1e9+7;
int n;
ll pw2[1111111];
int p[11111111],u[11111111],c[11111111],g[11111111];
ll S;
int d[111],tp,gg;
void dfs(int dep=1,int fac=1)
{
	if(dep==tp+1)
	{
		if(fac^1)
		(S+=u[fac]*(pw2[g[fac]]-1))%=mod,g[fac]+=gg,(S-=u[fac]*(pw2[g[fac]]-1))%=mod;
		return;
	}dfs(dep+1,fac),dfs(dep+1,fac*d[dep]);
}
void degen(int x,int op)
{
	gg=op;
	for(tp=0;p[x];)
	{
		int t=p[x];
		d[++tp]=t;
		while(x%t==0)x/=t;
	}dfs();
}
void ind(int dep=1,int fac=1)
{
	if(dep==tp+1)
	{
		if(fac^1)(S-=u[fac]*(pw2[g[fac]]-1)*gg)%=mod;
		return;
	}ind(dep+1,fac),ind(dep+1,fac*d[dep]);
}
void inc(int x,int op)
{
	gg=op;
	for(tp=0;p[x];)
	{
		int t=p[x];
		d[++tp]=t;
		while(x%t==0)x/=t;
	}ind();
}
void pre()
{
	register int i,ii;
	u[1]=1;
	for(i=2;i<=1e7;i++)
	{
		if(i&1)
		{
			if(!p[i])
				for(p[i]=i,u[ii=i]=-1;ii<=1e7/i;ii+=2)
					p[i*ii]=i;
			else u[i]=((i/p[i])%p[i])?-u[i/p[i]]:0;
		}else u[i]=(i%4)?-u[i/2]:0,p[i]=2;
	}
}
int main()
{
	register int i;
	scanf("%d",&n),pre();
	for(i=pw2[0]=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x),pw2[i]=pw2[i-1]*2%mod,c[x]++;
	}for(i=1;i<=1e7;i++)if(c[i])degen(i,c[i]);
	ll ans=0;
	for(i=1;i<=1e7;i++)
		if(c[i])
			inc(i,-1),(ans+=S*c[i])%=mod,inc(i,1);
	printf("%lld\n",(ans+mod)%mod);
}
/*
Just go for it.
*/