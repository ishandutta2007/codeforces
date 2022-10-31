#include<bits/stdc++.h>
#define M 1010
#define Q 998244353 
using namespace std;
int dp[M][M],pre[M],a[M];
int main(){
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=i-1;
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++) dp[0][i]=1;
	for(int i=1;a[1]+i*(k-1)<=a[n];i++){
		for(int j=1;j<=n;j++){
			while(pre[j]>0 && a[j]-a[pre[j]]<i) pre[j]--;
		}
		for(int s=1;s<=k;s++){
			for(int j=1;j<=n;j++){
				dp[s][j]=(dp[s][j-1]+dp[s-1][pre[j]])%Q;
			}
		}
		ans=(ans+dp[k][n])%Q;
	}
	printf("%d\n",ans);
	return 0;
}