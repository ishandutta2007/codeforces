#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
int n,a[N],dp[N][N],ans[N][N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],dp[i][i]=a[i];
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1])dp[i][i+1]=a[i]+1,ans[i][i+1]=1;
		else dp[i][i+1]=0;
	}
	for(int len=3;len<=n;len++)for(int i=1;i+len-1<=n;i++){
		int j=i+len-1;
		for(int k=i;k<j;k++){
			ans[i][j]=max(ans[i][j],ans[i][k]+ans[k+1][j]);
			if(dp[i][k]&&dp[k+1][j]&&dp[i][k]==dp[k+1][j])
				dp[i][j]=dp[i][k]+1;
		}
		if(dp[i][j])ans[i][j]=len-1;
	}
	cout<<n-ans[1][n]<<endl;
	return 0;
}