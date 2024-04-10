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
#include <array>
#include <stack>

using namespace std;

int n;
int dp[100001] = { 0, 1 };

void f(int i, int j, int k) {
	if (i == j) {
		cout << i << ' ';
		return;
	}
	int mid = (i + j) / 2;
	if (--k <= 0) {
		f(i, mid, 0);
		f(mid + 1, j, 0);
	}
	else {
		int leftK = min(k - 1, dp[mid - i + 1]);
		f(mid + 1, j, k - leftK);
		f(i, mid, leftK);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> n >> k;
	for (int i = 2; i <= n; ++i) {
		int mid = (1 + i) / 2;
		dp[i] = 1 + dp[mid] + dp[i - mid];
	}
	if (k > dp[n] || !(k & 1)) {
		cout << -1;
		return 0;
	}
	f(1, n, k);
	return 0;
}