#include<bits/stdc++.h>
using namespace std;
namespace Poly{
const int N=1<<20;
const int mod=998244353;
const int G=3;
int rev[N],povG[N],invG[N],INV[N];
int ksm(int x,int y=mod-2){int z=1;for(;y;x=1ll*x*x%mod,y>>=1)if(y&1)z=1ll*z*x%mod;return z;}
void init(){
	for(int md=1;md<N;md<<=1)povG[md]=ksm(G,(mod-1)/(md<<1)),invG[md]=ksm(povG[md]);
	INV[1]=1;for(int i=2;i<N;i++)INV[i]=1ll*INV[mod%i]*(mod-mod/i)%mod;
}
int lim,invlim;
int RED(int x){return x>=mod?x-mod:x;}
void ADJ(int&x){if(x>=mod)x-=mod;}
void NTT(int *a,int tp){
	for(int i=0;i<lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int md=1;md<lim;md<<=1)
		for(int pos=0,rt=(tp==-1?invG[md]:povG[md]);pos<lim;pos+=md<<1)
			for(int i=0,w=1;i<md;i++,w=1ll*w*rt%mod){
				int x=a[pos+i],y=1ll*w*a[pos+md+i]%mod;
				a[pos+i]=RED(x+y),a[pos+md+i]=RED(x+mod-y);
			}
	if(tp==-1)for(int i=0;i<lim;i++)a[i]=1ll*a[i]*invlim%mod;
}
int A[N],B[N],C[N],D[N],E[N];
void mul(int*a,int*b,int*c,int LG){//using: Array A and B
	invlim=ksm(lim=1<<LG);
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(LG-1));
	for(int i=0;i<lim;i++)A[i]=B[i]=0;
	for(int i=0;i<(lim>>1);i++)A[i]=a[i],B[i]=b[i];
	NTT(A,1),NTT(B,1);
	for(int i=0;i<lim;i++)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1);
	for(int i=0;i<lim;i++)c[i]=A[i];
}
void inv(int*a,int*b,int LG){//using: Array C
	b[0]=ksm(a[0]);
	for(int k=1;k<=LG+1;k++){
		mul(b,a,C,k);
		for(int i=0;i<(1<<k);i++)C[i]=RED(mod-C[i]);
		ADJ(C[0]+=2),mul(C,b,b,k);
	}
}
void diff(int*a,int*b,int len){for(int i=0;i<len;i++)b[i]=1ll*a[i+1]*(i+1)%mod;b[len-1]=0;}
void inte(int*a,int*b,int len){for(int i=len-1;i;i--)b[i]=1ll*a[i-1]*INV[i]%mod;b[0]=0;}
void ln(int*a,int*b,int LG){inv(a,b,LG),diff(a,C,1<<LG),mul(b,C,b,LG+1),inte(b,b,1<<LG);}
void exp(int*a,int*b,int LG){
	b[0]=1;
	for(int k=1;k<=LG+1;k++){
		ln(b,D,k-1);
		for(int i=0;i<(1<<(k-1));i++)D[i]=RED(a[i]-D[i]+mod);
		ADJ(++D[0]),mul(b,D,b,k);
	}
}
}using namespace Poly;
int n,fc[N],iv[N],LG,f[N],g[N];
int main(){
    init();
    scanf("%d",&n);
    while((1<<LG)<=n)LG++;
    fc[0]=1;for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
    iv[n]=ksm(fc[n]);for(int i=n;i;i--)iv[i-1]=1ll*iv[i]*i%mod;
    for(int i=1;i<=(n>>1);i++)f[i]=1ll*fc[i-1]*iv[i]%mod;
    exp(f,g,LG);
	// for(int i=1;i<=n;i++)printf("%d ",1ll*g[i]*fc[i]%mod);puts("");
    for(int i=0;i<(n>>1);i++)g[i]=0;
	printf("%d ",1ll*g[n-1]*fc[n-1]%mod);
	for(int i=0;i+1<n;i++)g[i]=1ll*g[i]*fc[n-i-2]%mod;g[n-1]=g[n]=0;
    mul(g,iv,f,LG+1);
    for(int i=2;i<=n;i++)printf("%d ",1ll*f[n-i]*fc[n-i]%mod*(i-1)%mod);
    return 0;
}