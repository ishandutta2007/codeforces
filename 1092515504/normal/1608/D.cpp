#include<bits/stdc++.h>
using namespace std;
int n,cnt[3][3];
int HS(char x){
	if(x=='B')return 0;
	if(x=='W')return 1;
	return 2;
}
char s[10];
namespace Poly{
	const int N=1<<20;
	const int mod=998244353;
	const int G=3;
	int rev[N],povG[N],invG[N];
	int ksm(int x,int y){
		int rt=1;
		for(;y;x=(1ll*x*x)%mod,y>>=1)if(y&1)rt=(1ll*rt*x)%mod;
		return rt;
	}
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
int f[N],g[N],h[N],fac[N],caf[N];
int main(){
	scanf("%d",&n),init();
	int LG=0;while((1<<LG)<=(n<<1))LG++;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		cnt[HS(s[0])][HS(s[1])]++;
	}
	f[0]=1;
	int lam=n;
	int sub=1;
	int q1=0,q2=0;
	for(int i=0;i<3;i++)for(int j=0;j<3;j++){
		g[0]=g[1]=g[2]=0;
		if(i!=1&&j!=1)g[0]++;
		if(i!=1&&j!=0)g[1]++,q1+=cnt[i][j];
		if(i!=0&&j!=1)g[1]++,q2+=cnt[i][j];
		if(i!=0&&j!=0)g[2]++;
		sub=1ll*sub*ksm(g[1],cnt[i][j])%mod;
		int qwq=0;while(!g[qwq])qwq++;
		lam-=cnt[i][j]*qwq;
		for(int k=0;k<3;k++)g[k]=g[k+qwq];
	}
	int tot=0;
	for(int i=0;i<3;i++)for(int j=0;j<3;j++){
		g[0]=g[1]=g[2]=0;
		if(i!=1&&j!=1)g[0]++;
		if(i!=1&&j!=0)g[1]++;
		if(i!=0&&j!=1)g[1]++;
		if(i!=0&&j!=0)g[2]++;
		int qwq=0;while(!g[qwq])qwq++;
		for(int k=0;k<3;k++)g[k]=g[k+qwq];
		if(g[0]==1&&g[1]==0&&g[2]==0)continue;
		if(g[0]==1&&g[1]==1&&g[2]==0)tot+=cnt[i][j];
		if(g[0]==1&&g[1]==2&&g[2]==1)tot+=cnt[i][j]<<1;
	}
	fac[0]=1;for(int i=1;i<=tot;i++)fac[i]=1ll*fac[i-1]*i%mod;
	caf[tot]=ksm(fac[tot],mod-2);for(int i=tot;i;i--)caf[i-1]=1ll*caf[i]*i%mod;
	int val=(lam<=tot?1ll*fac[tot]*caf[lam]%mod*caf[tot-lam]%mod:0);
//	printf("%d\n",lam);
	printf("%d\n",(val+mod-sub+(q1==n)+(q2==n))%mod);
	return 0;
}