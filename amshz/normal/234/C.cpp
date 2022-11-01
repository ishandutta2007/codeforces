# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+9;
int a[xn], dp[xn], n;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int mn;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	if (a[0] >= 0) dp[0] += 1;
	for (int i=1; i<n; i++) 
		if (a[i] <= 0) dp[0] += 1;
	for (int i=1; i<n-1; i++){
		if (a[i] == 0) dp[i] = dp[i-1];
		else if (a[i] > 0) dp[i] = dp[i-1]+1;
		else dp[i] = dp[i-1]-1;
	}
	mn = dp[0];
	for (int i=1; i<n-1; i++) if (dp[i] < mn) mn = dp[i];
	cout << mn;
}