#pragma GCC optimize("Os")
#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
inline ll qpow(ll x,ll k,ll m)
{ll r=1;for(;k;k>>=1,(x*=x)%=m)if(k&1)(r*=x)%=m;return r;}
int rev[1111111];
void swap(register ll&x,register ll&y)
{x^=y^=x^=y;}
template<ll mod,ll g,ll S>
	struct poly
	{
		ll f[S+10];
		void clear()
		{memset(f,0,sizeof(f));}
		void NTT(int opt)
		{
			register int i,ii,iii;
			for(i=1;i<S;i++)
				rev[i]=(rev[i>>1]>>1)|((i&1)*(S>>1));
			for(i=1;i<S;i++)
				if(i<rev[i])swap(f[i],f[rev[i]]);
			for(i=1;i<S;i<<=1)
			{
				ll w=qpow(g,(mod-1)/(i<<1),mod),wi;
				if(opt<0)w=qpow(w,mod-2,mod);
				for(ii=0;ii<S;ii+=(i<<1))
					for(iii=0,wi=1;iii<i;iii++,(wi*=w)%=mod)
					{
						int px=ii+iii,py=px+i;
						ll vx=f[px]+f[py]*wi,vy=f[px]-f[py]*wi;
						f[px]=vx%mod,f[py]=vy%mod;
					}
			}for(i=0;i<S;i++)(f[i]+=mod)%=mod;
			if(opt<0)
			{
				ll inv=qpow(S,mod-2,mod);
				for(i=0;i<S;i++)(f[i]*=inv)%=mod;
			}
		}poly&operator*=(poly&ttt)
		{
			NTT(1),ttt.NTT(1);
			for(register int i=0;i<S;i++)
				(f[i]*=ttt.f[i])%=mod;
			NTT(~0),ttt.NTT(~0);
			return*this;
		}
		void sqrv()
		{
			NTT(1);
			for(register int i=0;i<S;i++)(f[i]*=f[i])%=mod;
			NTT(~0);
		}void invr()
		{
			if(S==1){f[0]=qpow(f[0],mod-2,mod);return;}
			poly<mod,g,(S>>1)>h;
			register int i;
			h.clear();
			for(i=0;i<(S>>1);i++)h.f[i]=f[i];
			poly<mod,g,(S<<1)>R,V,G;
			G.clear();
			for(i=0;i<S;i++)G.f[i]=f[i];
			h.invr();
			for(i=0,R.clear();i<(S>>1);i++)R.f[i]=h.f[i];
			for(i=0;i<S;i++)V.f[i]=R.f[i]*2%mod;
			R.sqrv(),R*=G;
			for(i=0;i<S;i++)f[i]=(V.f[i]+mod-R.f[i])%mod;
		}void sqrt()
		{
			const ll inv2=(mod+1)>>1;
			if(S==1)return; //only when f[0]=1 
			poly<mod,g,(S<<1)>H,O;
			poly I;
			poly<mod,g,(S>>1)>G;
			register int i;
			for(i=0;i<(S>>1);i++)G.f[i]=f[i];
			G.sqrt();
			for(i=0,I.clear();i<(S>>1);i++)I.f[i]=G.f[i];
			G.invr();
			for(i=0,H.clear();i<(S>>1);i++)H.f[i]=G.f[i];
			for(i=0,O.clear();i<S;i++)O.f[i]=f[i];
			O*=H;
			for(i=0;i<S;i++)f[i]=(O.f[i]+I.f[i])*inv2%mod;
		}
	};
cpnst ll mod=119<<23|1;
poly<mod,3,262144>p;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x),p.f[x]=-4;
	}p.f[0]=1,p.sqrt(),p.f[0]++,p.invr();
	for(i=1;i<=m;i++)printf("%lld\n",p.f[i]*2%mod);
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/