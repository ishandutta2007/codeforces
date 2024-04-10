#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll d[11],iv[N],ad[11][N],f[N];
int t,p;
ll qp(ll a,int b){
	ll r=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)r=r*a%p;
	return r;
}
ll c(int n,int m){
	if(m<0)return 0;
	ll r=f[n]*iv[m]%p*iv[n-m]%p;
	for(int i=1;i<=t;++i)r=r*qp(d[i],ad[i][n]-ad[i][m]-ad[i][n-m])%p;
	return r;
}
int main(){
	int n,l,r,i,j,x,ph;
	ll ans=0;
	scanf("%d%d%d%d",&n,&p,&l,&r),x=ph=p;
	for(i=2;i*i<=x;++i)if(!(x%i)){
		ph=ph/i*(i-1),d[++t]=i;
		do x/=i;while(!(x%i));
	}
	if(x>1)d[++t]=x,ph=ph/x*(x-1);
	f[0]=f[1]=iv[0]=iv[1]=1,--ph;
	for(i=2;i<=n;++i){
		for(x=i,j=1;j<=t;++j){
			ad[j][i]=ad[j][i-1];
			while(!(x%d[j]))x/=d[j],++ad[j][i];
		}
		f[i]=f[i-1]*x%p,iv[i]=qp(f[i],ph);
	}
	for(i=n-l;~i;--i)ans=(ans+(c(n-i,(n-i-l)>>1)-c(n-i,(n-i-r-1)>>1))*c(n,i))%p;
	printf("%d",(ans+p)%p);
	return 0;
}