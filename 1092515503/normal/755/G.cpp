#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int G=3;
int n,m,lim=1,invlim,lg,rev[1<<16],f[3][1<<16],g[3][1<<16],a[1<<16],b[1<<16],cnt;
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
void mul(int *u,int *v,int *w){
	for(int i=0;i<lim;i++)a[i]=b[i]=0;
	for(int i=0;i<=m;i++)a[i]=u[i],b[i]=v[i];
	NTT(a,1),NTT(b,1);
	for(int i=0;i<lim;i++)a[i]=(1ll*a[i]*b[i])%mod;
	NTT(a,-1);
	for(int i=0;i<=m;i++)w[i]=(a[i]+w[i])%mod;
}
void combine(int x,int y,int z){
	for(int i=0;i<=m;i++)g[z][i]=0;
	mul(f[x],f[y],g[z]);
	mul(f[x-1],f[y-1],g[z]+1);
	g[z][m+1]=0;
}
void forward(int *x,int *y,int *z){
	z[0]=y[0];
	for(int i=1;i<=m;i++)z[i]=(0ll+x[i-1]+y[i-1]+y[i])%mod;
}
void work(){
	if(n==1){f[2][0]=f[2][1]=1;return;}
	f[0][0]=f[1][0]=f[1][1]=f[2][0]=f[2][2]=1,f[2][1]=3;
	int bd=30;
	while(!(n&(1<<bd)))bd--;
	for(int i=bd-1;i>=0;i--){
		if(n&(1<<i)){
			forward(f[1],f[2],f[0]);
			for(int j=0,tt;j<=m;j++)tt=f[0][j],f[0][j]=f[1][j],f[1][j]=f[2][j],f[2][j]=tt;
		}
		if(i){
			combine(2,2,2),combine(2,1,1),combine(1,1,0);
			for(int j=0;j<=m;j++)f[0][j]=g[0][j],f[1][j]=g[1][j],f[2][j]=g[2][j];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	while(lim<=2*m)lim<<=1,lg++;
	invlim=ksm(lim,mod-2);
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	work();
	for(int i=1;i<=m;i++)printf("%d ",f[2][i]);puts("");
	return 0;
}