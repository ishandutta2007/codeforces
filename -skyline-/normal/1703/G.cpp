#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,n,k,a[100005];
ll dp[100005][35];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		for(int i=0;i<=n;++i){
			for(int j=0;j<=32;++j)dp[i][j]=-orz*1ll*orz;
		}
		dp[0][0]=0;
		for(int i=1;i<=n;++i){
			dp[i][0]=dp[i-1][0]-k+a[i];
			for(int j=1;j<=31;++j)dp[i][j]=max(dp[i-1][j-1]+(a[i]>>j),dp[i-1][j]+(a[i]>>j)-k);
			dp[i][31]=max(dp[i][31],dp[i-1][31]);
		}
		ll ans=0;
		for(int i=0;i<=31;++i)ans=max(ans,dp[n][i]);
		printf("%I64d\n",ans);
	}
    return 0;
}