# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
const int xk = 5e1+10;

int dp[xn][xk][2];

int main(){
	int n;
	string a;
	cin >> a >> n;
	for (int i=0; i<a.size(); i++)
		for (int j=0; j<=n; j++) dp[i][j][0] = -1e9-10, dp[i][j][1] = -1e9-10;
	if (a[0] == 'F') dp[0][0][0] = 1, dp[0][1][1] = 0;
	else dp[0][0][1] = 0, dp[0][1][0] = 1;
	for (int i=1; i<a.size(); i++){
		for (int j=0; j<=n; j++){
			if (a[i] == 'T'){
				dp[i][j][0] = dp[i-1][j][1];
				dp[i][j][1] = dp[i-1][j][0];
				if (j > 0) dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][0]+1);
				if (j > 0) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][1]-1);
			}
			else{
				dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]+1);
				dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1]-1);
				if (j > 0) dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][1]);
				if (j > 0) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0]);
			}
		}
	}
	int mx = 0;
	for (int j=n%2; j<=n; j += 2){
		if (dp[a.size()-1][j][0] < -1e5) dp[a.size()-1][j][0] = 0;
		if (dp[a.size()-1][j][1] < -1e5) dp[a.size()-1][j][1] = 0;
		mx = max(mx, max(int(sqrt(pow(dp[a.size()-1][j][0],2))), int(sqrt(pow(dp[a.size()-1][j][1],2)))));
	}
	
	
	for (int i=0; i<a.size(); i++)
		for (int j=0; j<=n; j++) dp[i][j][0] = 1e9+10, dp[i][j][1] = 1e9+10;
	if (a[0] == 'F') dp[0][0][0] = 1, dp[0][1][1] = 0;
	else dp[0][0][1] = 0, dp[0][1][0] = 1;
	for (int i=1; i<a.size(); i++){
		for (int j=0; j<=n; j++){
			if (a[i] == 'T'){
				dp[i][j][0] = dp[i-1][j][1];
				dp[i][j][1] = dp[i-1][j][0];
				if (j > 0) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][0]+1);
				if (j > 0) dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-1][1]-1);
			}
			else{
				dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0]+1);
				dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1]-1);
				if (j > 0) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][1]);
				if (j > 0) dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-1][0]);
			}
		}
	}
	for (int j=n%2; j<=n; j += 2){
		if (dp[a.size()-1][j][0] > 1e5) dp[a.size()-1][j][0] = 0;
		if (dp[a.size()-1][j][1] > 1e5) dp[a.size()-1][j][1] = 0;
		mx = max(mx, max(int(sqrt(pow(dp[a.size()-1][j][0],2))), int(sqrt(pow(dp[a.size()-1][j][1],2)))));
	}
	
	cout << mx << endl;
}