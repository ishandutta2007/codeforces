#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,dp[200039][2],a[200039],t;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) dp[i][0]=dp[i][1]=1e9;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		dp[0][1]=1e9;dp[1][1]=a[1];
		for(i=2;i<=n;i++){
			dp[i][0]=min(dp[i-1][1],dp[i-2][1]);
			dp[i][1]=min(dp[i-1][0]+a[i],dp[i-2][0]+a[i]+a[i-1]);
		}
		printf("%d\n",min(dp[n][0],dp[n][1]));
	}
}