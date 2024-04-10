#include<bits/stdc++.h>
#define N 3010
using namespace std;
int dp[N][N]; //[current node][next hop > ]
int a[N],buf[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]+=i;
			for(int j=1;j<=n;j++){
				dp[i][j]=n;
			}
		}
		for(int j=1;j<=n;j++) dp[1][j]=0;
		for(int i=1;i<=n;i++){
			int cnt=0; //number of unchanged
			for(int j=i+1;j<=a[i];j++){
				dp[j][a[i]]=min(dp[j][a[i]],dp[i][j-1]+(j-i-1)-cnt);
				buf[min(a[j],a[i])]++;
				cnt+=buf[j];
				buf[j]=0;
				dp[i][j]=min(dp[i][j-1],dp[i][j]);
			}
			
		}
		printf("%d\n",dp[n][n]);
	}
	return 0;
}