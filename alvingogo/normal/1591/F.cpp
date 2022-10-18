#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	deque<int> dq;
	vector<pair<int,int> > dp(n);
	const int mod=998244353;
	dp[0]={v[0]%mod,1};
	
	dq.push_back(0);
	for(int i=1;i<n;i++){
		dp[i].fs=1ll*dp[i-1].fs*(v[i]-1)%mod;
		dp[i].sc=dp[i-1].fs;
		//int k=0;
		while(!dq.empty() && v[dq.back()]>v[i]){
			if((i-dq.back())%2){
				dp[i].fs+=1ll*dp[dq.back()].sc*(v[dq.back()]-v[i])%mod;
				dp[i].fs%=mod;
				dp[i].sc-=dp[dq.back()].sc;
				dp[i].sc+=mod;
				dp[i].sc%=mod;
			}
			else{
				dp[i].fs-=1ll*dp[dq.back()].sc*(v[dq.back()]-v[i])%mod;
				dp[i].fs+=mod;
				dp[i].fs%=mod;
				dp[i].sc+=dp[dq.back()].sc;
				dp[i].sc%=mod;
			}
			dq.pop_back();
		}
		dp[i].fs%=mod;
		dp[i].sc%=mod;
		dp[i].fs+=mod;
		dp[i].sc+=mod;
		dp[i].fs%=mod;
		dp[i].sc%=mod;
		//cout << dp[i].fs << " " << dp[i].sc << "\n";
		dq.push_back(i);
	}
	cout << dp[n-1].fs << "\n";
	return 0;
}