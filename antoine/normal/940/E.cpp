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

typedef long long ll;

struct Window {
	deque<pair<ll, ll>> dq;
	void add(ll i, ll v) {
		while (!dq.empty() && dq.back().second >= v)
			dq.pop_back();
		dq.push_back({ i, v });
	}
	void rem(ll i) {
		if (!dq.empty() && dq.front().first == i)
			dq.pop_front();
	}
	ll min() {
		if (dq.empty())
			exit(1);
		return dq.front().second;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Window win;

	ll n, c;
	cin >> n >> c;
	vector<ll> a(n);
	vector<ll> pre(n, numeric_limits<ll>::max() / 20);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		win.add(i, a[i]);
		win.rem(i - c);
		if(i - c + 1 >= 0)
			pre[i - c + 1] = win.min();
	}
	vector <ll> cs = a;
	for (int i = 1; i < n; ++i)
		cs[i] += cs[i - 1];
	vector<ll> dp(n + c + c + 10, numeric_limits<ll>::max() / 20);
	dp[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = a[i] + dp[i + 1];
		if (i + c - 1 < n)
			dp[i] = min(dp[i], dp[i + c] + cs[i + c - 1] - (i ? cs[i - 1] : 0) - pre[i]);
	}
	cout << dp[0];
	return 0;
}