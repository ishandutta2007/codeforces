#include<cstdio>
#include<vector>
int qpow(int x,int k,int md)
{int r=1;for(;k;k>>=1,x=x*1ll*x%md)if(k&1)r=r*1ll*x%md;return r;}
template<int POLYM>
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
			int w=qpow(3,(POLYM-1)/(i<<1),POLYM);
			if(op<0)w=qpow(w,POLYM-2,POLYM);
			for(iii=wi[0]=1;iii<i;iii++)wi[iii]=wi[iii-1]*1ll*w%POLYM;
			for(ii=0;ii<V;ii+=(i<<1))
				for(iii=0;iii<i;iii++)
				{
					int px=ii+iii,py=px+i;
					long long d=wi[iii]*1ll*f[py];
					f[py]=(f[px]+POLYM*1ll*POLYM-d)%POLYM,f[px]=(f[px]+d)%POLYM;
				}
		}if(op<0)
		{
			int Iv2=qpow(V,POLYM-2,POLYM);
			for(i=0;i<V;i++)f[i]=f[i]*1ll*Iv2%POLYM;
		}
	}
	void load(int*x,int le)
	{f.resize(le);for(register int i=0;i<le;i++)f[i]=x[i]%POLYM;}
	poly operator*(const poly&y)const
	{
		poly z=*this,w=y;
		int p=z.f.size()+w.f.size()-2,S=1;for(;S<=p;S<<=1);
		z.dft(S,1),w.dft(S,1);
		for(register int i=0;i<S;i++)z.f[i]=z.f[i]*1ll*w.f[i]%POLYM;
		z.dft(S,-1),z.f.resize(p+1);
		return z;
	}
};
const int p1=167772161,p2=998244353,p3=1004535809;
const int iv1=qpow(p1,p2-2,p2),iv12=qpow(p1,p3-2,p3)*1ll*qpow(p2,p3-2,p3)%p3;
const int mod=1e9+7,SIZ=65536,p12=p1*1ll*p2%mod;
poly<p1>F1,G1;
poly<p2>F2,G2;
poly<p3>F3,G3;
typedef long long ll;
int crt(int r1,int r2,int r3)
{
	int k2=((r2-r1)%p2+p2)*1ll*iv1%p2;
	ll r12=k2*1ll*p1+r1;
	int k3=((r3-r12)%p3+p3)*1ll*iv12%p3;
	return(r12+k3*1ll*p12)%mod;
}
ll n,k;
int d[1111111];
void mul(int*f,int*g)
{
	/*
	register int i,ii;
	for(i=0;i<=k;i++)
		for(ii=0;ii<=k-i;ii++)
			d[i+ii]=(d[i+ii]+f[i]*1ll*g[ii])%mod;
	for(i=0;i<=k;i++)f[i]=d[i],d[i]=0;
	*/
	F1.load(f,k+1),G1.load(g,k+1),F2.load(f,k+1),G2.load(g,k+1),
	F3.load(f,k+1),G3.load(g,k+1),F1=F1*G1,F2=F2*G2,F3=F3*G3;
	for(register int i=0;i<=k;i++)f[i]=crt(F1.f[i],F2.f[i],F3.f[i])%mod;
}
int ans[1111111],tmp[1111111],exf[1111111];
void solve(int N)
{
	register int i;
	if(N==1){for(i=0;i<=k;i++)ans[i]=exf[i];return;}
	solve(N>>1);
	int K=qpow(2,N>>1,mod),K0=1;
	for(i=0;i<=k;i++)tmp[i]=ans[i]*1ll*K0%mod,K0=K0*1ll*K%mod;
	mul(ans,tmp);
	if(N&1)
	{
		K=qpow(2,N-1,mod),K0=1;
		for(i=0;i<=k;i++)tmp[i]=exf[i]*1ll*K0%mod,K0=K0*1ll*K%mod;
		mul(ans,tmp);
	}
}
int fac[1111111],inv[1111111];
int C(int N,int R){return fac[N]*1ll*inv[R]%mod*inv[N-R]%mod;}
int main()
{
	scanf("%lld%lld",&n,&k);
	if(n>k)return puts("0"),0;
	register int i;
	for(i=fac[0]=1;i<=k;i++)fac[i]=fac[i-1]*1ll*i%mod;
	for(inv[i=k]=qpow(fac[k],mod-2,mod);i;i--)inv[i-1]=inv[i]*1ll*i%mod;
	for(i=1;i<=k;i++)exf[i]=inv[i];
	ans[0]=1,solve(n);
	int S=0;
	for(i=0;i<=k;i++)S=(S+C(k,i)*1ll*ans[i]%mod*fac[i])%mod;
	printf("%d\n",S);
}