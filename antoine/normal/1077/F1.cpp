#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = 5009;
int a[MaxN + 9];
ll dp[2][MaxN + 9];

struct Window {
	deque<pair<int, ll>> dq;

	void push(const int i, const ll v) {
		while (!dq.empty() && dq.back().second <= v)
			dq.pop_back();
		dq.emplace_back(i, v);

	}

	ll mx() {
		return dq.front().second;
	}

	void pop(const int i) {
		if (!dq.empty() && dq.front().first == i)
			dq.pop_front();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, K, X;
	cin >> n >> K >> X;

	const ll Inf = (ll) 1e13;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[1][i] = (i < K?a[i]:-Inf);
	}


	for (int x = 2; x <= X; ++x) {
		Window win;
		for (int i = 1; i < n; ++i) {
			if (i > 0)
				win.push(i - 1, dp[~x & 1][i - 1]);
			win.pop(i - K - 1);
			dp[x & 1][i] = a[i] + win.mx();
		}
	}

	const ll res = *max_element(dp[X & 1] + n - K, dp[X & 1] + n);
	cout << (res < 0 ? -1 : res) << '\n';
	return 0;
}