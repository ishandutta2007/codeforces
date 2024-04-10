#include <bits/stdc++.h>

using namespace std;

const int N = 520;
const int K = 12;
const int C = 100 * 1000 + 11;

int n, k;
int c[C];
int f[C];
vector<int> h;

int dp[N][K * N];

int main() {
	cin >> n >> k;
	h = vector<int>(k + 1);
	for (int i = 0; i < n * k; ++i) {
		int x;
		cin >> x;
		++c[x];
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++f[x];
	}
	for (int i = 1; i <= k; ++i)
		cin >> h[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n * k; ++j) {
			for (int cur = 0; cur <= k; ++cur) {
				dp[i + 1][j + cur] = max(dp[i + 1][j + cur], dp[i][j] + h[cur]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < C; ++i) {
		if (f[i] != 0) ans += dp[f[i]][c[i]];
	}
	cout << ans << endl;
	return 0;
}