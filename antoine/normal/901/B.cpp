#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <bitset>

using namespace std;

void p(int n, bitset<200> b) {
	cout << n << '\n';
	for (int i = 0; i <= n; ++i)
		cout << b[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	bitset<200> dp[2] = { 1, 0 };

	for (int i = 1; i <= n; ++i)
		dp[i & 1] = dp[(i & 1) ^ 1] << 1 ^ dp[i & 1];

	p(n, dp[n & 1]);
	p(n - 1, dp[n & 1 ^ 1]);
	return 0;
}