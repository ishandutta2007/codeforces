/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
namespace Poly{
const int N=1<<20;
const int mod=998244353;
const int G=3;
int rev[N],povG[N],invG[N];
int ksm(int x,int y=mod-2){int z=1;for(;y;x=1ll*x*x%mod,y>>=1)if(y&1)z=1ll*z*x%mod;return z;}
void init(){
	for(int md=1;md<N;md<<=1)povG[md]=ksm(G,(mod-1)/(md<<1)),invG[md]=ksm(povG[md]);
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
int A[N],B[N];
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
}using namespace Poly;
const int inv2=499122177;
int fac[N],inv[N],n,LG,f[N],g[N],h[N],res,ibn[N];
int C(int x,int y){return x<y?0:1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
void mina(){
	scanf("%d",&n),res=0;
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	ibn[0]=1;for(int i=1;i<=n;i++)ibn[i]=1ll*ibn[i-1]*inv2%mod;
	LG=0;while((1<<LG)<=n)LG++;
	for(int j=0;j<=n;j+=2){
		int yaw=1ll*fac[j]%mod*ibn[j>>1]%mod*inv[j>>1]%mod;
		g[j]=1ll*yaw*inv[j]%mod;
	}
	mul(g,inv,h,LG+1);
	for(int i=0;i<=n;i+=4){
		int _=i>>1;
		int way=1ll*C(n-_,_)*fac[_]%mod*inv[_>>1]%mod;
		res=(1ll*way*h[n-i]%mod*fac[n-i]%mod+res)%mod;
	}
	printf("%d\n",res);
}
int T;
int main(){
	init();
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}