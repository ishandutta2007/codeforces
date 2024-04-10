#include<bits/stdc++.h>
#define Q 1000000007
using namespace std;
int dp[80][1<<20],a[80];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
		int cur=-1;
		for(int j=i;j>0;j--){
			if(a[j]&&i-j>6) break;
			cur+=a[j]<<i-j;
			if(cur>=20) break;
			if(cur<0) continue;
			for(int k=0;k<(1<<20);k++){
				dp[i][k|1<<cur]+=dp[j-1][k];
				if(dp[i][k|1<<cur]>=Q) dp[i][k|1<<cur]-=Q;
			}
		}
		for(int j=1;j<(1<<20);j=j<<1|1){
			ans=(ans+dp[i][j])%Q;
		}
	}
	printf("%d\n",ans);
	return 0;
}