#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,P=1e9+7;
int fc[N],ifc[N];
int qp(int a,int b=P-2){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
#define upd(x,y) ((x)=((x)+=(y))<P?(x):((x)-P))
#define C(x,y) (fc[x]*1ll*ifc[y]%P*ifc[(x)-(y)]%P)
int main(){
	int n,i,j=-1,k,u,v=1,ans=0,s=1;
	long long T,w=0,o;
	scanf("%d%lld",&n,&T),fc[0]=1,u=qp(2);
	for(i=1;i<=n;++i)fc[i]=fc[i-1]*1ll*i%P;
	ifc[n]=qp(fc[n]);
	for(i=n;i;--i)ifc[i-1]=ifc[i]*1ll*i%P;
	for(i=1;i<=n;v=v*1ll*u%P,ans=(ans+s*1ll*v)%P,++i){
		scanf("%lld",&o),w+=o;
		if(T-w>=i){
			upd(s,s);
			continue;
		}
		if(T<w)break;
		if(j==-1)j=i-1;
		s=(s*2ll-C(i-1,j)+P)%P,k=T-w;
		while(j!=k)upd(s,P-C(i,j)),--j;
	}
	printf("%d",ans);
	return 0;
}