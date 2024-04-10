#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmin(int a, int b){
	return (a < b) ? a : b;
}
int qmax(int a, int b){
	return (a > b) ? a : b;
}

int n;
string s[22];
int mn[22], cntmn[22], sum[22];
vector<int> cntnotmn[22];
int masksum[1048666];
int dp[1048666];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)
		cin >> s[i];
	rep(i, n){
		sum[i] = 0;
		mn[i] = 0, cntmn[i] = 0;
		rep(j, (int)s[i].size()){
			sum[i] += (s[i][j] == '(');
			sum[i] -= (s[i][j] == ')');
			if(sum[i] <= 0 && sum[i] <= mn[i]){
				while(-sum[i] >= (int)cntnotmn[i].size())
					cntnotmn[i].push_back(0);
				cntnotmn[i][-sum[i]]++;
			}
			if(sum[i] < mn[i])
				mn[i] = sum[i], cntmn[i] = 1;
			else if(sum[i] == mn[i])
				cntmn[i]++;
		}
	}
	rep(mask, 1 << n)
		rep(i, n)
			if(mask & (1 << i))
				masksum[mask] += sum[i];
	memset(dp, 0xc0, sizeof(dp));
	dp[0] = 0;
	int ans = 0;
	rep(mask, 1 << n){
//		cout << mask << ": " << dp[mask] << endl;
		if(dp[mask] < 0)
			continue;
		ans = qmax(ans, dp[mask]);
		rep(j, n)
			if(!(mask & (1 << j))){
				if(masksum[mask] < (int)cntnotmn[j].size()){
//					cout << masksum[mask] << " " << j << " : " << cntnotmn[j][masksum[mask]] << endl;
					ans = qmax(ans, dp[mask] + cntnotmn[j][masksum[mask]]);
				}
				if(masksum[mask] + mn[j] < 0)
					continue;
//				cout << (mask | (1 << j)) << ": " << dp[mask] << " " << ((masksum[mask] + mn[j] == 0) ? cntmn[j] : 0) << endl;
				dp[mask | (1 << j)] = qmax(dp[mask | (1 << j)], dp[mask] + ((masksum[mask] + mn[j] == 0) ? cntmn[j] : 0));
			}
	}
	cout << ans << endl;
	return 0;
}