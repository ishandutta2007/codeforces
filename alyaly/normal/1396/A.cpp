#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100001];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		printf("1 1\n%lld\n1 1\n%lld\n1 1\n%lld\n",0ll,0ll,-a[1]);
		return 0;
	}
	printf("%lld %lld\n",1ll,n-1);
	for(int i=1;i<=n-1;i++)printf("%lld ",a[i]*(n-1));printf("\n");
	printf("%lld %lld\n",2ll,n);
	for(int i=2;i<=n-1;i++)printf("0 ");printf("%lld\n",a[n]*(n-1));
	printf("%lld %lld\n",1ll,n);
	for(int i=1;i<=n;i++)printf("%lld ",-a[i]*n);printf("\n");
	return 0;
}