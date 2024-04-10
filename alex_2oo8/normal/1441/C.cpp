#include <bits/stdc++.h>

using namespace std;

const int MX = 3000;

long long sum[MX], dp[MX + 1], ans;
vector<int> a[MX];
int k;

void solve(int l, int r) {
	if (l == r) {
		ans = max(dp[k], ans);
		
		long long here = 0;
		for (int x = 0; x < k && x < a[l].size(); x++) {
			here += a[l][x];
			ans = max(dp[k - x - 1] + here, ans);
		}
		
		return;
	}
	
	vector<long long> save(dp, dp + k + 1);
	
	int c = (l + r) / 2;
	
	for (int i = l; i <= c; i++) {
		int sz = a[i].size();
		
		for (int x = k; x - sz >= 0; x--) {
			dp[x] = max(dp[x], dp[x - sz] + sum[i]);
		}
	}
	
	solve(c + 1, r);
	
	for (int x = 0; x <= k; x++) dp[x] = save[x];
	
	for (int i = c + 1; i <= r; i++) {
		int sz = a[i].size();
		
		for (int x = k; x - sz >= 0; x--) {
			dp[x] = max(dp[x], dp[x - sz] + sum[i]);
		}
	}
	
	solve(l, c);
	
	for (int x = 0; x <= k; x++) dp[x] = save[x];
}

int main() {
	int n;
	ignore = scanf("%d %d", &n, &k);
	for (int i = 0, m; i < n; i++) {
		ignore = scanf("%d", &m);
		for (int j = 0, x; j < m; j++) {
			ignore = scanf("%d", &x);
			
			sum[i] += x;
			a[i].push_back(x);
		}
	}
	
	solve(0, n - 1);
	
	printf("%lld\n", ans);
	
	return 0;
}