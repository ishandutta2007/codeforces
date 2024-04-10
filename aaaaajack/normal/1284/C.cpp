#include<bits/stdc++.h>
#define N 300100
using namespace std;
int fac[N];
int main(){
	int n,m;
	long long ans=0;
	scanf("%d%d",&n,&m);
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1LL*fac[i-1]*i%m;
	}
	for(int k=1;k<=n;k++){
		ans+=1LL*(n-k+1)*(n-k+1)%m*fac[k]%m*fac[n-k]%m;
	}
	printf("%lld\n",ans%m);
	return 0;
}