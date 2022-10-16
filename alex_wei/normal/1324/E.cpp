#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e3+5;
int n,h,l,r,dp[N][N],a[N];
int main(){
	cin>>n>>h>>l>>r;
	for(int i=1;i<=n;i++)cin>>a[i];
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int j=0;j<=i;j++){
			dp[i][j]=max(j?dp[i-1][j-1]:0,dp[i-1][j]);
			int t=(sum-j)%h;
			if(l<=t&&t<=r)dp[i][j]++;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
    return 0;
}