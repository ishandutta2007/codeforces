#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
const int G=3,Gi=332748118;
int n,lim,t,invn;
LL m;
int r[262152];
LL p[100002],fac[100002],inv[100002],A[262152],B[262152],w[262152],wi[262152];
inline LL Pow(int a,LL b)
{
	if(!b)return 1;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=n+1;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[n+1]=Pow(fac[n+1],mod-2);for(int i=n+1;i;--i)inv[i-1]=(inv[i]*i)%mod;
	for(t=-1,lim=1;lim<=(n<<1);lim<<=1,++t);
	for(int i=1;i<lim;++i)r[i]=((r[i>>1]>>1)|((i&1)<<t))%mod;
	int W=Pow(G,(mod-1)/lim),Wi=Pow(Gi,(mod-1)/lim),mid=(lim>>1);
	w[mid]=wi[mid]=1,invn=Pow(lim,mod-2);
	for(int i=mid+1;i<lim;++i)w[i]=(w[i-1]*W)%mod,wi[i]=(wi[i-1]*Wi)%mod;
	for(int i=mid-1;i>=0;--i)w[i]=w[i<<1],wi[i]=wi[i<<1];
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%mod)*inv[a-b])%mod;
}
inline void NTT(LL *A,int o)
{
	for(int i=0;i<lim;++i)if(i<r[i])swap(A[i],A[r[i]]);
	for(int i=1,t;i<lim;i<<=1)for(int j=0;j<lim;j+=(i<<1))for(int k=0;k<i;++k)t=((~o? w[i+k]:wi[i+k])*A[i+j+k])%mod,A[i+j+k]=(A[j+k]-t)%mod,(A[j+k]+=t)%=mod;
}
inline void Mul(LL *A,LL *B)
{
	NTT(A,1),NTT(B,1);
	for(int i=0;i<lim;++i)(A[i]*=B[i])%=mod;
	NTT(A,-1);
	for(int i=0;i<lim;++i)(A[i]*=invn)%=mod;
}
int main()
{
	scanf("%d%lld",&n,&m),init();
	for(int i=0;i<=n;++i)scanf("%lld",&p[i]),A[i]=(fac[i]*p[i])%mod,B[i]=inv[n-i];
	Mul(A,B);
	for(int i=0;i<=n;++i)(((p[i]=A[i+n]*inv[i])%=mod)*=Pow((inv[i+1]*fac[i])%mod,m))%=mod,A[i]=((i&1? -1:1)*fac[i]*p[i])%mod,B[i]=inv[n-i];
	for(int i=n+1;i<lim;++i)A[i]=B[i]=0;
	Mul(A,B);
	for(int i=0;i<=n;++i)printf("%lld ",(((A[i+n]*(i&1? -1:1)*inv[i])%mod)+mod)%mod);
	return 0;
}