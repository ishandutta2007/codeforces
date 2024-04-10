#include<bits/stdc++.h>
using namespace std;
int a[55],b[55],d[105],f[55],c[55],inv[55];
const int p=998244353;
long long qp(long long a,int b,int p){
	long long r=1;
	while(b){
		if(b&1)r=r*a%p;
		a=a*a%p,b>>=1;
	}
	return r;
}
int main(){
	int n,i,j,k,l,t,m=0;
	scanf("%d",&n),inv[1]=c[0]=f[0]=1;
	for(i=2;i<=n;++i)inv[i]=(p-p/i)*1ll*inv[p%i]%p;
	for(i=1;i<=n;++i)scanf("%d%d",a+i,b+i),d[++m]=a[i],d[++m]=b[i]+1;
	sort(d+1,d+m+1),m=unique(d+1,d+m+1)-d-1;
	for(i=1;i<=n;++i)a[i]=lower_bound(d+1,d+m+1,a[i])-d,b[i]=lower_bound(d+1,d+m+1,b[i]+1)-d;
	for(j=m-1;j;--j){
		for(i=1,l=d[j+1]-d[j];i<=n;++i)c[i]=c[i-1]*1ll*(l+i-1)%p*inv[i]%p;
		for(i=n;i;--i)if(a[i]<=j&&j<b[i])for(t=1,k=i-1;k>=0;--k,++t){
			f[i]=(f[i]+c[t]*1ll*f[k])%p;
			if(a[k]>j||j>=b[k])break;
		}
	}
	for(i=k=1;i<=n;++i)k=k*1ll*(d[b[i]]-d[a[i]])%p;
	printf("%d",f[n]*qp(k,p-2,p)%p);
	return 0;
}