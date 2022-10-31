#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
int a[5010],s[5010],cnt[5010],l[5010],c[5010];
vector<int> dp[5010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=m+n;i++){
		scanf("%d",&l[i]);
		cnt[i]+=cnt[i-1]/2;
		dp[i].resize(cnt[i]+1);
		fill(all(dp[i]),-(1<<30));
		dp[i][0]=0;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=dp[a[i]].size()-1;j>0;j--){
			dp[a[i]][j]=max(dp[a[i]][j],dp[a[i]][j-1]-c[i]+l[a[i]]);
		}
		for(int j=a[i];j<m+n;j++){
			for(int k=0;k<dp[j].size();k++){
				dp[j+1][k/2]=max(dp[j+1][k/2],dp[j][k]+(k/2)*l[j+1]);
			}
		}
	}
	printf("%d\n",dp[m+n][0]);
	return 0;
}