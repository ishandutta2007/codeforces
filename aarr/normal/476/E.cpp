#include <iostream>
using namespace std;

const int N = 2005, M = 505;

string s, p;
int dp[N];
int maxdp[N];
int dp2[N];
int main() {
	string s, p;
	cin >> s >> p;
	int n = s.size(), m = p.size();
	for (int i = 1; i <= n; i++) {
		dp2[i] = N;
		dp[i] = N;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			if (j % m != 0) {
				dp2[j]++;
			//	cout << i << " " << j << endl;
			}
			if (s[i - 1] == p[(j - 1) % m]) {
				/*if (j % m == 0) {
					dp2[j] = min(dp2[j] + 1, dp[j - 1]);
				}
				else {
					dp2[j] = min(dp2[j] + 1, dp2[j - 1]);
				}*/
				dp2[j] = min(dp2[j], dp2[j - 1]);
			}
			dp[j] = min(dp[j], dp2[j]);
		}
	}
	for (int i = 0; i <= n; i++) {
		int ans = 0;
		for (int j = m; j <= n; j += m) {
			if (dp[j] <= i && j <= n - i) {
				ans = j / m;
			}
		}
		cout << ans << " ";
	}
	return 0;
}