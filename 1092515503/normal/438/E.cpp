#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
int n,m,f[N],g[N],all;
namespace Poly{
	const int mod=998244353;
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
	int A[N],B[N],C[N],D[N],E[N];
	void mul(int *a,int *b,int *c,int LG){//using: Array A and B
		int lim=(1<<LG);
		for(int i=0;i<lim;i++)A[i]=B[i]=0;
		for(int i=0;i<(lim>>1);i++)A[i]=a[i],B[i]=b[i];
		NTT(A,1,LG),NTT(B,1,LG);
		for(int i=0;i<lim;i++)A[i]=1ll*A[i]*B[i]%mod;
		NTT(A,-1,LG);
		for(int i=0;i<lim;i++)c[i]=A[i];
	}
	void inv(int *a,int *b,int LG){//using: Array C
		b[0]=ksm(a[0],mod-2);
		for(int k=1;k<=LG+1;k++){
			mul(b,a,C,k);
			for(int i=0;i<(1<<k);i++)C[i]=(mod-C[i])%mod;
			(C[0]+=2)%=mod;
			mul(C,b,b,k);
		}
	}
	void diff(int *a,int *b,int lim){
		for(int i=0;i<lim;i++)b[i]=1ll*a[i+1]*(i+1)%mod;
		b[lim-1]=0;
	}
	void inte(int *a,int *b,int lim){
		for(int i=lim-1;i;i--)b[i]=1ll*a[i-1]*ksm(i,mod-2)%mod;
		b[0]=0;
	}
	void sqrt(int *a,int *b,int LG){//using:arrays D&E
		b[0]=1;
		for(int k=1;k<=LG+1;k++){
			for(int i=0;i<(1<<(k-1));i++)D[i]=(b[i]<<1)%mod;
			inv(D,E,k-1);
			mul(b,b,b,k);
			for(int i=0;i<(1<<(k-1));i++)(b[i]+=a[i])%=mod;
			mul(b,E,b,k);
		}
	}
}
using namespace Poly;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),g[x]=mod-4;
	g[0]++;
	while((1<<all)<=m)all++;
	sqrt(g,f,all);
	f[0]++;
	inv(f,g,all);
	for(int i=1;i<=m;i++)printf("%d\n",(g[i]<<1)%mod);
	return 0;
}