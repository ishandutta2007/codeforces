#include<bits/stdc++.h>
int a[400100];
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long ans;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		a[0]=a[n+1]=0;
		ans=a[n];
		for(int i=1;i<=n;i++){
			ans+=abs(a[i]-a[i-1]);
			if(a[i]>max(a[i-1],a[i+1])) ans-=(a[i]-max(a[i-1],a[i+1]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}