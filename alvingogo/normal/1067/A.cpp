#include <bits/stdc++.h>
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	const int mod=998244353;
	auto add=[&](int& x,int y){
		x+=y;
		x-=mod*(x>=mod);
	};
	auto mul=[&](int x,int y){
		return 1ll*x*y%mod;
	};
	int n;
	const int k=200;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
		v[i]--;
	}
	vector<array<int,2*k> > dp(n);
	if(v[0]<0){
		for(int i=0;i<k;i++){
			dp[0][i]=1;
		}
	}
	else{
		dp[0][v[0]]=1;
	}
	for(int i=1;i<n;i++){
		if(v[i]>=0){
			for(int j=v[i]+k;j<2*k;j++){
				add(dp[i][v[i]+k],dp[i-1][j]);
			}
			add(dp[i][v[i]+k],dp[i-1][v[i]]);
			for(int j=0;j<v[i];j++){
				add(dp[i][v[i]],dp[i-1][j]);
				add(dp[i][v[i]],dp[i-1][j+k]);
			}
		}
		else{
			int sum=0;
			for(int j=0;j<k;j++){
				add(dp[i][j],sum);
				add(sum,dp[i-1][j]);
				add(sum,dp[i-1][j+k]);
			}
			sum=0;
			for(int j=2*k-1;j>=k;j--){
				add(sum,dp[i-1][j]);
				add(dp[i][j],sum);
				add(dp[i][j],dp[i-1][j-k]);
			}
		}
	}
	int ans=0;
	for(int j=k;j<2*k;j++){
		add(ans,dp[n-1][j]);
	}
	cout << ans << "\n";
	return 0;
}