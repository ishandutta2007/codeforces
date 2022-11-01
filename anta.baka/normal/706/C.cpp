#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e16;
const int N = 1e5;
ll c[N], dp[N][2];
string s[N][2];

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		dp[i][0] = INF;
		dp[i][1] = INF;
	}
	for(int i = 0; i < n; i++) {
		cin >> s[i][0];
		s[i][1] = s[i][0];
		reverse(s[i][1].begin(), s[i][1].end());
	}
	dp[0][0] = 0;
	dp[0][1] = c[0];
	for(int i = 1; i < n; i++)
		for(int q = 0; q < 2; q++)
			for(int w = 0; w < 2; w++)
				if(s[i-1][w] <= s[i][q])
					dp[i][q] = min(dp[i][q], dp[i-1][w] + c[i] * q);
	long long ans = min(dp[n-1][0], dp[n-1][1]);
	if(ans == INF)
		cout << -1;
	else
		cout << ans;
	return 0;
}