# include <bits/stdc++.h>

using namespace std;

const int xn = 2.6e3+10;

int dp[xn][xn][5];
map <char, int> mp;

int main(){
	string a;
	cin >> a;
	int n = a.size();
	if (n >= 2600){
		for (int i=0; i<n; i++){
			mp[a[i]]++;
			if (mp[a[i]] == 100){
				for (int j=0; j<100; j++) cout << a[i];
				return 0;
			}
		}
	}
	for (int i=0; i<n; i++) dp[i][i][0] = 1, dp[i][i][1] = i;
	for (int i=0; i<n-1; i++)
		if (a[i] == a[i+1]) dp[i][i+1][0] = 2, dp[i][i+1][1] = i, dp[i][i+1][2] = -1, dp[i][i+1][3] = -1;
	for (int k=0; k<n; k++){
		for (int i=0; i<n-k; i++){
			int j = i+k;
			if (dp[i][j][0] == 0){
				if (a[i] == a[j]) dp[i][j][0] = dp[i+1][j-1][0]+2, dp[i][j][1] = i, dp[i][j][2] = i+1, dp[i][j][3] = j-1;
				else if (dp[i+1][j][0] >= dp[i][j-1][0]) dp[i][j][0] = dp[i+1][j][0], dp[i][j][1] = -1, dp[i][j][2] = i+1, dp[i][j][3] = j;
				else dp[i][j][0] = dp[i][j-1][0], dp[i][j][1] = -1, dp[i][j][2] = i, dp[i][j][3] = j-1;
			}
			
			if (dp[i][j][0] >= 100){
				int l = i, r = j;
				vector <char> ans;
				while (l < r){
					if (dp[l][r][1] != -1) ans.push_back(a[dp[l][r][1]]);
					int q = dp[l][r][2], w = dp[l][r][3];
					l = q, r = w;
				}
				if (l == r and l != -1) ans.push_back(a[l]);
				if (ans.size() == 51){
					for (int k=0; k<50; k++) cout << ans[k];
					for (int k=49; k>=0; k--) cout << ans[k];
				}
				else{
					for (int k=0; k<50; k++) cout << ans[k];
					for (int k=49; k>=0; k--) cout << ans[k];
				}
				return 0;
			}
		}
	}
	int l = 0, r = n-1;
	vector <char> ans;
	int fl1 = 0;
	while (l < r){
		if (dp[l][r][1] != -1) ans.push_back(a[dp[l][r][1]]);
		if (l+1 == r and a[l] == a[r]) ans.push_back(a[l]), fl1 = 1;
		int q = dp[l][r][2], w = dp[l][r][3];
		l = q, r = w;
	}
	if (l == r and l != -1) ans.push_back(a[l]);
	for (int k=0; k<ans.size(); k++) cout << ans[k];
	for (int k=ans.size()-2-fl1; k>=0; k--) cout << ans[k];
	return 0;
}