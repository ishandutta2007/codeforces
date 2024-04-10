#include<bits/stdc++.h>
#include<map>
//#define int long long
#define P 998244353
//#pragma GCC target("avx")
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
#define re register
using namespace std;
struct poly{
	int a[150001];
} b[103],c[103];
int n,K,nfl,nn[150001],pb,pc;
map<int,int> ma;
inline int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=1ll*(1ll*nans*10%P+c-'0')%P,c=getchar();return nans;}
inline int ksm(int x,int y){int nans=1;for(;y;y>>=1,x=1ll*x*x%P)if(y&1)nans=1ll*nans*x%P;return nans;}
inline int qny(int x){return ksm(x,P-2);}
inline int zgw(int x){for(re int i=30;i>=0;i--) if(x&(1<<i))return i;}
inline void dft(poly&x,int len,int nfl){
	for(re int i=1;i<=len;i++){
		nn[i]=nn[i/2]/2;
		if(i%2==1)nn[i]+=((len+1)>>1);
		if(nn[i]<i) swap(x.a[i],x.a[nn[i]]);
	}
	for(re int i=2;i<=len+1;i*=2){
		int nt=ksm(3,(P-1)/i);if(nfl) nt=qny(nt);
		for(re int j=0;j<=len;j+=i){
			int ng=1;
			for(int k=j;k<j+i/2;k++){
				int np=x.a[k],nq=x.a[k+i/2];
				x.a[k]=1ll*(np+1ll*nq*ng%P)%P;
				x.a[k+i/2]=1ll*(np-1ll*nq*ng%P+P)%P;
				ng=1ll*ng*nt%P;
			}
		}
	}
	if(nfl){int nt=qny(len+1);for(re int i=0;i<=len;i++) x.a[i]=1ll*x.a[i]*nt%P;
	}return;
}
inline void fft(poly&x,int lenx,poly y,int leny){
	int nl=(1<<(zgw(lenx+leny)+1))-1;
	for(re int i=lenx+1;i<=nl;i++) x.a[i]=0;for(re int i=leny+1;i<=nl;i++)y.a[i]=0;
	dft(x,nl,0);dft(y,nl,0);
	for(re int i=0;i<=nl;i++) x.a[i]=1ll*x.a[i]*y.a[i]%P;
	dft(x,nl,1);return;
}
void cal(int nx,int np){//cout<<nx<<" "<<np<<" "<<pc<<endl;
	if(nx==0){b[np].a[0]=1;ma.insert(make_pair(nx,np));return;}
	else if(nx==1){b[np].a[0]=b[np].a[1]=1;ma.insert(make_pair(nx,np));return;}
	int ng=(nx+1)/2,nh=ng-1;pc+=2;
	if(ma.find(ng)!=ma.end()) c[pc-1]=b[ma.find(ng)->second];
	else ++pb,cal(ng,pb),c[pc-1]=b[ma.find(ng)->second];
	if(ma.find(nh)!=ma.end()) c[pc]=b[ma.find(nh)->second];
	else ++pb,cal(nh,pb),c[pc]=b[ma.find(nh)->second];
	int nl=(1<<(zgw(2*K)+1))-1;
	for(int i=K+1;i<=nl;i++)c[pc-1].a[i]=c[pc].a[i]=0;
	dft(c[pc-1],nl,0),dft(c[pc],nl,0);
	if(nx%2==0){
		for(re int i=0;i<=nl;i++)c[pc-1].a[i]=1ll*c[pc-1].a[i]*c[pc-1].a[i]%P,c[pc].a[i]=1ll*c[pc].a[i]*c[pc].a[i]%P;
		dft(c[pc-1],nl,1),dft(c[pc],nl,1);
		for(re int i=1;i<=K;i++) b[np].a[i]=1ll*(c[pc-1].a[i]+c[pc].a[i-1])%P;b[np].a[0]=c[pc-1].a[0]%P;
	}else{
		for(re int i=0;i<=nl;i++)c[pc-1].a[i]=1ll*c[pc-1].a[i]*c[pc].a[i]%P,c[pc].a[i]=1ll*c[pc].a[i]*c[pc].a[i]%P;
		dft(c[pc-1],nl,1),dft(c[pc],nl,1);
		for(re int i=1;i<=K;i++) b[np].a[i]=1ll*(2ll*c[pc-1].a[i]%P-c[pc].a[i]-c[pc].a[i-1]+2*P)%P;b[np].a[0]=1ll*(2ll*c[pc-1].a[0]%P-c[pc].a[0]+P)%P;
	}
	ma.insert(make_pair(nx,np));pc-=2;return;
}
signed main(){
//	freopen("gg.in","r",stdin);
//	freopen("gg.out","w",stdout);
	cin>>n>>K;
	cal(n,0);
	for(re int i=1;i<=K;i++)cout<<b[0].a[i]<<' ';cout<<'\n';
	return 0;
}
/*
100 100

100000 100

1000000000 32767

1337 12345
*/