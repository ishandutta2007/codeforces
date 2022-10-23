#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n;
ll a[200005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll s=0;
		for(int i=1;i<=n;++i)scanf("%I64d",a+i),s+=a[i];
		sort(a+1,a+n+1);
		if(a[1]*(n-2ll)+s>0||a[n]*(n-2ll)+s<0){
			puts("INF");
			continue;
		}
		ll P=0,S=0,ans=-orz*1ll*orz;
		for(int i=2;i<=n;++i)P+=a[1]*a[i],S+=(a[1]+a[i]);
		for(int i=1;i<n;++i){
			if(i>1){
				P-=a[i]*a[1];
				S-=(a[i]+a[1]);
				P+=a[i]*a[n];
				S+=(a[i]+a[n]);
			}
			ll L=-a[i+1],R=-a[i];
			ans=max(ans,P+L*S);
			ans=max(ans,P+R*S);
		}
		printf("%I64d\n",ans);
	}
    return 0;
}