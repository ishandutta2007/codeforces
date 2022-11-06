#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mx = (int) 5e3;
int a[Mx + 9];
int pre[Mx + 9];
int dp[Mx + 3][Mx + 3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, K;
	cin >> n >> K;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && a[j] - a[i] <= 5)
			++j;
		pre[i] = j;
	}

	for (int i = n - 1; i >= 0; --i)
		for (int k = 1; k <= K; ++k)
			dp[i][k] = max(dp[i + 1][k], pre[i] - i + dp[pre[i]][k - 1]);
	cout << dp[0][K];
	return 0;
}