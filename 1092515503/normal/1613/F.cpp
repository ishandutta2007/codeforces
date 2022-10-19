#include<bits/stdc++.h>
using namespace std;
namespace Poly{
const int N=1<<20;
const int mod=998244353;
const int G=3;
int rev[N],povG[N],invG[N];
int ksm(int x,int y=mod-2){int z=1;for(;y;x=1ll*x*x%mod,y>>=1)if(y&1)z=1ll*z*x%mod;return z;}
void init(){
	for(int md=1;md<N;md<<=1)povG[md]=ksm(G,(mod-1)/(md<<1)),invG[md]=ksm(povG[md],mod-2);
}
int lim,invlim;
void NTT(int *a,int tp,int LG){
	for(int i=0;i<lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int md=1;md<lim;md<<=1){
		int rt=(tp==-1?invG[md]:povG[md]);
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
	lim=(1<<LG),invlim=ksm(lim,mod-2);
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(LG-1));
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
void diff(int *a,int *b,int len){
	for(int i=0;i<len;i++)b[i]=1ll*a[i+1]*(i+1)%mod;
	b[len-1]=0;
}
void inte(int *a,int *b,int len){
	for(int i=len-1;i;i--)b[i]=1ll*a[i-1]*ksm(i,mod-2)%mod;
	b[0]=0;
}
void ln(int *a,int *b,int LG){//using: Array C
	inv(a,b,LG);
	diff(a,C,1<<LG);
	mul(b,C,b,LG+1);
	inte(b,b,1<<LG);
}
void exp(int *a,int *b,int LG){//using: Array D
	b[0]=1;
	for(int k=1;k<=LG+1;k++){
		ln(b,D,k-1);
		for(int i=0;i<(1<<(k-1));i++)D[i]=(a[i]-D[i]+mod)%mod;
		D[0]=(D[0]+1)%mod;
		mul(b,D,b,k);
	}
}
}using namespace Poly;
int n,deg[N],f[N],g[N],LG,sum,fac[N],INV[N],res,prod=1,cnt[N];
int main(){
	scanf("%d",&n),init();
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),deg[x]++,deg[y]++;
	for(int i=2;i<=n;i++)deg[i]--;
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	INV[1]=1;for(int i=2;i<=n;i++)INV[i]=1ll*INV[mod%i]*(mod-mod/i)%mod;
	while((1<<LG)<=n)LG++;
	for(int i=1;i<=n;i++){
		if(!deg[i]){sum++;continue;}
		prod=1ll*prod*deg[i]%mod;
		cnt[deg[i]]++;
	} 
	for(int i=1;i<=n;i++)if(cnt[i])
		for(int j=1,k=INV[i],l=1ll*k*cnt[i]%mod;j<=n;j++,l=1ll*l*k%mod)
			(f[j]+=l)%=mod;
	for(int i=1;i<=n;i++){
		f[i]=1ll*f[i]*INV[i]%mod;
		if(!(i&1))f[i]=mod-f[i];
	}
	exp(f,g,LG);
	for(int i=0;i+sum<=n;i++)
		if((n-i-sum)&1)(res+=mod-1ll*fac[i+sum]*g[i]%mod)%=mod;
		else(res+=1ll*fac[i+sum]*g[i]%mod)%=mod;
	printf("%d\n",1ll*res*prod%mod);
	return 0;
}