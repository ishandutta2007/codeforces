#include<stdio.h>
#include<bits/stdc++.h>
int n;
int d[1<<20];
const int mod=998244353,G=3,IG=(mod+1)/3,lm=1<<20;
int fc[1<<20|15],fiv[1<<20|15],iv[1<<20|15];
int qpow(int x,int k){int r=1;for(;k;k>>=1,x=x*1ll*x%mod)if(k&1)r=r*1ll*x%mod;return r;}
void init()
{
	register int i;
	for(i=fc[0]=1;i<=lm;i++)fc[i]=fc[i-1]*1ll*i%mod;
	for(fiv[i=lm]=qpow(fc[lm],mod-2);i;i--)
		fiv[i-1]=fiv[i]*1ll*i%mod,iv[i]=fiv[i]*1ll*fc[i-1]%mod;
}
struct poly
{
	std::vector<int>f;
	void e(){f.clear(),f.push_back(1);}
	void dft(int V,int op)
	{
		register int i,ii,iii;
		static int rv[1<<20],wi[1<<20];
		if(int(f.size())!=V)
		{
			int o=f.size();f.resize(V);
			for(i=o;i<V;i++)f[i]=0;
		}for(i=1;i<V;i++)rv[i]=(rv[i>>1]>>1)+(i&1)*(V>>1);
		for(i=1;i<V;i++)if(i<rv[i]){int t=f[i];f[i]=f[rv[i]],f[rv[i]]=t;}
		for(i=1;i<V;i<<=1)
		{
			int w=qpow(3,(mod-1)/(i<<1));
			if(op<0)w=qpow(w,mod-2);
			for(iii=wi[0]=1;iii<i;iii++)wi[iii]=wi[iii-1]*1ll*w%mod;
			for(ii=0;ii<V;ii+=(i<<1))
				for(iii=0;iii<i;iii++)
				{
					int px=ii+iii,py=px+i;
					long long d=wi[iii]*1ll*f[py];
					f[py]=(f[px]+mod*1ll*mod-d)%mod,f[px]=(f[px]+d)%mod;
				}
		}if(op<0)
		{
			int Iv2=qpow(V,mod-2);
			for(i=0;i<V;i++)f[i]=f[i]*1ll*Iv2%mod;
		}
	}
	poly operator+(const poly&y)
	{
		poly z=*this;
		if(z.f.size()<y.f.size())z.f.resize(y.f.size());
		for(register int i=0;i<y.f.size();i++)(z.f[i]+=y.f[i])<mod?0:z.f[i]-=mod;
		return z;
	}
	poly operator-(const poly&y)
	{
		poly z=*this;
		if(z.f.size()<y.f.size())z.f.resize(y.f.size());
		for(register int i=0;i<y.f.size();i++)(z.f[i]+=mod-y.f[i])<mod?0:z.f[i]-=mod;
		return z;
	}
	poly operator*(const poly&y)const
	{
		poly z=*this,w=y;
		int p=z.f.size()+w.f.size()-2,S=1;for(;S<=p;S<<=1);
		z.dft(S,1),w.dft(S,1);
		for(register int i=0;i<S;i++)z.f[i]=z.f[i]*1ll*w.f[i]%mod;
		z.dft(S,-1),z.f.resize(p+1);
		return z;
	}
	void extend()
	{
		register int p=f.size(),S=1;
		for(;S<p;S<<=1);
		f.resize(S);
		for(;p<S;p++)f[p]=0;
	}
	inline void cutUntil(int Lim)
	{if(Lim<f.size())f.resize(Lim);}
	poly splitFirstHalf()const
	{
		poly z=*this;
		z.cutUntil(f.size()>>1);
		return z;
	}
	poly splitLastHalf()const
	{
		poly z;
		register int i,S=f.size()>>1;
		z.f.resize(S);
		for(i=0;i<S;i++)z.f[i]=f[i+S];
		return z;
	}
	void inv()
	{
		if(f.size()==1){f[0]=qpow(f[0],mod-2);return;}
		extend();
		int S=f.size(),T=S>>1;
		poly z=this->splitFirstHalf(),f0=z,f1=this->splitLastHalf();
		z.inv();
		poly a=f0*z,b=f1*z;a.f.push_back(0),b.f.push_back(0);
		register int i;
		for(i=0;i<T;i++)(a.f[i]=a.f[i+T]+b.f[i])<mod?0:a.f[i]-=mod;
		a.cutUntil(T),a=a*z;
		for(i=0;i<T;i++)f[i]=z.f[i];
		for(i=T;i<S;i++)f[i]=a.f[i-T]?mod-a.f[i-T]:0;
	}
	void dif()
	{
		register int i;
		for(i=0;i+1<f.size();i++)
			f[i]=f[i+1]*1ll*(i+1)%mod;
		f.pop_back();
	}
	void itg()
	{
		f.push_back(0);
		for(register int i=f.size()-1;i;i--)
			f[i]=f[i-1]*1ll*iv[i]%mod;
		f[0]=0;
	}
	void ln()
	{
		poly z=*this;
		int S=f.size();
		z.dif(),inv(),*this=*this*z,itg(),z.cutUntil(S);
	}
	void exp()
	{
		if(f.size()==1){f[0]=1;return;}
		extend();
		poly z=this->splitFirstHalf();
		z.exp();
		poly w=z;
		int S=f.size(),T=S>>1;
		register int i;
		for(i=0;i<T;i++)f[i]=z.f[i];
		z.f.resize(S);
		for(i=T;i<S;i++)z.f[i]=0;
		z.ln();
		for(i=0;i<T;i++)(z.f[i]=f[i+T]+mod-z.f[i+T])<mod?0:z.f[i]-=mod;
		z.f.resize(T),z=z*w;
		for(i=0;i<T;i++)f[i+T]=z.f[i];
	}
};
poly solve(int L,int R)
{
	if(L==R)
	{
		poly ret;
		ret.f.push_back(1);
		ret.f.push_back(d[L]);
		return ret; 
	}
	int M=(L+R)>>1;
	return solve(L,M)*solve(M+1,R);
}
int fac[1<<20];
int main()
{
	scanf("%d",&n);
	for(int i=fac[0]=1;i<=n;i++)fac[i]=fac[i-1]*1ll*i%mod;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]++,d[y]++;
	}
	for(int i=2;i<=n;i++)d[i]--;
	poly P=solve(1,n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		//printf("%d ",P.f[i]);
		if(i&1)ans=(ans+mod-P.f[i]*1ll*fac[n-i]%mod)%mod;
		else ans=(ans+P.f[i]*1ll*fac[n-i]%mod)%mod;
	}
	printf("%d\n",ans);
}