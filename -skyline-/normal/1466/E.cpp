#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int t,n;
ll a[500005],f[66];
int c[66];
int main(){
	scanf("%d",&t);
	for(int i=0;i<60;++i)f[i]=(1ll<<i)%orz;
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<60;++i)c[i]=0;
		for(int i=1;i<=n;++i){
			scanf("%I64d",a+i);
			for(int j=0;j<60;++j)if(a[i]&(1ll<<j))++c[j];
		}
		ll ans=0;
		for(int i=1;i<=n;++i){
			ll x=0,y=0;
			for(int j=0;j<60;++j){
				if(a[i]&(1ll<<j)){
					(x+=c[j]*f[j])%=orz;
					(y+=n*f[j])%=orz;
				}
				else{
					(y+=c[j]*f[j])%=orz;
				}
			}
			(ans+=x%orz*y)%=orz;
		}
		ans=(ans%orz+orz)%orz;
		printf("%I64d\n",ans);
	}
    return 0;
}