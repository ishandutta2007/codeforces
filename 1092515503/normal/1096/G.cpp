#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int G=3;
int n,bs[1<<20],lim=1,lg,m,invlim,rev[1<<20],f[1<<20],g[1<<20],qaq[1<<20],res;
inline int pov(int x,int y){
	int res=1;
	for(;y;x=(1ll*x*x)%mod,y>>=1)if(y&1)res=(1ll*res*x)%mod;
	return res;
}
inline void NTT(int *a,int tp){
	for(register int i=0;i<lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(register int md=1;md<lim;md<<=1){
		register int rt=pov(G,(mod-1)/(md<<1));
		if(tp==-1)rt=pov(rt,mod-2);
		for(register int stp=md<<1,pos=0;pos<lim;pos+=stp){
			register int w=1;
			for(register int i=0;i<md;i++,w=(1ll*w*rt)%mod){
				register int x=a[pos+i],y=(1ll*w*a[pos+md+i])%mod;
				a[pos+i]=(x+y)%mod;
				a[pos+md+i]=(x-y+mod)%mod;
			}
		}
	}
}
inline void mul(int *a,int *b,int *c){
	for(register int i=0;i<lim;i++)f[i]=a[i],g[i]=b[i];
	NTT(f,1),NTT(g,1);
	for(register int i=0;i<lim;i++)f[i]=(1ll*f[i]*g[i])%mod;
	NTT(f,-1);
	for(register int i=0;i<lim;i++)c[i]=(1ll*f[i]*invlim)%mod;
}
inline void ksm(int x){
	if(x==1){while(lim<x*10)lim<<=1,lg++;for(register int i=0;i<10;i++)qaq[i]=bs[i];return;}
	ksm(x>>1);
	while(lim<x*10)lim<<=1,lg++;
	invlim=pov(lim,mod-2);
	for(register int i=1;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	mul(qaq,qaq,qaq);
	if(x&1)mul(qaq,bs,qaq);
}
int main(){
	scanf("%d%d",&n,&m),n>>=1;
	for(register int i=0,x;i<m;i++)scanf("%d",&x),bs[x]++;
	ksm(n);
	for(register int i=0;i<lim;i++)res=(1ll*qaq[i]*qaq[i]%mod+res)%mod;
	printf("%d\n",res);
	return 0;
}