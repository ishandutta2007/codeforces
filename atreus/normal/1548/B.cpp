#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

ll dp[maxn][18], a[maxn];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
		a[i] = abs(a[i + 1] - a[i]);
	a[n] = 1;
	
	for (int i = n; i >= 1; i--) {
		dp[i][0] = a[i];
		for (int j = 1; j < 18 && i + (1 << j) - 1 <= n; j++)
			dp[i][j] = gcd(dp[i][j - 1], dp[i + (1 << (j-1))][j - 1]);
	}

	int answer = 1;
	for (int i = 1; i <= n; i++) { 
		ll x = 0;
		int idx = i;
		for (int j = 17; j >= 0; j--) {
			if (idx + (1 << j) <= n && gcd(x, dp[idx][j]) != 1) {
				x = gcd(x, dp[idx][j]);
				idx += (1 << j);
			}
		}
		answer = max(answer, idx - i + 1);
	}
	cout << answer << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}