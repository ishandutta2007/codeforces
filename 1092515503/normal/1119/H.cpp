#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int inv2=499122177;
const int inv4=748683265;
int m,n,X,Y,Z,u[100100],v[100100],A,lim,k1[1<<17],k2[1<<17],k3[1<<17],S[1<<17];
int ksm(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
void FWT(int *f,int tp){
	for(int md=1;md<lim;md<<=1)for(int stp=md<<1,pos=0;pos<lim;pos+=stp)for(int i=0;i<md;i++){
		int x=f[pos+i],y=f[pos+md+i];
		f[pos+i]=(x+y)%mod;
		f[pos+md+i]=(x+mod-y)%mod;
		if(tp==-1)f[pos+i]=1ll*f[pos+i]*inv2%mod,f[pos+md+i]=1ll*f[pos+md+i]*inv2%mod; 
	}
}
int main(){
	scanf("%d%d%d%d%d",&m,&n,&X,&Y,&Z),lim=1<<n;
	for(int i=1,a,b,c;i<=m;i++)scanf("%d%d%d",&a,&b,&c),u[i]=a^b,v[i]=a^c,A^=a;
	for(int i=1;i<=m;i++)k1[u[i]]++;FWT(k1,1);
	for(int i=1;i<=m;i++)k2[v[i]]++;FWT(k2,1);
	for(int i=1;i<=m;i++)k3[u[i]^v[i]]++;FWT(k3,1);
	for(int i=0;i<lim;i++){
		int t0=(0ll+m+k1[i]+k2[i]+k3[i])*inv4%mod;
		int t1=(1ll*(m+k1[i])*inv2%mod+mod-t0)%mod;
		int t2=(1ll*(m+k2[i])*inv2%mod+mod-t0)%mod;
		int t3=(1ll*(m+k3[i])*inv2%mod+mod-t0)%mod;
		S[i]=1ll*ksm((0ll+X+Y+Z)%mod,t0)*ksm((0ll+X+Y-Z+mod)%mod,t1)%mod*ksm((0ll+X-Y+Z+mod)%mod,t2)%mod*ksm((0ll+X-Y-Z+mod+mod)%mod,t3)%mod;
	}
	FWT(S,-1);
	for(int i=0;i<lim;i++)printf("%d ",S[i^A]);
	return 0;
}