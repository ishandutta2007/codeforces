#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
const int mod=998244353;
int n,g[N],f[3][N],all,res;
//g:the number of partitions when there is no separating point
//f0:the number of partitions that there could be separating points, and there is no matched places on either border
//f1:there is exact one matched place on one border
//f2:there're matched places on both borders
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
#define sqr(x) 1ll*(x)*(x)%mod
void ADD(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int A[N],B[N];
void CDQ(int l,int LG){
	if(!LG){ADD(f[0][l],sqr(l)*g[l]%mod),ADD(f[1][l],sqr(l+1)*g[l]%mod),ADD(f[2][l],sqr(l+2)*g[l]%mod);return;}
	CDQ(l,LG-1);
	int lim=(1<<LG);
//----------------------0------------------------------	
	for(int i=0;i<(lim<<1);i++)A[i]=B[i]=0;
	for(int i=0;i<lim;i++)A[i]=sqr(i)*g[i]%mod;
	for(int i=0;i<(lim>>1);i++)B[i]=f[0][l+i];
	NTT(A,1,LG+1),NTT(B,1,LG+1);
	for(int i=0;i<(lim<<1);i++)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1,LG+1);
	for(int i=(lim>>1);i<lim;i++)if(i-1>=0)ADD(f[0][l+i],A[i-1]);
	
	for(int i=0;i<(lim<<1);i++)A[i]=B[i]=0;
	for(int i=0;i<lim;i++)A[i]=sqr(i+1)*g[i]%mod;
	for(int i=0;i<(lim>>1);i++)B[i]=f[1][l+i];
	NTT(A,1,LG+1),NTT(B,1,LG+1);
	for(int i=0;i<(lim<<1);i++)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1,LG+1);
	for(int i=(lim>>1);i<lim;i++)if(i-3>=0)ADD(f[0][l+i],A[i-3]);
//----------------------1------------------------------
	for(int i=0;i<(lim<<1);i++)A[i]=B[i]=0;
	for(int i=0;i<lim;i++)A[i]=sqr(i+1)*g[i]%mod;
	for(int i=0;i<(lim>>1);i++)B[i]=f[0][l+i];
	NTT(A,1,LG+1),NTT(B,1,LG+1);
	for(int i=0;i<(lim<<1);i++)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1,LG+1);
	for(int i=(lim>>1);i<lim;i++)if(i-1>=0)ADD(f[1][l+i],A[i-1]);
	
	for(int i=0;i<(lim<<1);i++)A[i]=B[i]=0;
	for(int i=0;i<lim;i++)A[i]=sqr(i+2)*g[i]%mod;
	for(int i=0;i<(lim>>1);i++)B[i]=f[1][l+i];
	NTT(A,1,LG+1),NTT(B,1,LG+1);
	for(int i=0;i<(lim<<1);i++)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1,LG+1);
	for(int i=(lim>>1);i<lim;i++)if(i-3>=0)ADD(f[1][l+i],A[i-3]);
//----------------------2------------------------------
	for(int i=0;i<(lim<<1);i++)A[i]=B[i]=0;
	for(int i=0;i<lim;i++)A[i]=sqr(i+1)*g[i]%mod;
	for(int i=0;i<(lim>>1);i++)B[i]=f[1][l+i];
	NTT(A,1,LG+1),NTT(B,1,LG+1);
	for(int i=0;i<(lim<<1);i++)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1,LG+1);
	for(int i=(lim>>1);i<lim;i++)if(i-1>=0)ADD(f[2][l+i],A[i-1]);
	
	for(int i=0;i<(lim<<1);i++)A[i]=B[i]=0;
	for(int i=0;i<lim;i++)A[i]=sqr(i+2)*g[i]%mod;
	for(int i=0;i<(lim>>1);i++)B[i]=f[2][l+i];
	NTT(A,1,LG+1),NTT(B,1,LG+1);
	for(int i=0;i<(lim<<1);i++)A[i]=1ll*A[i]*B[i]%mod;
	NTT(A,-1,LG+1);
	for(int i=(lim>>1);i<lim;i++)if(i-3>=0)ADD(f[2][l+i],A[i-3]);
	
	CDQ(l+(lim>>1),LG-1);
} 
int main(){
	scanf("%d",&n);
	while((1<<all)<=n)all++;
	g[0]=g[2]=1,g[1]=g[3]=0;
	for(int i=4;i<(1<<all);i++)g[i]=(g[i-2]+g[i-4])%mod;
	CDQ(0,all);
	res=sqr(n-1)*n%mod*(g[n-1]+g[n-3])%mod;
	for(int i=0;i<n;i++){
		if(i-1>=0&&n-i-1>=0)ADD(res,sqr(i-1)*i%mod*g[i-1]%mod*f[0][n-i-1]%mod);
		if(i-2>=0&&n-i-2>=0)ADD(res,2*sqr(i-1)*i%mod*g[i-2]%mod*f[1][n-i-2]%mod);
		if(i-3>=0&&n-i-3>=0)ADD(res,sqr(i-1)*i%mod*g[i-3]%mod*f[2][n-i-3]%mod);
	}
	printf("%d\n",res);
	return 0;
}