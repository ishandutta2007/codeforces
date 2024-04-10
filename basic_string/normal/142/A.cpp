#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,i,j,k,l;
	long long mi=1e18,ma=0,u,v,w;
	scanf("%d",&n);
	for(i=1;i*i*i<=n;++i){
		if(!(n%i)){
			k=n/i;
			for(j=i;j*j<=k;++j)if(!(k%j)){
				l=k/j,u=(i+1)*1ll*(j+2)*(l+2),v=(i+2)*1ll*(j+1)*(l+2),w=(i+2)*1ll*(j+2)*(l+1);
				mi=min(mi,min(u,min(v,w))),ma=max(ma,max(u,max(v,w)));
			}
		}
	}
	printf("%lld %lld",mi-n,ma-n);
	return 0;
}