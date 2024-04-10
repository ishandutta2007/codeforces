#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int T,n,m,i,j,k,u,v;
	ll p,pp,q,w,o;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&p,&q);
		if(p%q==0){
			w=2e18,pp=p;
			for(i=2;i*i<=q;++i)if(q%i==0){
				u=v=0;
				while(p%i==0)p/=i,++u;
				while(q%i==0)q/=i,++v;
				k=u-v+1,o=1;
				for(j=1;j<=k;++j)o*=i;
				w=min(w,o);
			}
			if(q>1){
				u=v=0,i=q;
				while(p%i==0)p/=i,++u;
				while(q%i==0)q/=i,++v;
				k=u-v+1,o=1;
				for(j=1;j<=k;++j)o*=i;
				w=min(w,o);
			}
			printf("%lld\n",pp/w);
		}
		else printf("%lld\n",p);
	}
	return 0;
}