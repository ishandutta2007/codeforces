#include<bits/stdc++.h>
#define N 5010
using namespace std;
long long dp[N][N];
int a[N],b[N],c[N],d[N],x[N];
int main(){
	int n,s,e,vs=0,ve=0;
	scanf("%d%d%d",&n,&s,&e);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	if(s==1) vs=1;
	if(e==1) ve=1;
	memset(dp,0x3f,sizeof(dp));
	long long inf=dp[0][0];
	if(vs) dp[1][1]=d[1];
	else if(ve) dp[1][1]=b[1];
	else dp[1][2]=b[1]+d[1];
	for(int i=2;i<=n;i++){
		for(int j=(2-(vs^ve));j<n;j+=2){
			if(dp[i-1][j]==inf) continue;
			dp[i-1][j]+=1LL*(x[i]-x[i-1])*j;
			if(i!=s&&i!=e){
				if(j>1) dp[i][j]=min(dp[i][j],dp[i-1][j]+min(a[i]+d[i],b[i]+c[i]));
				else if(vs) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i]+d[i]);
				else dp[i][j]=min(dp[i][j],dp[i-1][j]+b[i]+c[i]);
				dp[i][j+2]=min(dp[i][j+2],dp[i-1][j]+b[i]+d[i]);
				if(j>=2) dp[i][j-2]=min(dp[i][j-2],dp[i-1][j]+a[i]+c[i]);
			}
			else if(i==s){
				dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+d[i]);
				dp[i][j-1]=min(dp[i][j-1],dp[i-1][j]+c[i]);
			}
			else{
				dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+b[i]);
				dp[i][j-1]=min(dp[i][j-1],dp[i-1][j]+a[i]);
			}
		}
		if(i==s) vs=1;
		if(i==e) ve=1;
	}
	printf("%I64d\n",dp[n][0]);
	return 0;
}