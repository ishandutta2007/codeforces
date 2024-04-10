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

using namespace std;

template <class T> struct maxWindow {
	deque<pair<int, T>> dq;
	void add(const int i, const T v) {
		while (!dq.empty() && dq.back().second <= v)
			dq.pop_back();
		dq.emplace_back(i, v);
	}
	void rem(const int i) {
		if (dq.front().first == i)
			dq.pop_front();
	}
	bool empty() const {
		return dq.empty();
	}
	const T &max() const {
		return dq.front().second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, W, B, X;
	cin >> N >> W >> B >> X;
	vector<int> c(N + 1), cost(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> c[i];
	for (int i = 1; i <= N; ++i)
		cin >> cost[i];

	vector<vector<long long>> dp(N + 1, vector<long long>(1e4 + 1, -1));

	dp[0][0] = W;
	for (int n = 1; n <= N; ++n) {
		maxWindow<long long> win;
		for (long long k = 0; k <= 1e4; ++k) {
			if (dp[n - 1][k] >= 0)
				win.add(k, min(dp[n - 1][k] + X, W + B * k) + k * cost[n]);
			win.rem(k - c[n] - 1);
			if (!win.empty())
				dp[n][k] = win.max() - k * cost[n];
		}
	}
	for(int k = 1e4;; --k)
		if (dp[N][k] >= 0) {
			cout << k;
			return 0;
		}
	return 0;
}