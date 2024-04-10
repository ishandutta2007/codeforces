//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

const int N = 51'000;
int dp[N][3];
int t[N];

void solve() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
	}
	scanf("%d", &x);
	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = -1e9;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j] = -1e9;
		}
		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		dp[i][0] = max(dp[i][0], dp[i - 1][1]);
		dp[i][0] = max(dp[i][0], dp[i - 1][2]);
		dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
		if (i > 1 && t[i] + t[i - 1] >= x * 2) {
			dp[i][2] = max(dp[i][2], dp[i - 1][1] + 1);
			if (i > 2 && t[i] + t[i - 1] + t[i - 2] >= x * 3) {
				dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
			}
		}
	}
	printf("%d\n", max({dp[n][0], dp[n][1], dp[n][2]}));
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}