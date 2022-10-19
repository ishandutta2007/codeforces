#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4];
int k,K;
int main(){
	for(int i=1;i<=3;i++)scanf("%lld",&a[i]);
	printf("First\n"),fflush(stdout);
	ll inf=1e10;
	printf("%lld\n",inf),fflush(stdout);
	scanf("%d",&k);
	a[k]+=inf;
	ll fni=(a[k]<<1);
	for(int i=1;i<=3;i++)if(k!=i)fni-=a[i];
	printf("%lld\n",fni),fflush(stdout);
	scanf("%d",&K);
	a[K]+=fni;
	printf("%lld\n",a[K]-a[k]),fflush(stdout);
	return 0;
}