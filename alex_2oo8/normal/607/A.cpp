#include<bits/stdc++.h>

using namespace std;

const int MX = 200000;

vector< pair<int, int> > v;
int dp[MX];

int main() {
	int n, ans = MX;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		v.push_back(make_pair(a, b));
	}
	
	sort(v.begin(), v.end());
	
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int j = 0;
		for (int k = (1 << 20); k > 0; k /= 2)
			if (j + k < i && v[j + k - 1].first < v[i - 1].first - v[i - 1].second)
				j += k;
		
		dp[i] = dp[j] + i - j - 1;
		
		ans = min(ans, dp[i] + n - i);
	}
	
	printf("%d\n", ans);
	
	return 0;
}