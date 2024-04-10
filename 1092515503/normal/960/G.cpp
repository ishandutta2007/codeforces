#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
const int mod=998244353;
const int G=3;
int rev[N],fac[N],inv[N],lim,invlim,pre,suf;
int ksm(int x,int y){
	int rt=1;
	for(;y;x=(1ll*x*x)%mod,y>>=1)if(y&1)rt=(1ll*rt*x)%mod;
	return rt;
}
void NTT(int *a,int tp){
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
void mul(int *a,int *b,int *c,int len){
	for(int i=0;i<lim;i++)A[i]=B[i]=0;
	for(int i=0;i<=len;i++)A[i]=a[i],B[i]=b[i];
	NTT(A,1),NTT(B,1);
	for(int i=0;i<lim;i++)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1);
	for(int i=0;i<=(len<<1);i++)c[i]=A[i];
}
int a[N],b[N],c[N];
void func(int m){
	if(!m){a[0]=1;return;}
	int half=(m>>1);
	func(half);
	int LG=0;
	while((1<<LG)<=(half<<1))LG++;
	lim=(1<<LG),invlim=ksm(lim,mod-2);
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(LG-1));
	b[half]=1;
	for(int i=half-1;i>=0;i--)b[i]=1ll*b[i+1]*half%mod;
	for(int i=0;i<=half;i++)b[i]=1ll*b[i]*inv[half-i]%mod;
	for(int i=0;i<=half;i++)c[i]=1ll*fac[i]*a[i]%mod;
	mul(b,c,b,half);
	for(int i=0;i<=half;i++)b[i]=1ll*b[i+half]*inv[i]%mod;
	mul(b,a,a,half);
	if(!(m&1))return;
	a[m]=0;
	for(int i=m;i;i--)a[i]=(1ll*a[i]*(m-1)%mod+a[i-1])%mod;
	a[0]=1ll*a[0]*(m-1)%mod;
}
int n;
int main(){
	scanf("%d%d%d",&n,&pre,&suf),n--;
	if(n<pre+suf-2){puts("0");return 0;}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	func(n);
	printf("%d\n",1ll*a[pre+suf-2]*fac[pre+suf-2]%mod*inv[pre-1]%mod*inv[suf-1]%mod);
	return 0;
}