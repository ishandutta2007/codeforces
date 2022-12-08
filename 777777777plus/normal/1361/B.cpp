#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
const ll mod = 1e9+7;

int T;
int n,p,a[N];

ll qpow(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		b>>=1;a=a*a%mod;
	}
	return r;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		if(p==1){
			if(n&1)printf("1\n");
			else printf("0\n");
			continue;
		}
		sort(a+1,a+n+1);
		ll div_virt=0;
		ll ans=0;
		for(int i=n;i>=1;--i){
			if(div_virt>=0){
				div_virt--;
				ans=(ans+qpow(p,a[i]))%mod;
			}
			else{
				div_virt++;
				ans=(ans-qpow(p,a[i])+mod)%mod;
			}
			if(i!=1&&div_virt!=0){
				for(int j=a[i];j>a[i-1];--j){
					div_virt*=p;
					if(div_virt>n){
						div_virt=n;
						break;
					}
					if(div_virt<-n){
						div_virt=-n;
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
}
/*
*/