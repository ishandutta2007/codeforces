#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<20;
ll n;
int m,f[N],all,res;
int fac[N],inv[N],bin[N];
const int p=1e9+7;
int ksm(int x,int y,int mod){
	int rt=1;
	for(;y;x=(1ll*x*x)%mod,y>>=1)if(y&1)rt=(1ll*rt*x)%mod;
	return rt;
}
int INV(int x,int y){return ksm(x,y-2,y);}
namespace xtx{
	struct Poly{
		int mod;
		const int G=3;
		int rev[N];
		int ksm(int x,int y){
			int rt=1;
			for(;y;x=(1ll*x*x)%mod,y>>=1)if(y&1)rt=(1ll*rt*x)%mod;
			return rt;
		}
		void NTT(int *a,int tp,int LG){
			int lim=(1<<LG),invlim=ksm(lim,mod-2);
			for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(LG-1));
			for(int i=0;i<lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
			for(int md=1;md<lim;md<<=1){
				int rt=ksm(G,(mod-1)/(md<<1));
				if(tp==-1)rt=ksm(rt,mod-2);
				for(int stp=md<<1,pos=0;pos<lim;pos+=stp){
					int w=1;
					for(int i=0;i<md;i++,w=(1ll*w*rt)%mod){
						int x=a[pos+i],y=(1ll*w*a[pos+md+i])%mod;
						a[pos+i]=(x+y)%mod;
						a[pos+md+i]=(x-y+mod)%mod;
					}
				}
			}
			if(tp==-1)for(int i=0;i<lim;i++)a[i]=(1ll*a[i]*invlim)%mod;
		}
		int A[N],B[N];
		void mul(int *a,int *b,int LG){//using: Array A and B
			int lim=(1<<LG);
			for(int i=0;i<lim;i++)A[i]=B[i]=0;
			for(int i=0;i<(lim>>1);i++)A[i]=a[i],B[i]=b[i];
			NTT(A,1,LG),NTT(B,1,LG);
			for(int i=0;i<lim;i++)A[i]=1ll*A[i]*B[i]%mod;
			NTT(A,-1,LG);
		}
	}poly[3];
	const int mod0=998244353,mod1=1004535809,mod2=469762049;
	const ll mod01=1ll*mod0*mod1;
	const int inv0=INV(mod0,mod1),inv01=INV(mod01%mod2,mod2);
	void MTT(int *a,int *b,int *c,int LG){
		for(int i=0;i<3;i++)poly[i].mul(a,b,LG);
		for(int i=0;i<(1<<LG);i++){
			ll x=1ll*(poly[1].A[i]-poly[0].A[i]+mod1)%mod1*inv0%mod1*mod0+poly[0].A[i];
			c[i]=(1ll*(poly[2].A[i]-x%mod2+mod2)%mod2*inv01%mod2*(mod01%p)%p+x)%p;
		}
	}
	int A[N];
	void KSM(int *a,int k,int LG){
		if(k==1){a[0]=0;for(int i=1;i<=m;i++)a[i]=1;return;}
		KSM(a,k>>1,LG);
		for(int i=0;i<=m;i++)A[i]=1ll*a[i]*ksm(bin[i],k>>1,p)%p*inv[i]%p;
		for(int i=0;i<=m;i++)a[i]=1ll*a[i]*inv[i]%p;
		MTT(A,a,a,LG);
		for(int i=0;i<=m;i++)a[i]=1ll*a[i]*fac[i]%p;
		if(!(k&1))return;
		for(int i=0;i<=m;i++)a[i]=1ll*a[i]*bin[i]%p*inv[i]%p,A[i]=0;
		for(int i=1;i<=m;i++)A[i]=inv[i];
		MTT(A,a,a,LG);
		for(int i=0;i<=m;i++)a[i]=1ll*a[i]*fac[i]%p;
		for(int i=0;i<k;i++)a[i]=0;
	}
	void prep(){poly[0].mod=mod0,poly[1].mod=mod1,poly[2].mod=mod2;}
}
int main(){
	scanf("%lld%d",&n,&m),xtx::prep();
	if(n>m){puts("0");return 0;}
	while((1<<all)<=m)all++;
	fac[0]=bin[0]=1;
	for(int i=1;i<=m;i++)fac[i]=1ll*fac[i-1]*i%p,bin[i]=(bin[i-1]<<1)%p;
	inv[m]=INV(fac[m],p);
	for(int i=m-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%p;
	xtx::KSM(f,n,all+1);
	for(int i=1;i<=m;i++)(res+=1ll*f[i]*fac[m]%p*inv[i]%p*inv[m-i]%p)%=p;
	printf("%d\n",res);
	return 0;
}