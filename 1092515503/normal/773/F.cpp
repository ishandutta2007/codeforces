#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<20;
int n,m,p,res,all;
int ksm(int x,int y,int mod){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int INV(int x,int mod){return ksm(x,mod-2,mod);}
void ADD(int &x,int y){x+=y;if(x>=p)x-=p;}
int RED(int x){if(x>=p)x-=p;return x;}
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
	}poly[2];
	const int mod0=998244353,mod1=1004535809;
	const int inv0=INV(mod0,mod1);
	void MTT(int *a,int *b,int *c,int LG){
		for(int i=0;i<2;i++)poly[i].mul(a,b,LG);
		for(int i=0;i<(1<<LG);i++)c[i]=(1ll*(poly[1].A[i]-poly[0].A[i]+mod1)%mod1*inv0%mod1*mod0+poly[0].A[i])%p;
	}
	int f[2][N];
	int A[N],B[N],C[N];
	void KSM(int k,int LG){
		if(k==0)return;
		KSM(k>>1,LG);
		for(int i=0;i<=n;i++)C[i]=RED(f[0][i]+f[1][i]);ADD(C[0],1);
		if(k&2)MTT(f[0],C,B,LG),MTT(f[1],C,A,LG);
		else MTT(f[0],C,A,LG),MTT(f[1],C,B,LG);
		for(int i=0;i<=n;i++)ADD(f[0][i],A[i]),ADD(f[1][i],B[i]);
		if(k&1){
			for(int i=0;i<=n;i++)C[i]=RED(f[0][i]+f[1][i]);ADD(C[0],1);
			for(int i=1;i<=n;i++)ADD(f[1][i],C[i-1]);	
		}
		for(int i=1;i<=n;i+=2)ADD(res,f[1][i]);
	}
	void prep(){poly[0].mod=mod0,poly[1].mod=mod1;}
}
int main(){
	scanf("%d%d%d",&n,&m,&p),xtx::prep();
	while((1<<all)<=n)all++;
	xtx::KSM(m>>1,all+1);
	printf("%d\n",res);
	return 0;
}