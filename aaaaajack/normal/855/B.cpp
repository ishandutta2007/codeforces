#include<bits/stdc++.h>
#define N 101000
using namespace std;
long long dp[3];
long long a[N];
int main(){
	int n,c[3];
	dp[0]=dp[1]=dp[2]=-(1LL<<62);
	scanf("%d%d%d%d",&n,&c[0],&c[1],&c[2]);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		for(int j=0;j<3;j++){
			dp[j]=max(dp[j],(j?dp[j-1]:0)+c[j]*a[i]);
		}
	}
	printf("%I64d\n",dp[2]);
	return 0;
}