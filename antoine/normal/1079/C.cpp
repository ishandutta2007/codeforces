#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool dp[(int) 1e5 + 9][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	fill(dp[n - 1] + 1, dp[n - 1] + 6, 1);

	for (int i = n - 2; i >= 0; --i) {
		for (int j = 1; j <= 5; ++j) {
			bool &res = dp[i][j];
			for (int k = 1; k <= 5; ++k)
				if (dp[i + 1][k]) {
					if (a[i] < a[i + 1] && j < k)
						res = true;
					if (a[i] > a[i + 1] && j > k)
						res = true;
					if (a[i] == a[i + 1] && j != k)
						res = true;
				}
		}
	}

	int j = 0;
	while (j <= 5 && !dp[0][j])
		++j;
	if (j > 5)
		cout << -1;
	else {
		for (int i = 0; i < n; ++i) {
			cout << j << ' ';
			assert(dp[i][j]);
			for (int k = 1; k <= 5; ++k)
				if (dp[i + 1][k]) {
					if (a[i] < a[i + 1] && j < k) {
						j = k;
						break;
					}
					if (a[i] > a[i + 1] && j > k) {
						j = k;
						break;
					}
					if (a[i] == a[i + 1] && j != k) {
						j = k;
						break;
					}
				}
		}
	}
	return 0;
}