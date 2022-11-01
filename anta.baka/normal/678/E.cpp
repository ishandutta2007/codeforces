#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<double>> p(n, vector<double>(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> p[i][j];
	int pw = 1<<n;
	vector<double> dp(pw, 0);
	dp[pw-2] = 1;
	for(int mask = pw-1; mask >= 0; mask--) {
		bitset<18> foo = mask;
		if(foo[0] == 1)
			continue;
		for(int i = 0; i < n; i++)
			if(foo[i] == 0)
				for(int j = i+1; j < n; j++)
					if(foo[j] == 0)
						dp[mask] = max(dp[mask], dp[mask+(1<<i)] * p[j][i] + dp[mask+(1<<j)] * p[i][j]);
	}
	cout << setprecision(6) << dp[0];
}