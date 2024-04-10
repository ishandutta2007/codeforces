#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int) 1e5 + 9;
int n;
string s;
ll a[MaxN + 9];
ll dp[MaxN + 9][6];
const string hard = "hard";

const ll Inf = (ll) 1e16;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = n; i >= 0; --i) {
		for (int j = 0; j <= 4; ++j) {
			ll &res = dp[i][j];
			if (j == 4)
				res = Inf;
			else if (i == n) {
				res = 0;
			} else {
				res = min(dp[i + 1][j] + a[i], dp[i + 1][j + (s[i] == hard[j])]);
			}
		}
	}
	cout << dp[0][0];
	return 0;
}