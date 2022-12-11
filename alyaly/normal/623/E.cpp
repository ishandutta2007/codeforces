#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define int long long
#define P 1000000007
#define N 30003
#define M 30003
using namespace std;
int n,K,logn[4*N+1],rev[4*M+1],w[M+1],jc[N+1],njc[N+1],pw2[70*N+1],pw21[N+1],ans;
int Pm[4]={0,469762049,998244353,1004535809};
struct poly{int a[4*M+1];}g[17],p0,p1,ap[5];
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
int ksm(int x,int y){int nans=1;for(;y;y>>=1,x=x*x%P)if(y&1)nans=nans*x%P;return nans;}
int ksm1(int x,int y,int np){int nans=1;for(;y;y>>=1,x=x*x%np)if(y&1)nans=nans*x%np;return nans;}
int ksa(int x,int y,int np){int nans=0;for(;y;y>>=1,x=2*x%np)if(y&1)nans+=x,nans%=np;return nans;}
int qny(int x){return ksm(x,P-2);}
int C(int x,int y){if(y>x||y<0)return 0;return jc[x]*njc[y]%P*njc[x-y]%P;}
int nat(int x){return (1<<(logn[x-1]+1));}
void dft(poly&x,int len,int nfl,int npp){
	for(int i=0;i<len;i++){rev[i]=rev[i>>1]>>1;if(i&1)rev[i]|=(len>>1);}
	for(int i=0;i<len;i++)if(i<rev[i])swap(x.a[i],x.a[rev[i]]);
	for(int i=2;i<=len;i*=2){
		int ni=ksm1(3,(Pm[npp]-1)/i,Pm[npp]);if(nfl==-1)ni=ksm1(ni,Pm[npp]-2,Pm[npp]);
		for(int j=0;j<len;j+=i){
			int nt=1;
			for(int k=j;k<j+i/2;k++){
				int np=x.a[k],nq=x.a[k+i/2];
				x.a[k]=np+nt*nq,x.a[k]%=Pm[npp];
				x.a[k+i/2]=np-nt*nq%Pm[npp]+Pm[npp],x.a[k+i/2]%=Pm[npp];nt=nt*ni%Pm[npp];
			}
			
		}
	}
	if(nfl==-1)for(int i=0,ni=ksm1(len,Pm[npp]-2,Pm[npp]);i<len;i++)x.a[i]*=ni,x.a[i]%=Pm[npp];
}
void fft(poly&x,int xlen,poly y,int ylen,int np){
	int nn=nat(xlen+ylen);
	for(int i=xlen;i<=nn;i++)x.a[i]=0;for(int i=ylen;i<=nn;i++)y.a[i]=0;
	dft(x,nn,1,np),dft(y,nn,1,np);for(int i=0;i<nn;i++)x.a[i]*=y.a[i],x.a[i]%=Pm[np];
	dft(x,nn,-1,np);
}
void ant(poly&x,int xlen,poly y,int ylen){
	for(int i=1;i<=3;i++)ap[i]=x,fft(ap[i],xlen,y,ylen,i);
	int np=Pm[1]*Pm[2],i1=ksm1(Pm[2],Pm[1]-2,Pm[1]),i2=ksm1(Pm[1],Pm[2]-2,Pm[2]);
	int i4=ksm1(Pm[2],Pm[3]-2,Pm[3]),i3=ksm1(Pm[1],Pm[3]-2,Pm[3]);
	for(int i=0;i<xlen;i++){
		int na=ksa(ap[1].a[i],Pm[2]*i1,np)+ksa(ap[2].a[i],Pm[1]*i2,np);na%=np;
		int nb=(ap[3].a[i]-na%Pm[3]+Pm[3])%Pm[3]*i4%Pm[3]*i3%Pm[3];
		x.a[i]=(np%P*nb%P+na)%P;
	}
}
void ycl(){
	for(int i=2;i<=4*N;i++)logn[i]=logn[i/2]+1;
	jc[0]=njc[0]=pw2[0]=pw21[0]=1;
	for(int i=1;i<=N;i++)jc[i]=jc[i-1]*i%P,pw21[i]=pw21[i-1]*2%(P-1);
	njc[N]=qny(jc[N]);for(int i=N-1;i>=1;i--)njc[i]=njc[i+1]*(i+1)%P;
}
void calg(){
	p0.a[0]=jc[K];
	for(int i=1;i<=K;i++)g[0].a[i]=njc[i];
	for(int i=1;i<=15;i++){
		p1=g[i-1],g[i]=g[i-1];
		for(int j=0;j<=K;j++)p1.a[j]*=ksm(2,pw21[i-1]*j%(P-1)),p1.a[j]%=P;
		ant(g[i],K+1,p1,K+1);
	}
}
signed main(){
	ycl();
	cin>>n>>K;
	if(n>K){cout<<0<<endl;return 0;}
	calg();
	for(int i=15;i>=0;i--){
		if(n&(1<<i)){
			for(int j=0;j<=K;j++)p0.a[j]=p0.a[j]*ksm(2,pw21[i]*j%(P-1))%P;
			ant(p0,K+1,g[i],K+1);
		}
	}
	for(int i=0;i<=K;i++)ans+=p0.a[i]*njc[K-i],ans%=P;
	cout<<ans<<endl;
	return 0;
}
/*
30000 30000
16383 30000
*/