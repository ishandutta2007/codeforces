#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		vector<vector<int> > dp(n,vector<int>(n,1e9));
		for(int i=0;i<n;i++){
			dp[0][i]=0;
		}
		for(int i=1;i<n;i++){
			int cnt=0;
			for(int j=i-1;j>=0;j--){
				if(j+v[j]>=i){
					dp[i][j+v[j]]=min(dp[i][j+v[j]],dp[j][i-1]+cnt);
					cnt++;
				}
			}
			for(int j=i+1;j<n;j++){
				dp[i][j]=min(dp[i][j],dp[i][j-1]);
			}
		}
		cout << dp[n-1][n-1] << "\n";
	}
    return 0;
}