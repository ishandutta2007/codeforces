#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,K,a[201],h[201],ans;
signed main(){
	cin>>T;
	while(T--){
		memset(h,0,sizeof(h));
		cin>>n>>K;
		for(int i=1;i<=n;i++) cin>>a[i],h[a[i]]=1;
		for(int i=1,j=1;i<=200&&j<=K;i++){
			if(!h[i]){
				h[i]=1;
				j++;
			}
		}
		for(ans=1;h[ans];ans++);
		ans--;
		printf("%lld\n",ans);
	}
	return 0;
}