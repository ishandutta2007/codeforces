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
	string s,t;
	cin >> s >> t;
	s='$'+s;
	t='#'+t;
	int n=s.length(),m=t.length();
	vector<int> nxt(n,-1);
	for(int i=1;i<n;i++){
		if(s[i]!='.'){
			int cnt=1;
			for(int j=i+1;j<n;j++){
				if(s[j]=='.'){
					cnt--;
				}
				else{
					cnt++;
				}
				if(cnt==0){
					nxt[i]=j;
					break;
				}
			}
		}
	}
	vector<vector<int> > dp(n+1,vector<int>(m+1,1e9));
	dp[0][0]=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			if(j+1<m && s[i+1]==t[j+1]){
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
			}
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
			if(nxt[i+1]>=0){
				dp[nxt[i+1]][j]=min(dp[nxt[i+1]][j],dp[i][j]);
			}
		}
	}
	cout << dp[n-1][m-1] << "\n";
	return 0;
}