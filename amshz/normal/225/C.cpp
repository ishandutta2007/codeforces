# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
long long c1[xn], c2[xn], dp[2][xn];
string a[xn];

int main(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<m; i++){
		int t = 0;
		for (int j=0; j<n; j++) if (a[j][i] == '#') t++;
		c1[i] = n-t, c2[i] = t;
	}
	for (int i=0; i<m; i++) dp[0][i] =  1e18+10, dp[1][i] = 1e18+10;
	int s1 = 0, s2 = 0, s;
	for (int i=0; i<x; i++) s1 += c1[i], s2 += c2[i];
	dp[0][x-1] = s1, dp[1][x-1] = s2;
	for (int i=x; i<y; i++) s1 += c1[i], s2 += c2[i], dp[0][i] = s1, dp[1][i] = s2;
	for (int i=x; i<m; i++){
		s1 = 0;
		s2 = 0;
		for (int j=i; j>=i-y; j--){
			if (j < 0) break;
			if (j <= i-x) dp[0][i] = min(dp[0][i], dp[1][j]+s1), dp[1][i] = min(dp[1][i], dp[0][j]+s2);
			s1 += c1[j], s2 += c2[j];
		}
	}
	cout << min(dp[0][m-1],dp[1][m-1]);
}