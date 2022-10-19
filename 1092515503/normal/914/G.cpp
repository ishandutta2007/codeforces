#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int inv2=5e8+4;
#define bit __builtin_popcount
int m,a[18][1<<17],b[1<<17],c[1<<17],d[1<<17],e[1<<17],n=17,lim=1<<17,res;
void FMTOR(int *f,int tp){
	for(int i=0;i<n;i++)for(int j=0;j<lim;j++)if(j&(1<<i))(f[j]+=(mod+tp*f[j^(1<<i)])%mod)%=mod;
}
void FMTAND(int *f,int tp){
	for(int i=0;i<n;i++)for(int j=0;j<lim;j++)if(j&(1<<i))(f[j^(1<<i)]+=(mod+tp*f[j])%mod)%=mod;
}
void FWTXOR(int *f,int tp){
	for(int md=1;md<lim;md<<=1)for(int stp=md<<1,pos=0;pos<lim;pos+=stp)for(int i=0;i<md;i++){
		int x=f[pos+i],y=f[pos+md+i];
		f[pos+i]=(x+y)%mod;
		f[pos+md+i]=(x-y+mod)%mod;
		if(tp==-1)f[pos+i]=1ll*f[pos+i]*inv2%mod,f[pos+md+i]=1ll*f[pos+md+i]*inv2%mod;
	}
}
int main(){
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++)scanf("%d",&x),a[bit(x)][x]++,c[x]++,d[x]++;
	for(int i=0;i<=n;i++)FMTOR(a[i],1);
	for(int i=n;i>=0;i--)for(int j=0;j<lim;j++){
		int x=0;
		for(int k=0;k<=i;k++)(x+=1ll*a[k][j]*a[i-k][j]%mod)%=mod;
		a[i][j]=x;
	}
	for(int i=0;i<=n;i++)FMTOR(a[i],-1);
	for(int i=0;i<lim;i++)b[i]=a[bit(i)][i];
	FWTXOR(d,1);
	for(int i=0;i<lim;i++)d[i]=1ll*d[i]*d[i]%mod;
	FWTXOR(d,-1);
	e[0]=0,e[1]=1;for(int i=2;i<lim;i++)e[i]=(e[i-1]+e[i-2])%mod;
	for(int i=0;i<lim;i++)b[i]=1ll*b[i]*e[i]%mod,c[i]=1ll*c[i]*e[i]%mod,d[i]=1ll*d[i]*e[i]%mod;
	FMTAND(b,1),FMTAND(c,1),FMTAND(d,1);
	for(int i=0;i<lim;i++)e[i]=1ll*b[i]*c[i]%mod*d[i]%mod;
	FMTAND(e,-1);
	for(int i=0;i<n;i++)(res+=e[1<<i])%=mod;
	printf("%d\n",res);
	return 0;
}