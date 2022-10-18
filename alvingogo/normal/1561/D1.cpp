#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);

using namespace std;

int main(){
	fastio;
	int n,mod;
	cin >> n >> mod;
	vector<long long> dp(n+1);
	dp[0]=1;
	dp[1]=1;
	int sum=1;
	for(int i=2;i<=n;i++){
		dp[i]+=sum;
		dp[i]%=mod;
		dp[i]+=i-i/2;
		dp[i]%=mod;
		for(int j=2;j*j<=i;j++){
			if(i/j!=j){
				dp[i]+=dp[i/j];
			}
			dp[i]%=mod;
			dp[i]+=(1ll*dp[j]*(i/j-i/(j+1)))%mod;
		}
		dp[i]%=mod;
		sum+=dp[i];
		sum%=mod;
	}
	cout << dp[n] << endl;
	return 0;
}