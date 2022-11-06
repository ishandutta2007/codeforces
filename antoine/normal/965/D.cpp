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
#include <memory>

using namespace std;
typedef long long ll;

ll w, l;
int a[(int)1e5];

bool f(int mid) {
	vector<int> dp(w, 0);
	dp[0] = mid;
	for (int i = 0, j = 1; i + l < w; ++i) {
		while (dp[i]) {
			while (j == i || dp[j] == a[j])
				if (++j - i > l)
					return false;
			ll count = min(dp[i], a[j] - dp[j]);
			dp[i] -= count;
			dp[j] += count;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> l;
	int lo = 0, hi = 1e9;
	for (int i = 1; i < w; ++i)
		cin >> a[i];

	while (lo < hi) {
		auto mid = (lo + hi + 1) >> 1;
		if (f(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	cout << lo;
	return 0;
}