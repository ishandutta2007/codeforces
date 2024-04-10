#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=998244353;
void add(int& x,int y){
	x+=y;
	x-=mod*(x>=mod);
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
int main(){
    AquA;
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end(),greater<int>());
	vector<vector<int> > dp(n,vector<int>(n));
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(dp[i-1][j]){
				if(v[i]*2<=v[j]){
					dp[i][j]=mul(dp[i-1][j],i);
					add(dp[i][i],dp[i-1][j]);
				}
				else{
					dp[i][j]=mul(dp[i-1][j],i-1);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		add(ans,dp[n-1][i]);
	}
	cout << ans << "\n";
    return 0;
}