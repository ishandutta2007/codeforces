#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);cout.tie(0);

using namespace std;

int main(){
	fastio;
	int n,m;
	cin >> n >> m;
	vector<long long> dp(n+1);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=1;
	}
	dp[2]=2;
	for(int i=4;i<=n;i+=2){
		dp[i]++;
	}
	for(int i=3;i<=n;i++){
		dp[i]+=2*dp[i-1];
		dp[i]%=m;
		for(int j=i+i;j<=n;j+=i){
			dp[j]+=dp[i]-dp[i-1];
			if(dp[j]<0){
				dp[j]+=m;
			}
			dp[j]%=m;
		}
	}
	/*
	for(int i=0;i<n;i++){
		cout << dp[i] << " ";
	}
	*/
	cout << dp[n] << "\n";
	return 0;
}