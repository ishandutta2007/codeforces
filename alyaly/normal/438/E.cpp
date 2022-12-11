#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
#define P 998244353
using namespace std;
int n,m,v[100001],s[100001],rev[300001],p;
struct poly{
	int a[300001];
} p1,p2,p3,p4;
int ksm(int x,int y){int nans=1;for(;y;y>>=1,x=x*x%P)if(y&1)nans=nans*x%P;return nans;}
int qny(int x){return ksm(x,P-2);}
int zgw(int x){for(int i=30;i>=0;i--)if(x>>i)return i;}
void dft(poly&x,int len,int nfl){
	for(int i=0;i<=len;i++){
		rev[i]=rev[i>>1]>>1;
		if(i&1)rev[i]|=((len+1)>>1);
	}
	for(int i=0;i<=len;i++)if(i<rev[i])swap(x.a[i],x.a[rev[i]]);
	for(int i=2;i<=len+1;i*=2){
		int ni=ksm(3,(P-1)/i);if(nfl==-1)ni=qny(ni);
		for(int j=0;j<=len;j+=i){
			int nt=1;
			for(int k=j;k<j+i/2;k++){
				int np=x.a[k],nq=x.a[k+i/2];
				x.a[k]=(np+nq*nt)%P;
				x.a[k+i/2]=(np-nq*nt%P+P)%P;
				nt=nt*ni%P;
			}
		}
	}
	if(nfl==-1){
		int ni=qny(len+1);
		for(int i=0;i<=len;i++)x.a[i]=x.a[i]*ni%P;
	}
}
void fft(poly&x,int lenx,poly y,int leny){
	int nn=(1<<(zgw(lenx+leny)+1))-1;
	for(int i=lenx+1;i<=nn;i++)x.a[i]=0;
	for(int i=leny+1;i<=nn;i++)y.a[i]=0;
	dft(x,nn,1);dft(y,nn,1);
	for(int i=0;i<=nn;i++)x.a[i]=x.a[i]*y.a[i]%P;
	dft(x,nn,-1);
}
void inv(poly&x,int len){
	poly np=x,nq;
	memset(x.a,0,sizeof(x.a));
	x.a[0]=qny(np.a[0]);
	for(int i=2;i<2*len;i*=2){
		for(int j=0;j<i;j++)nq.a[j]=x.a[j];
		fft(nq,i-1,np,i-1);
		for(int j=0;j<i;j++)nq.a[j]=(-nq.a[j]+P)%P;nq.a[0]=(nq.a[0]+2)%P;
		fft(x,i-1,nq,i-1);
	}
}
void sqrt(poly&x,int len){
	poly np=x,nq,ny;
	memset(x.a,0,sizeof(x.a));
	memset(ny.a,0,sizeof(ny.a));
	x.a[0]=ny.a[0]=1;
	for(int i=2;i<2*len;i*=2){
//		for(int j=0;j<i;j++)nq.a[j]=ny.a[j];
//		fft(nq,i-1,x,i-1);
//		for(int j=0;j<i;j++)nq.a[j]=(-nq.a[j]+P)%P;nq.a[0]=(nq.a[0]+2)%P;
//		fft(ny,i-1,nq,i-1);
		int ny2=qny(2);ny=x;inv(ny,i-1);
		nq=np;fft(nq,i-1,ny,i-1);
		for(int j=0;j<i;j++)x.a[j]=(x.a[j]+nq.a[j])%P*ny2%P;
		
	}
}
void bl(){
	s[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<=i-v[j];k++){
				s[i]+=s[k]*s[i-v[j]-k]%P;
				s[i]%=P;
			}
		}
		printf("%d\n",s[i]);
	}
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p;
		p2.a[p]++;
	}
	p3.a[0]=1;
	for(int i=2;i<=m*2;i*=2){
		p1=p3;fft(p1,i-1,p2,i-1);p4=p1;
		fft(p1,i-1,p3,i-1);
		for(int j=0;j<i;j++)p4.a[j]=(p4.a[j]*2)%P,p1.a[j]=(p1.a[j]-p3.a[j]+P)%P;
		p4.a[0]=(p4.a[0]-1+P)%P;inv(p4,i-1);p1.a[0]=(p1.a[0]+1)%P;
		fft(p1,i-1,p4,i-1);
		for(int j=0;j<i;j++)p3.a[j]=(p3.a[j]-p1.a[j]+P)%P;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",p3.a[i]);
	return 0;
}