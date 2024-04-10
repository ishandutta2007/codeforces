#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> v(n+1),sum(n+1);
		for(int i=1;i<=n;i++){
			cin >> v[i];
			sum[i]=sum[i-1]+v[i];
		}
		int k=450;
		vector<vector<long long> > dp(n+2,vector<long long>(k));
		for(int j=0;j<k;j++){
			dp[n+1][j]=-1e9-7;
		}
		dp[n+1][0]=1e9+7;
		for(int i=n;i>0;i--){
			for(int j=0;j<k;j++){
				dp[i][j]=dp[i+1][j];
				if(j>0 && i+j-1<=n && sum[i+j-1]-sum[i-1]<dp[i+j][j-1]){
					dp[i][j]=max(dp[i][j],sum[i+j-1]-sum[i-1]);
				}
			}
		}
		int ans=0;
		for(int j=k-1;j>=0;j--){
			if(dp[1][j]>0){
				ans=j;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}