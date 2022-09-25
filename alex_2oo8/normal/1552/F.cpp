#include <bits/stdc++.h>

using namespace std;

const int MX = 200001, md = 998244353;

int x[MX], y[MX], s[MX], n;

int getReturn(int i);

int sumReturn(int i) {
	if (i == -1) return 0;
	
	static int dp[MX];
	
	if (dp[i] == 0) {
		dp[i] = (getReturn(i) + sumReturn(i - 1)) % md + 1;
	}
	
	return dp[i] - 1;
}

int getReturn(int i) {
	static int dp[MX];
	
	if (dp[i] == 0) {
		dp[i] = (x[i] - y[i] + sumReturn(i - 1)) % md;
		
		int j = -1;
		for (int p = (1 << 20); p > 0; p /= 2) {
			if (j + p < n && x[j + p] < y[i]) {
				j += p;
			}
		}
		
		dp[i] = (dp[i] + md - sumReturn(j)) % md + 1;
	}
	
	return dp[i] - 1;
}

int getAns(int i) {
	if (i == n) return 0;
	
	static int dp[MX];
	
	if (dp[i] == 0) {
		int here = (x[i + 1] - x[i] + getAns(i + 1)) % md;
		if (s[i] == 1) {
			here = (here + getReturn(i)) % md;
		}
		
		dp[i] = here + 1;
	}
	
	return dp[i] - 1;
}

int main() {
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d %d %d", x + i, y + i, s + i);
	
	x[n] = x[n - 1] + 1;
	
	printf("%d\n", (x[0] + getAns(0)) % md);
	
	return 0;
}