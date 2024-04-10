#pragma GCC optimize("O3")
#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
ll S2(ll n)
{
	ll e=n*(n+1)/2;
	if(e%3==0)return(e/3)%mod*(n*2+1)%mod;
	else return(e%mod*(n*2+1)/3)%mod;
}
ll t[2222222],d[1111111],phi[1111111],p[1111111];
ll pw2[2222222],pw[2222222];
void exec()
{
	int n,m,dt;
	scanf("%d%d",&n,&m);
	if(n>m)n^=m^=n^=m;
	dt=m-n;
	printf("%lld\n",(pw2[n+1]+pw[n+1]*dt)%mod);
}
namespace poly
{
	const ll m1=469762049,m2=998244353,m3=1004535809,g=3;
	const int V=1<<21;
	int rev[2222222];
	ll qpow(ll x,ll k,const ll m)
	{ll r=1;for(;k;k>>=1,(x*=x)%=m)if(k&1)(r*=x)%=m;return r;}
	const ll I1=554580198,I2=395249030;
	ll crtcall(ll X,ll Y,ll Z)
	{
		ll R=((Y-X)%m2+m2)*I1%m2,S=X+m1*R,T=I2*((Z-S%m3)%m3+m3)%m3;
		return(S+T*m1%mod*m2)%mod;
	}
	void swap(ll&x,ll&y){x^=y^=x^=y;}
	void NTT(ll*x,const ll m,int opt)
	{
		int i,ii,iii;
		for(i=0;i<V;i++)if(rev[i]<i)swap(x[i],x[rev[i]]);
		for(i=1;i<V;i<<=1)
		{
			ll w=qpow(g,(m-1)/(i<<1),m),wi;
			if(opt<0)w=qpow(w,m-2,m);
			for(ii=0;ii<V;ii+=(i<<1))
				for(iii=0,wi=1;iii<i;iii++,(wi*=w)%=m)
				{
					int px=ii+iii,py=i+ii+iii;
					ll vx=x[px]+wi*x[py],vy=x[px]-wi*x[py];
					x[px]=vx%m,x[py]=vy%m;
				}
		}ll cas=1;if(opt<0)cas=qpow(V,m-2,m);
		for(i=0;i<V;i++)x[i]=(x[i]+m)*cas%m;
	}
	ll Wx[3][2222222],Wy[3][2222222],tx[2222222],ty[2222222],tz[2222222];
	void MTT(ll*x,ll*y,ll*z)
	{
		int i;
		for(i=0;i<V;i++)rev[i]=(rev[i>>1]>>1)+(i&1)*(V>>1);
		for(i=0;i<V;i++)tx[i]=x[i],ty[i]=y[i],tz[i]=z[i];
		NTT(x,m1,1),NTT(y,m1,1),NTT(z,m1,1);
		for(i=0;i<V;i++)Wx[0][i]=x[i]*z[i]%m1,Wy[0][i]=y[i]*z[i]%m1;
		NTT(Wx[0],m1,-1),NTT(Wy[0],m1,-1);
		for(i=0;i<V;i++)x[i]=tx[i],y[i]=ty[i],z[i]=tz[i];
		NTT(x,m2,1),NTT(y,m2,1),NTT(z,m2,1);
		for(i=0;i<V;i++)Wx[1][i]=x[i]*z[i]%m2,Wy[1][i]=y[i]*z[i]%m2;
		NTT(Wx[1],m2,-1),NTT(Wy[1],m2,-1);
		for(i=0;i<V;i++)x[i]=tx[i],y[i]=ty[i],z[i]=tz[i];
		NTT(x,m3,1),NTT(y,m3,1),NTT(z,m3,1);
		for(i=0;i<V;i++)Wx[2][i]=x[i]*z[i]%m3,Wy[2][i]=y[i]*z[i]%m3;
		NTT(Wx[2],m3,-1),NTT(Wy[2],m3,-1);
		for(i=0;i<V;i++)
			x[i]=crtcall(Wx[0][i],Wx[1][i],Wx[2][i]),
			y[i]=crtcall(Wy[0][i],Wy[1][i],Wy[2][i]);
	}
}
#include<ctime>
void init()
{
	int V=1e6+7;
	int i,ii;
	phi[1]=1;
	for(i=2;i<=V;i++)
	{
		if(!p[i])
		{
			phi[i]=i-1;
			for(ii=i;ii<=V/i;ii++)p[i*ii]=i;
		}else
		{
			if((i/p[i])%p[i])phi[i]=phi[i/p[i]]*(p[i]-1);
			else phi[i]=phi[i/p[i]]*p[i];
		}
	}for(i=1;i<=V;i++)
		for(ii=i;ii<=V;ii+=i)(d[ii]+=(ii/i)*1ll*phi[i])%=mod;
	for(i=1;i<=V;i++)
		t[i]=(S2(i)+S2(i-1)+(d[i]+mod-i*1ll*i%mod)*2)%mod,pw[i]=i,pw2[i]=i*1ll*i%mod;
	poly::MTT(pw,pw2,t);
}
int main()
{
	int T;
	init();
	scanf("%d",&T);
	for(;T--;)exec();
}
/*
Please don't let me down.
*/