#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Mx = (int) 1e5 + 9;
ll o[Mx + 9];
ll dp[Mx + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		++o[x];
	}

	dp[1] = o[1];

	for (int i = 2; i <= Mx; ++i)
		dp[i] = max(dp[i - 1], i * o[i] + dp[i - 2]);
	cout << dp[Mx];
	return 0;
}