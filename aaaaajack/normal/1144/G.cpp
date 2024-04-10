#include<bits/stdc++.h>
#define N 200100
using namespace std;
int dp[N][2],fr[N][2];
int a[N],ans[N];
int main(){
	int n;
	const int inf=1e9+100;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	dp[0][0]=inf;
	dp[0][1]=-inf;
	for(int i=1;i<n;i++){
		dp[i][0]=-inf;
		dp[i][1]=inf;
		if(a[i-1]<a[i] && dp[i-1][0]>dp[i][0]){
			fr[i][0]=0;
			dp[i][0]=dp[i-1][0];
		}
		if(dp[i-1][1]<a[i] && a[i-1]>dp[i][0]){
			fr[i][0]=1;
			dp[i][0]=a[i-1];
		}
		if(a[i-1]>a[i] && dp[i-1][1]<dp[i][1]){
			fr[i][1]=1;
			dp[i][1]=dp[i-1][1];
		}
		if(dp[i-1][0]>a[i] && a[i-1]<dp[i][1]){
			fr[i][1]=0;
			dp[i][1]=a[i-1];
		}
	}
	if(dp[n-1][0]==-inf && dp[n-1][1]==inf) puts("NO");
	else{
		puts("YES");
		int st=dp[n-1][0]==-inf?1:0;
		for(int i=n-1;i>=0;i--){
			ans[i]=st;
			st=fr[i][st];
		}
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}