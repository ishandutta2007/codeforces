#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5000 + 15;

int dp[MAXN];
int z[MAXN];

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
		dp[i] = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = max(dp[i], n - i);
		int l = i, r = i;
		for (int j = i + 1; j < n; j++) {
			z[j] = 0;
			if (j < r)
				z[j] = min(z[i + j - l], r - j);
			while (j + z[j] < n && s[i + z[j]] == s[j + z[j]])
				z[j]++;
			if (j + z[j] > r) {
				l = j;
				r = j + z[j];
			}

			int k = z[j];
			if (k < n and s[i + k] < s[j + k])
				dp[j] = max(dp[j], dp[i] + n - j - k);
		}
	}
	cout << *max_element(dp, dp + n) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}