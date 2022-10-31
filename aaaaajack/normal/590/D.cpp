#include<cstdio>
#include<cstring>
#define N 160
#define inf 1023456789
using namespace std;
int dp[N][N*N];
int main(){
	int n,k,s,ans=0,pk=0,a[N],m;
	scanf("%d%d%d",&n,&k,&s);
	if(n*(n-1)/2<s) s=n*(n-1)/2;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i<k) pk+=a[i];
	}
	if(k<n-k) m=k;
	else m=n-k;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=s;j++){
			dp[i][j]=inf;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<k;i++){
		for(int j=m-1;j>=0;j--){
			for(int l=s-(k-1-i);l>=0;l--){
				if(dp[j][l]==inf) continue;
				int &to=dp[j+1][l+(k-1-i)];
				if(dp[j][l]-a[i]<to) to=dp[j][l]-a[i];
			}
		}
	}
	for(int i=k;i<n;i++){
		for(int j=1;j<=m;j++){
			for(int l=s-(i-k+1);l>=0;l--){
				if(dp[j][l]==inf) continue;
				int &to=dp[j-1][l+(i-k+1)];
				if(dp[j][l]+a[i]<to) to=dp[j][l]+a[i];
			}
		}
	}
	for(int i=0;i<=s;i++){
		if(dp[0][i]<ans) ans=dp[0][i];
	}
	printf("%d\n",ans+pk);
	return 0;
}