#include<cstdio>
typedef long long ll;
const int mod=119<<23|1;
const ll M2=mod*1ll*mod;
int qpow(int x,int k)
{int r=1;for(;k;k>>=1,x=x*1ll*x%mod)if(k&1)r=r*1ll*x%mod;return r;}
int fac[1111111],inv[1111111];
int C(int n,int r)
{return(r<0||n<r)?0:fac[n]*1ll*inv[r]%mod*inv[n-r]%mod;}
void init()
{
	register int i;
	const int V=1e6; 
	for(i=fac[0]=1;i<=V;i++)fac[i]=fac[i-1]*1ll*i%mod;
	for(inv[i=V]=qpow(fac[V],mod-2);i;i--)
		inv[i-1]=inv[i]*1ll*i%mod;
}
int n;
int rv[22222],wi[22222];
void swap(register int&x,register int&y){int t=x;x=y,y=t;}
void NTT(int*x,int SZ,int op)
{
	register int i,ii,iii;
	for(i=1;i<SZ;i++)rv[i]=(rv[i>>1]>>1)+(i&1)*(SZ>>1);
	for(i=1;i<SZ;i++)if(i<rv[i])swap(x[i],x[rv[i]]);
	for(i=1;i<SZ;i<<=1)
	{
		int w=qpow(3,(mod-1)/(i<<1));
		if(op<0)w=qpow(w,mod-2);
		for(iii=wi[0]=1;iii<i;iii++)wi[iii]=wi[iii-1]*1ll*w%mod;
		for(ii=0;ii<SZ;ii+=(i<<1))
			for(iii=0;iii<i;iii++)
			{
				int px=ii+iii,py=px+i;
				ll Dt=x[py]*1ll*wi[iii];
				x[py]=(x[px]+M2-Dt)%mod,x[px]=(x[px]+Dt)%mod;
			}
	}if(op<0)
	{
		int a=qpow(SZ,mod-2);
		for(i=0;i<SZ;i++)x[i]=x[i]*1ll*a%mod;
	}
}
int cur[22222],pwr,cs[22222];
void upd(int a,int b)
{
	register int i;
	int pwt=pwr+a-b,tp=pwt+pwr*2,S;
	for(i=2;i<=tp;i<<=1);S=i;
	for(i=0;i<S;i++)cs[i]=0;
	for(i=-pwr;i<=pwt;i++)cs[i+pwr]=C(a+b,b+i);
	NTT(cs,S,1),NTT(cur,S,1);
	for(i=0;i<S;i++)cur[i]=cur[i]*1ll*cs[i]%mod;
	NTT(cur,S,-1);
	for(i=0;i<=pwt;i++)cur[i]=cur[i+pwr];
	for(i=pwt+1;i<S;i++)cur[i]=0;
	pwr=pwt;
}
int main()
{
	init(),cur[0]=1,pwr=0;
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b),upd(a,b);
	}ll ans=0;
	for(i=0;i<=pwr;i++)ans+=cur[i];
	printf("%lld\n",ans%mod);
}
/*
Please don't let me down.
*/