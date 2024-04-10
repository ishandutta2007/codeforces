#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
struct f{
	int a,b;//LIS,L shuangyin S.
}dp[2005];
int n,dp2[2005],a[2005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i].a = dp[i].b = 1;
		for(int j=1;j<i;j++){
			if(a[j] <= a[i]) dp[i].a = max(dp[i].a,dp[j].a + 1);
			if(a[j] < a[i]) dp[i].b = max(dp[i].b,dp[j].a + 1);
			else if(a[j] > a[i]) dp[i].b = max(dp[i].b,dp[j].b + 1);
			else dp[i].b = max(dp[i].b,max(dp[j].a + 1,dp[j].b + 1));
		}
	}
	for(int i=n;i>=1;i--){
		dp2[i] = 1;
		for(int j=n;j>i;j--){
			if(a[i] <= a[j]) dp2[i] = max(dp2[i],dp2[j] + 1);
		}
	}
	int ans = 1;
	for(int i=n;i>=1;i--){
		ans = max(ans,dp[i].b + dp2[i] - 1);
	}
	printf("%d\n",ans);
	return 0;
}