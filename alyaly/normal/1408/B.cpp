#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,K,a[100001],ans;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;
		for(int i=1;i<=n;i++)cin>>a[i];
		n=unique(a+1,a+n+1)-a-1;
		if(K==0||(K==1&&n!=1)){
			printf("-1\n");continue;
		}
		if(n<=K){
			printf("1\n");continue;
		}
		printf("%lld\n",(int)ceil((n-K)*1.0/(K-1))+1);
	}
	return 0;
}