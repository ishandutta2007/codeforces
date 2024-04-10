#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int G=3;
const int lim=1<<20,lg=20;
int n,m,cnt[lim+10],s1[lim+10],s2[lim+10],f[lim+10],g[lim+10],res[lim+10],invlim,fac[lim+10],invfac[lim+10],rev[lim+10];
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
int C(int n,int m){
	if(m>n)return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main(){
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	fac[0]=invfac[0]=1;
	for(int i=1;i<lim;i++)fac[i]=(1ll*fac[i-1]*i)%mod;
	invfac[lim-1]=ksm(fac[lim-1],mod-2);
	for(int i=lim-2;i>=1;i--)invfac[i]=(1ll*invfac[i+1]*(i+1))%mod;
	invlim=ksm(lim,mod-2);
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),cnt[x]++;
	for(int i=1;i<lim;i++)s1[i]=s1[i-1]+(cnt[i]==1),s2[i]=s2[i-1]+(cnt[i]>=2);
	for(int i=1,x,u,v;i<=m;i++){
		scanf("%d",&x),u=s1[x-1],v=s2[x-1];
		for(int j=0;j<lim;j++)f[j]=1ll*C(u,j)*ksm(2,j)%mod,g[j]=C(v*2,j);
		NTT(f,1),NTT(g,1);
		for(int j=0;j<lim;j++)f[j]=(1ll*f[j]*g[j])%mod;
		NTT(f,-1);
		for(int j=0;j<lim-x-1;j++)res[j+x+1]=(res[j+x+1]+f[j])%mod;
	}
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++)scanf("%d",&x),printf("%d\n",res[x/2]);
	return 0;
}